#include "GameManager.h"
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Transform.h>
#include <RigidBody.h>
#include "ShootComponent.h"
#include <ProgressBar.h>

//#include <Serializer.h>
const std::string GameManager::id = "GameManager";

GameManager::GameManager(): firstTurn(false),init(true), isP1(false), turnStarted(false),
cinematicCamera(false), myBallCounterP1(0),myBallCounterP2(0),maxBalls(3),points1(0),points2(0), pointRadius(100), speed(0)
, initialCamPos(0,0,0){
	boliche = nullptr;
	cam = nullptr;
}

GameManager::~GameManager() {
}

bool GameManager::initComponent(ComponentData* data) {
	ballsP1 = std::vector<Entity*>();
	ballsP2 = std::vector<Entity*>();
	bar = this->getEntity()->getComponent<ProgressBar>();
	
	return true;
}

void GameManager::update() {
	// Bucle para calcular los puntos de la partida
	// Falta control de escena de pausa
	if (cinematicCamera) {
		
		 //Si la velocidad de la bola es menor a 0.1, se desactiva la camara cinematica
		 if(speed < 5) { 
			 cinematicCamera = false;
			 turnStarted=false;
			 if (!firstTurn) {
				 //Camara vuelve a posicion inicial
				 if (isP1) {
					 //Sumamos el contador de bolas y calculamos los puntos y pasamos al siguiente turno
					 calculatePoints(isP1);
					 cam->setPosition(initialCamPos);
					 cam->lookAt(ballsP1[myBallCounterP1-1]->getComponent<Transform>()->getPosition());
					 isP1 = false;
				 }
				 //Mismo proceso pero con P2
				 else {
					 calculatePoints(isP1);
					 cam->setPosition(initialCamPos);
					 cam->lookAt(ballsP2[myBallCounterP2-1]->getComponent<Transform>()->getPosition());
					 isP1 = true;
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
			bar->setValue(currentBall->getForce() / maxForce);
			if (turnStarted) {
				speed = 100;
				cinematicCamera = turnStarted;
			}
		}
		if (isP1 && !firstTurn) {
			//Crear bola de petanca jugador 1 y activar su shoot component
			createBall(isP1);
			myBallCounterP1++;
			turnStarted = true;
		}
		else if(!firstTurn) {
			//Lo mismo pero con P2
			createBall(isP1 && !firstTurn);
			myBallCounterP2++;
			turnStarted = true;
		}
	}
	//Si el turno ha empezado y no estamos en camara cinematica
	if (turnStarted && !cinematicCamera) {
		if (isP1) {
			cinematicCamera = currentBall->hasShot();
			bar->setValue(currentBall->getForce() / maxForce);
			speed = 100;
		}
		else {
			cinematicCamera = currentBall->hasShot();
			bar->setValue(currentBall->getForce() / maxForce);		
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
	}
	else {
		points2 = 0;
		for (auto ball : ballsP2)
		{
			points2 += (int)(500 * ((float)(pointRadius - (boliche->getComponent<Transform>()->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude()) / pointRadius));
		}
	}
	return 0;
}

void GameManager::createBall(bool player1)
{
	//Crea la bola para el jugador uno si es su turno
	if (player1) {
		ballsP1.push_back(sceneManager.instantiateBlueprint("ball"));
		currentBall = ballsP1[myBallCounterP1]->getComponent<ShootComponent>();
	}
	//Crea la bola para el jugador dos si es su turno
	else {
		ballsP2.push_back(sceneManager.instantiateBlueprint("ball"));
		currentBall = ballsP2[myBallCounterP2]->getComponent<ShootComponent>();
	}
}
