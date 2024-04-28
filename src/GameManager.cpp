#include "GameManager.h"
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Transform.h>
//#include <Serializer.h>
const std::string GameManager::id = "GameManager";

GameManager::GameManager(): firstTurn(true), isP1(false), turnStarted(false),
cinematicCamera(false), myBallCounterP1(0),myBallCounterP2(0),maxBalls(3),points1(0),points2(0), pointRadius(100){
	//serializer(cameraOffset, "cameraOffset");
}

GameManager::~GameManager() {
}

bool GameManager::initComponent(ComponentData* data) {
	scene = SceneManager::GetInstance()->getActiveScene();
	ballsP1 = std::vector<Entity*>();
	ballsP2 = std::vector<Entity*>();
	cam = scene->getEntityByHandler("cam")->getComponent<Transform>();
	return true;

}

void GameManager::update() {
	//Bucle para calcular los puntos de la partida
	//No sabemos si se hara aqui o en un point component el calculo de los puntos
	if (cinematicCamera) {
		//La camara sigue la bola hasta que baje de cierta velocidad
		//Y vuelve a la posicion inicial
		// if(isP1) {
		//	camTransform.lookAt(ballsP1[myBallCounterP1]->getComponent<Transform>().getPosition());
		//	speed = ballsP1[myBallCounterP1]->getComponent<RigidBody>()->getSpeed();
		// }
		// else{
		// camTransform.lookAt(ballsP2[myBallCounterP2]->getComponent<Transform>().getPosition());
		//	speed = ballsP2[myBallCounterP2]->getComponent<RigidBody>()->getSpeed(); 
		// }
		//if(speed < 0.1) { 
		// cinematicCamera = false;
		// turnStarted=false;
		//  }
	}
	else if (!turnStarted && !cinematicCamera) {
		if (firstTurn) {
			//bolichePos = SceneManager->createEntity("balliche").getComponent<Transform>();
			//turnStarted = bolichePos.getEntity().getComponent<ShootComponent>().hasShot();
			if (turnStarted) firstTurn = false;
			isP1 = true;
		}
		if (isP1) {
			//Crear bola de petanca jugador 1 y activar su shoot component
			//ballsP1.push_back(SceneManager->createEntity("ball")); //a partir de un prefab preferentemente
			myBallCounterP2++;
			turnStarted = true;
		}
		else {
			//Lo mismo pero con P2
			//ballsP2.push_back(SceneManager->createEntity("ball")); //a partir de un prefab preferentemente
			myBallCounterP2++;
			turnStarted = true;
		}
	}
	else {
		if (isP1) {
			//cinematicCamera = ballsP1[myBallCounterP1]->getComponent<ShootComponent>()->hasShot();
			if (!turnStarted) {
				calculatePoints(isP1);
				isP1 = false;
			}
		}
		else {
			//cinematicCamera = ballsP2[myBallCounterP2]->getComponent<ShootComponent>()->hasShot();
			if (!turnStarted) {
				calculatePoints(isP1);
				isP1 = true;
			}
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
