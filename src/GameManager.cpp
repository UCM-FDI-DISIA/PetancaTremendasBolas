#include "GameManager.h"
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Transform.h>
#include <RigidBody.h>
#include "ShootComponent.h"
//#include <Serializer.h>
const std::string GameManager::id = "GameManager";

GameManager::GameManager(): firstTurn(true), isP1(false), turnStarted(false),
cinematicCamera(false), myBallCounterP1(0),myBallCounterP2(0),maxBalls(3),points1(0),points2(0), pointRadius(100), speed(0)
, initialCamPos(0,0,0){
}

GameManager::~GameManager() {
}

bool GameManager::initComponent(ComponentData* data) {
	ballsP1 = std::vector<Entity*>();
	ballsP2 = std::vector<Entity*>();

	//Creamos las TREMENDAS bolas de petanca
	/*for (int i = 0; i < maxBalls; i++) {
		ballsP1.push_back(sceneManager.instantiateBlueprint("ball"));
		ballsP1[i]->setEnabled(false);
		ballsP2.push_back(sceneManager.instantiateBlueprint("ball"));
		ballsP2[i]->setEnabled(false);
	}*/
	bolichePos = sceneManager.instantiateBlueprint("boliche")->getComponent<Transform>();
	cam = sceneManager.getActiveScene()->getEntityByHandler("cam")->getComponent<Transform>();
	initialCamPos = cam->getPosition();
	return true;

}

void GameManager::update() {
	// Bucle para calcular los puntos de la partida
	// Falta control de escena de pausa
	if (cinematicCamera) {
		// La camara sigue la bola hasta que baje de cierta velocidad
		// Y vuelve a la posicion inicial
		 if(isP1) {
			cam->lookAt(ballsP1[myBallCounterP1]->getComponent<Transform>()->getPosition());
			// Camara sigue pelota
			speed = ballsP1[myBallCounterP1]->getComponent<RigidBody>()->getSpeed();
		 }
		 else {
			cam->lookAt(ballsP2[myBallCounterP2]->getComponent<Transform>()->getPosition());
			speed = ballsP2[myBallCounterP2]->getComponent<RigidBody>()->getSpeed(); 
		 }
		 //Si la velocidad de la bola es menor a 0.1, se desactiva la camara cinematica
		 if(speed < 0.1) { 
			 cinematicCamera = false;
			 turnStarted=false;
			 //Camara vuelve a posicion inicial
			 if (isP1) {
				 //Sumamos el contador de bolas y calculamos los puntos y pasamos al siguiente turno
				myBallCounterP1++;
				calculatePoints(isP1);
				isP1 = false;
			 }
			 //Mismo proceso pero con P2
			 else {
				myBallCounterP2++;
				calculatePoints(isP1);
				isP1 = true;
			 }
		 }
	}
	else if (!turnStarted && !cinematicCamera) {
		if (firstTurn) {
			//bolichePos = SceneManager::createEntity("balliche")->getComponent<Transform>();
			turnStarted = bolichePos->getEntity()->getComponent<ShootComponent>()->hasShot();
			if (turnStarted) firstTurn = false;
			isP1 = true;
		}
		if (isP1) {
			//Crear bola de petanca jugador 1 y activar su shoot component
			createBall(isP1);
			turnStarted = true;
		}
		else {
			//Lo mismo pero con P2
			createBall(isP1);
			turnStarted = true;
		}
	}
	//Si el turno ha empezado y no estamos en camara cinematica
	if (turnStarted && !cinematicCamera) {
		if (isP1) {
			cinematicCamera = ballsP1[myBallCounterP1]->getComponent<ShootComponent>()->hasShot();
		}
		else {
			cinematicCamera = ballsP2[myBallCounterP2]->getComponent<ShootComponent>()->hasShot();
		}
	}
}

int GameManager::calculatePoints(bool player1)
{
	if (player1) {
		points1 = 0;
		for (auto ball : ballsP1)
		{
			points1 += 500 * ((float)(pointRadius - (bolichePos->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude())/pointRadius);
		}
	}
	else {
		points2 = 0;
		for (auto ball : ballsP2)
		{
			points2 += 500 * ((float)(pointRadius - (bolichePos->getPosition() - ball->getComponent<Transform>()->getPosition()).magnitude()) / pointRadius);
		}
	}
	return 0;
}

void GameManager::createBall(bool player1)
{
	//Crea la bola para el jugador uno si es su turno
	if (player1) {
		ballsP1.push_back(sceneManager.instantiateBlueprint("ball"));
	}
	//Crea la bola para el jugador dos si es su turno
	else {
		ballsP2.push_back(sceneManager.instantiateBlueprint("ball"));
	}
}
