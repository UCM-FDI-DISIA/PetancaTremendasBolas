#include "GameManager.h"
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Transform.h>
#include <RigidBody.h>
#include "ShootComponent.h"
#include <ProgressBar.h>
#include <Text.h>
#include "UIManager.h"
#include <TimeForge.h>
#include <Mesh.h>

//#include <Serializer.h>
const std::string GameManager::id = "GameManager";

GameManager::GameManager(): firstTurn(false),init(false), isP1(false), turnStarted(false),
cinematicCamera(false), end(false), myBallCounterP1(0),myBallCounterP2(0),maxBalls(3),points1(0),points2(0), pointRadius(1000), speed(0),
winnerTime(5), initialCamPos(0, 0, 0), playing(false), waitForRefresh(false), endUI(false) {
	boliche = nullptr;
	cam = nullptr;
	currentBall = nullptr;
	manager = nullptr;
	maxForce = 0;
}

GameManager::~GameManager() {
}

bool GameManager::initComponent(ComponentData* data) {
	ballsP1 = std::vector<Entity*>(0);
	ballsP2 = std::vector<Entity*>(0);
	
	return true;
}

void GameManager::initVariables() {
	if (waitForRefresh) {
		waitForRefresh = false;
	}
	else {
		init = false;
		boliche = sceneManager.instantiateBlueprint("boliche");
		currentBall = boliche->getComponent<ShootComponent>();
		maxForce = currentBall->getMaxForce();
		cam = sceneManager.getActiveScene()->getEntityByHandler("cam")->getComponent<Transform>();
		initialCamPos = cam->getPosition();
		manager = sceneManager.getActiveScene()->getEntityByHandler("UIManager")->getComponent<UIManager>();
		sceneManager.getActiveScene()->getEntityByHandler("Turn")->getComponent<Text>()->setText("No Juan");
		firstTurn = true;
	}
}

void GameManager::update() {
	if (playing) {
		mainLoop();
	}
	else if (isSelectionScene) {
	
	}
	else {
	}
}

void GameManager::mainLoop() {
	if (!end) {
		/// CAMERA CINEMATICA QUE SIGUE A LA BOLA
		if (cinematicCamera) {
			cinematicCameraPhase();
		}
		else if (!turnStarted && !cinematicCamera && !init && !end) {
			if (firstTurn) {
				turnStarted = boliche->getComponent<ShootComponent>()->hasShot();

				//ACTUALIZACION DE LA BARRA
				manager->updateProgressBar(currentBall->getForce(), maxForce);
				if (turnStarted) {
					speed = 100;
					cinematicCamera = turnStarted;

				}
			}
			if (isP1 && !firstTurn) {
				//Crear bola de petanca jugador 1 y activar su shoot component
				//ACTUALIZACION DEL TURNO
				manager->updateTurn(isP1);

				createBall(isP1);
				myBallCounterP1++;
				turnStarted = true;
			}
			else if (!firstTurn) {
				//Lo mismo pero con P2
				//ACTUALIZACION DEL TURNO
				manager->updateTurn(isP1);

				createBall(isP1 && !firstTurn);
				myBallCounterP2++;
				turnStarted = true;
			}
		}
		//Si el turno ha empezado y no estamos en camara cinematica
		if (turnStarted && !cinematicCamera) {
			if (isP1) {
				cinematicCamera = currentBall->hasShot();

				//ACTUALIZACION DE LA BARRA
				manager->updateProgressBar(currentBall->getForce(), maxForce);

				speed = 100;
			}
			else {
				cinematicCamera = currentBall->hasShot();

				//ACTUALIZACION DE LA BARRA
				manager->updateProgressBar(currentBall->getForce(), maxForce);

				speed = 100;
			}
		}

		if (init) {
			initVariables();
		}
	}
	else {
		endGamePhase();
	}
}

