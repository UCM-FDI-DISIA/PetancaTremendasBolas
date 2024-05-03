#include "ShootComponent.h"
#include <Camera.h>
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Input.h>
#include <Transform.h>
#include <RigidBody.h>
#include <limits>
#define PI 3.14159265359

const std::string ShootComponent::id = "ShootComponent";

ShootComponent::ShootComponent() :input(Input::GetInstance()), cameraOffset(0), rotation(0), force(0), invert(0), ballRotation(0), onStart(true),
ballOffset(0) {
	positioning = true;
	strengthControl = false;
	cam = nullptr;
	camTransform = nullptr;
	initialPos = forge::Vector3(std::numeric_limits<int>::max(), std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
	myRigidBody = nullptr;
	ballInitialPosition = forge::Vector3(0, 0, 0);
	//serializer(maxForce, "maxForce");
}

ShootComponent::~ShootComponent() {
}

bool ShootComponent::initComponent(ComponentData* data) {
	myRigidBody = entity->getComponent<RigidBody>();
	ballInitialPosition = entity->getComponent<Transform>()->getPosition();
	return true;
}

void ShootComponent::update() {
	//Inicializar el componente
	if(cam==nullptr)cam = SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Camera>();
	if (camTransform == nullptr)camTransform = SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Transform>();
	if (onStart) {
		cameraOffset = forge::Vector3(camTransform->getPosition().getX() - entity->getComponent<Transform>()->getPosition().getX(), 0,
			camTransform->getPosition().getZ() - entity->getComponent<Transform>()->getPosition().getZ()).magnitude();
		ballOffset= forge::Vector3(0, camTransform->getPosition().getY() - entity->getComponent<Transform>()->getPosition().getY(),
			camTransform->getPosition().getZ() - entity->getComponent<Transform>()->getPosition().getZ()).magnitude();
		onStart = false;
	}

	if(initialPos.getX()== std::numeric_limits<int>::max())initialPos = camTransform->getPosition();
	//camTransform->lookAt(scene->getEntityByHandler("Player")->getComponent<Transform>()->getPosition());
	// Si se esta posicionando
	if (positioning) {
		// Posicionar
		if (input->keyPressed(K_LEFT)) {
			// Mover a la izquierda
			rotation += 2;
			rotation %= 360;
			camTransform->setPosition(forge::Vector3(cameraOffset * sin((float)rotation/180*PI), initialPos.getY(), cameraOffset * cos((float)rotation / 180 * PI)));
		}
		if (input->keyPressed(K_RIGHT)) {
			// Mover a la derecha
			rotation -= 2;
			rotation %= 360;
			camTransform->setPosition(forge::Vector3(cameraOffset * sin((float)rotation / 180 * PI), initialPos.getY(), cameraOffset * cos((float)rotation / 180 * PI)));
		}
		if (input->keyPressed(K_UP)) {
			// Mover arriba
			ballRotation += 2;
			ballRotation %= 360;
			myRigidBody->setPosition(forge::Vector3(ballInitialPosition.getX(), ballOffset * sin((float)ballRotation / 180 * PI), ballOffset * cos((float)ballRotation / 180 * PI)));
		}
		if (input->keyPressed(K_DOWN)) {
			// Mover abajo
			ballRotation -= 2;
			ballRotation %= 360;
			myRigidBody->setPosition(forge::Vector3(ballInitialPosition.getX(), ballOffset * sin((float)ballRotation / 180 * PI), ballOffset * cos((float)ballRotation / 180 * PI)));
		}
		if (input->keyDown(K_SPACE)) {
			// Disparar
			positioning = false;
			strengthControl = true;
		}
	}

	// Si se esta controlando la fuerza
	if (strengthControl) {
		// Controlar la fuerza
		// sacar el vector al que esta mirando la camara y aplicar una fuerza en esa direccion 
		// con el vector unitario por la fuerza que se le quiera aplicar dejando presionado el espacio
		// La fuerza variara con una funcion sinusoidal para bajar a 0 y subir a un maximo y luego volver a bajar a 0
		if (input->keyPressed(K_SPACE)) {
			//Se puede cambiar por un valor en el futuro
			if (!invert) {
				force++;
			}
			else {
				force--;
			}
			if (force > maxForce) {
				force = maxForce;
				invert = true;
			}
			else if (force < 0) {
				force = 0;
				invert = false;
			}
		}
		if (input->keyUp(K_SPACE)) {
			// Disparar
			// Aplicar fuerza
			forge::Vector3 forceVector = camTransform->getForward();
			forceVector.normalize();
			forceVector = forceVector * force;
			entity->getComponent<RigidBody>()->applyForce(forceVector);
			force = 0;
			strengthControl = false;
		}
	}
	
}

void ShootComponent::activatePositioning() {
	positioning = true;
}

void ShootComponent::deactivatePositioning() {
	positioning = false;
}

void ShootComponent::activateStrengthControl() {
	strengthControl = true;
}

void ShootComponent::deactivateStrengthControl() {
	strengthControl = false;
}

bool ShootComponent::hasShot() {
	return positioning || strengthControl;
}