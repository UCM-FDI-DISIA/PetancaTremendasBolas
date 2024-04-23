#include "GameManager.h"
#include <SceneManager.h>
#include <Scene.h>
#include <Vector3.h>
#include <Camera.h>
const std::string GameManager::id = "GameManager";

GameManager::GameManager() {
}

GameManager::~GameManager() {
}

bool GameManager::initComponent(ComponentData* data) {
	scene = SceneManager::GetInstance()->getActiveScene();
	cam = scene->getEntityByHandler("cam");
	isP1 = true;
	return true;
}

void GameManager::update() {
	//Bucle para calcular los puntos de la partida
	//No sabemos si se hara aqui o en un point component el calculo de los puntos
	if (cinematicCamera) {
		//La camara sigue la bola hasta que baje de cierta velocidad
		//Y vuelve a la posicion inicial
		// speed = ballsP1[myBallCounterP1]->getComponent<RigidBody>()->getSpeed(); <- Implementar en FORGE RigidBody
		//if(speed < 0.1) { cinematicCamera = false; }
	}
	else if (!turnStarted && !cinematicCamera) {
		if (isP1) {
			//Crear bola de petanca jugador 1 y activar su shoot component
			//ballsP1.push_back(scene->createEntity("ballP1")); a partir de un prefab preferentemente
			//
			turnStarted = true;
		}
		else {
			//Lo mismo pero con P2
			turnStarted = true;
		}
	}
	else {
		if (isP1) {
			//turnStarted = ballsP1[myBallCounterP1]->getComponent<ShootComponent>()->hasShot();
			if (!turnStarted) {
				isP1 = false;
			}
		}
		else {
			//turnStarted = ballsP2[myBallCounterP2]->getComponent<ShootComponent>()->hasShot();
			if (!turnStarted) {
				isP1 = true;
			}
		}
	}
	
	
}