void GameManager::cinematicCameraPhase()
{
	//Si la velocidad de la bola es menor a 0.1, se desactiva la camara cinematica
	if (speed < 0.01) {
		cinematicCamera = false;
		turnStarted = false;
		if (!firstTurn) {
			//Camara vuelve a posicion inicial
			if (isP1) {
				//Sumamos el contador de bolas y calculamos los puntos y pasamos al siguiente turno
				calculatePoints(isP1);
				calculatePoints(!isP1);
				cam->setPosition(initialCamPos);
				cam->lookAt(ballsP1[myBallCounterP1 - 1]->getComponent<Transform>()->getPosition());
				isP1 = false;
				end = (myBallCounterP1 == myBallCounterP2 && myBallCounterP1 == maxBalls);
			}
			//Mismo proceso pero con P2
			else {
				calculatePoints(isP1);
				calculatePoints(!isP1);
				cam->setPosition(initialCamPos);
				cam->lookAt(ballsP2[myBallCounterP2 - 1]->getComponent<Transform>()->getPosition());
				isP1 = true;
				end = (myBallCounterP1 == myBallCounterP2 && myBallCounterP1 == maxBalls);
			}
		}
		else {
			firstTurn = false;
			isP1 = true;
		}
	}
	// La camara sigue la bola hasta que baje de cierta velocidad
   // Y vuelve a la posicion inicial
	if (isP1 && !ballsP1.empty()) {
		// Camara sigue la bola
		cam->lookAt(ballsP1[myBallCounterP1 - 1]->getComponent<Transform>()->getPosition());
		speed = ballsP1[myBallCounterP1 - 1]->getComponent<RigidBody>()->getSpeed();
	}
	else if (!firstTurn && !isP1 && !ballsP2.empty()) {
		cam->lookAt(ballsP2[myBallCounterP2 - 1]->getComponent<Transform>()->getPosition());
		speed = ballsP2[myBallCounterP2 - 1]->getComponent<RigidBody>()->getSpeed();
	}
	else {
		cam->lookAt(boliche->getComponent<Transform>()->getPosition());
		speed = boliche->getComponent<RigidBody>()->getSpeed();
	}
}

int GameManager::calculatePoints(bool player1)
{
	if (player1) {
		points1 = 0;
		int aux;
		for (auto ball : ballsP1)
		{
			aux = (int)(500 * ((float)(pointRadius - (boliche->getComponent<Transform>()->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude()) / pointRadius));
			if (aux < 0.0f) {
				aux = 0;
			}
			points1 += aux;
		}
		
		manager->updatePoints(points1, player1);
	}
	else {
		points2 = 0;
		int aux;
		for (auto ball : ballsP2)
		{
			aux = (int)(500 * ((float)(pointRadius - (boliche->getComponent<Transform>()->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude()) / pointRadius));
			if (aux < 0.0f) {
				aux = 0;
			}
			points2 += aux;
		}
		manager->updatePoints(points2, player1);

	}
	return 0;
}

void GameManager::createBall(bool player1)
{
	//Crea la bola para el jugador uno si es su turno
	if (player1) {
		ballsP1.push_back(sceneManager.instantiateBlueprint("ball"));
		currentBall = ballsP1[myBallCounterP1]->getComponent<ShootComponent>();
		currentBall->getEntity()->getComponent<Mesh>()->setMaterial(player1Skin);
		maxForce = currentBall->getMaxForce();
	}
	//Crea la bola para el jugador dos si es su turno
	else {
		ballsP2.push_back(sceneManager.instantiateBlueprint("ball"));
		currentBall = ballsP2[myBallCounterP2]->getComponent<ShootComponent>();
		currentBall->getEntity()->getComponent<Mesh>()->setMaterial(player2Skin);
		maxForce = currentBall->getMaxForce();

	}
}

void GameManager::changeScene(std::string const& scene) {
	sceneManager.changeScene(scene);
	if(scene != "TitleScreen" && scene!= "SkinSelection")setPlaying(true);
}

void GameManager::setMap(std::string map)
{
	if (map == "escorial.png")
	{
		mapSelected = "Escorial";
	}
	if (map == "valencia.png")
	{
		mapSelected = "Valencia";
	}
	if (map == "murcia.png")
	{
		mapSelected = "Test";
	}
	changeScene(mapSelected);
}

void GameManager::setSkins(std::string skinP1, std::string skinP2)
{
	player1Skin = skinP1;
	player2Skin = skinP2;
}
void GameManager::endGamePhase() {
	if (!endUI) {
		sceneManager.getActiveScene()->getEntityByHandler("Turn")->getComponent<Text>()->setText("");
		sceneManager.instantiateBlueprint("WinnerText")->getComponent<Text>()->setText((points1 > points2) ? "Ganador : Jugador 1" : "Ganador : Jugador 2");
		endUI = true;
	}
	if (winnerTime > 0) {
		winnerTime -= static_cast<float>(forge::Time::deltaTime);
	}
	else {
		winnerTime = 5;

		changeScene("TitleScreen");
	}
}

void GameManager::setPlaying(bool play) {
	playing = play;
	waitForRefresh = play;
	init = play;
	firstTurn=false;
	endUI = false;
	isP1=false;
	turnStarted=false;
	cinematicCamera = false;
	end = false;

	myBallCounterP1=0;
	myBallCounterP2=0;
	maxBalls=3;
	points1=0;
	points2=0;
	speed = 0;
	winnerTime = 5;

	initialCamPos = forge::Vector3(0, 0, 0);

	ballsP1.clear();
	ballsP2.clear();
}
