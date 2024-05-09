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
//#include <Serializer.h>
const std::string GameManager::id = "GameManager";

GameManager::GameManager(): firstTurn(false),init(true), isP1(false), turnStarted(false),
cinematicCamera(false), myBallCounterP1(0),myBallCounterP2(0),maxBalls(3),points1(0),points2(0), pointRadius(100), speed(0)
, initialCamPos(0,0,0){
	boliche = nullptr;
	cam = nullptr;
	currentBall = nullptr;
	manager = nullptr;
	maxForce = 0;
}

GameManager::~GameManager() {
}

bool GameManager::initComponent(ComponentData* data) {
	ballsP1 = std::vector<Entity*>();
	ballsP2 = std::vector<Entity*>();
	
	return true;
}

void GameManager::update() {
	if (isSelectionScene)
	{
		return;
	}

	// Bucle para calcular los puntos de la partida
	// Falta control de escena de pausasds

	/// CAMERA CINEMATICA QUE SIGUE A LA BOLA
	if (cinematicCamera) {
		
		 //Si la velocidad de la bola es menor a 0.1, se desactiva la camara cinematica
		 if(speed < 5) { 
			 cinematicCamera = false;
			 turnStarted=false;

			 ///SI NO ES EL PRIMER TURNO
			 if (!firstTurn) {
				 //Camara vuelve a posicion inicial
				 ///SI SE ACABA EL TURNO DEL JUGADOR 1
				 if (isP1) {
					 //Sumamos el contador de bolas y calculamos los puntos y pasamos al siguiente turno
					 calculatePoints(isP1);
					 cam->setPosition(initialCamPos);
					 cam->lookAt(ballsP1[myBallCounterP1-1]->getComponent<Transform>()->getPosition());
					 isP1 = false;
				 }
				 //Mismo proceso pero con P2
				 ///SI SE ACABA DEL TURNO DEL JUGADOR 2
				 else {
					 calculatePoints(isP1);
					 cam->setPosition(initialCamPos);
					 cam->lookAt(ballsP2[myBallCounterP2-1]->getComponent<Transform>()->getPosition());
					 isP1 = true;
				 }
			 }
			 ///SI ES EL PRIMER TURNO Y ACABA EMPIEZA EL JUEGO
			 else {
				 firstTurn = false;
				 isP1 = true;
			 }
		 }
		 // La camara sigue la bola hasta que baje de cierta velocidad
		// Y vuelve a la posicion inicial
		 if (isP1 && !ballsP1.empty()) {
			 // Camara sigue la bola
 			 cam->lookAt(ballsP1[myBallCounterP1-1]->getComponent<Transform>()->getPosition());
			 speed = ballsP1[myBallCounterP1-1]->getComponent<RigidBody>()->getSpeed();
		 }
		 else if (!firstTurn && !isP1 && !ballsP2.empty()) {
			 cam->lookAt(ballsP2[myBallCounterP2-1]->getComponent<Transform>()->getPosition());
			 speed = ballsP2[myBallCounterP2-1]->getComponent<RigidBody>()->getSpeed();
		 }
		 else {
			 cam->lookAt(boliche->getComponent<Transform>()->getPosition());
			 speed = boliche->getComponent<RigidBody>()->getSpeed();
		 }
	}
	else if (!turnStarted && !cinematicCamera && !init) {
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
		else if(!firstTurn) {
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
		init = false;
		boliche = sceneManager.instantiateBlueprint("boliche");
		currentBall = boliche->getComponent<ShootComponent>();
		maxForce = currentBall->getMaxForce();
		cam = sceneManager.getActiveScene()->getEntityByHandler("cam")->getComponent<Transform>();
		initialCamPos = cam->getPosition();
		manager = sceneManager.getActiveScene()->getEntityByHandler("UIManager")->getComponent<UIManager>();
		firstTurn = true;
	}
}

int GameManager::calculatePoints(bool player1)
{
	if (player1) {
		points1 = 0;
		for (auto ball : ballsP1)
		{
			points1 += (int)(500 * ((float)(pointRadius - (boliche->getComponent<Transform>()->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude()) / pointRadius));
		}
		manager->updatePoints(points1, player1);
	}
	else {
		points2 = 0;
		for (auto ball : ballsP2)
		{
			points2 += (int)(500 * ((float)(pointRadius - (boliche->getComponent<Transform>()->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude()) / pointRadius));
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
		maxForce = currentBall->getMaxForce();
	}
	//Crea la bola para el jugador dos si es su turno
	else {
		ballsP2.push_back(sceneManager.instantiateBlueprint("ball"));
		currentBall = ballsP2[myBallCounterP2]->getComponent<ShootComponent>();
		maxForce = currentBall->getMaxForce();

	}
}

void GameManager::changeScene(std::string scene) {
	sceneManager.changeScene(scene);
}

void GameManager::setSkins(std::string skinP1, std::string skinP2)
{
	player1Skin = skinP1;
	player2Skin = skinP2;
}
