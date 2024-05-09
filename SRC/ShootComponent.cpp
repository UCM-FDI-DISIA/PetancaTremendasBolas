#include "ShootComponent.h"
#include <Camera.h>
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Input.h>
#include <Transform.h>
#include <RigidBody.h>
#include <limits>
#include <Serializer.h>
#include <TimeForge.h>
#define PI 3.14159265359

const std::string ShootComponent::id = "ShootComponent";

ShootComponent::ShootComponent() :input(Input::GetInstance()), cameraOffset(0), rotation(0), force(0), invert(0), ballRotation(0), onStart(true),
prevGrav(0,0,0), maxForce(0), cameraOffsetWithoutY(0){
	positioning = true;
	strengthControl = false;
	cam = nullptr;
	camTransform = nullptr;
	cameraPos = forge::Vector3(std::numeric_limits<float>::max(), std::numeric_limits<float>::max(), std::numeric_limits<float>::max());
	myRigidBody = nullptr;
	ballInitialPosition = forge::Vector3(0, 0, 0);
	forward = forge::Vector3(0, 0, -1);
	serializer(maxForce, "maxForce");
}

ShootComponent::~ShootComponent() {
}

bool ShootComponent::initComponent(ComponentData* data) {
	myRigidBody = entity->getComponent<RigidBody>();
	prevGrav = myRigidBody->getGravity();
	myRigidBody->setGravity(forge::Vector3(0, 0, 0));
	ballInitialPosition = entity->getComponent<Transform>()->getPosition();
	return true;
}

void ShootComponent::update() {
	//Inicializar el componente
	if(cam==nullptr)cam = SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Camera>();
	if (camTransform == nullptr)camTransform = SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Transform>();
	if (onStart) {
		cameraOffset = forge::Vector3(camTransform->getPosition().getX() - entity->getComponent<Transform>()->getPosition().getX(), 
			camTransform->getPosition().getY() - entity->getComponent<Transform>()->getPosition().getY(),
			camTransform->getPosition().getZ() - entity->getComponent<Transform>()->getPosition().getZ()).magnitude();
		cameraOffsetWithoutY= forge::Vector3(camTransform->getPosition().getX() - entity->getComponent<Transform>()->getPosition().getX(),
			0,camTransform->getPosition().getZ() - entity->getComponent<Transform>()->getPosition().getZ()).magnitude();
		onStart = false;
		forge::Vector3 target = myRigidBody->getPosition();
		camTransform->lookAtInterpolated(forge::Vector3(target.getX(), ballInitialPosition.getY(), target.getZ()),0.1f);
	}

	cameraPos = camTransform->getPosition();
	//camTransform->lookAt(scene->getEntityByHandler("Player")->getComponent<Transform>()->getPosition());
	// Si se esta posicionando
	// Formula para rotar la camara completamente al rededor : 
	// camTransform->setPosition(forge::Vector3(cameraOffset * sin((float)rotation/180*PI) * abs(cos(ballRotation)), 
	//	cameraOffset* sin(ballRotation / 180 * PI), cameraOffset* cos((float)rotation / 180 * PI)* abs(cos(ballRotation))));
	if (positioning) {
		// Posicionar
		if (input->keyPressed(K_LEFT)&& rotation<90) {
			// Mover a la izquierda
			rotation += 25 * (float)forge::Time::deltaTime;
			if(rotation >= 360)rotation = 0;
			camTransform->setPosition(forge::Vector3(ballInitialPosition.getX() + cameraOffsetWithoutY * (float)sin((float)rotation / 180 * PI), cameraPos.getY(), ballInitialPosition.getZ()
				+ cameraOffsetWithoutY * (float)cos((float)rotation / 180 * PI)));

			forward = forge::Vector3(1 * (float)sin((float)rotation / 180 * PI), 0, 1 * (float)cos((float)rotation / 180 * PI)).normalized();

			myRigidBody->setPosition(forge::Vector3(cameraPos.getX() - cameraOffset * (float)cos(ballRotation / 180 * PI) * forward.getX(),
				cameraPos.getY() + cameraOffset * (float)sin(ballRotation / 180 * PI), cameraPos.getZ() - cameraOffset * (float)cos(ballRotation / 180 * PI) * forward.getZ()));

			forge::Vector3 target = myRigidBody->getPosition();
			camTransform->lookAtInterpolated(forge::Vector3(target.getX(), ballInitialPosition.getY(), target.getZ()), 0.1f);
		}
		if (input->keyPressed(K_RIGHT) && rotation>-90) {
			// Mover a la derecha
			rotation -= 25 * (float)forge::Time::deltaTime;
			if (rotation >= 360)rotation = 0;
			camTransform->setPosition(forge::Vector3(ballInitialPosition.getX() + cameraOffsetWithoutY * (float)sin((float)rotation / 180 * PI), cameraPos.getY(), ballInitialPosition.getZ()
				+ cameraOffsetWithoutY * (float)cos((float)rotation / 180 * PI)));
			forward = forge::Vector3(cameraOffset * (float)sin((float)rotation / 180 * PI), 0, cameraOffset * (float)cos((float)rotation / 180 * PI)).normalized();

			myRigidBody->setPosition(forge::Vector3(cameraPos.getX() - cameraOffset * (float)cos(ballRotation / 180 * PI) * forward.getX(),
				cameraPos.getY() + cameraOffset * (float)sin(ballRotation / 180 * PI), cameraPos.getZ() - cameraOffset * (float)cos(ballRotation / 180 * PI) * forward.getZ()));

			forge::Vector3 target = myRigidBody->getPosition();
			camTransform->lookAtInterpolated(forge::Vector3(target.getX(), ballInitialPosition.getY(), target.getZ()), 0.1f);
		}
		if (input->keyPressed(K_UP) && ballRotation <= 20) {
			// Mover arriba
			ballRotation += 25 * (float)forge::Time::deltaTime;
			if (ballRotation >= 360)ballRotation = 0;
			myRigidBody->setPosition(forge::Vector3(cameraPos.getX() - cameraOffset * (float)cos(ballRotation / 180 * PI) * forward.getX(),
				cameraPos.getY() + cameraOffset * (float)sin(ballRotation / 180 * PI),
				cameraPos.getZ() + cameraOffset * (float)abs(cos(ballRotation / 180 * PI)) * (forward.getZ() < 0 ? forward.getZ() : -forward.getZ())));
		}
		if (input->keyPressed(K_DOWN)&& ballRotation >= -10) {
			// Mover abajo
			ballRotation -= 25 * (float)forge::Time::deltaTime;
			if (ballRotation >= 360)ballRotation = 0;
			myRigidBody->setPosition(forge::Vector3(cameraPos.getX() - cameraOffset * (float)cos(ballRotation / 180 * PI) * forward.getX(),
				cameraPos.getY() + cameraOffset * (float)sin(ballRotation / 180 * PI),
				cameraPos.getZ() + cameraOffset * (float)abs(cos(ballRotation / 180 * PI)) * (forward.getZ()<0?forward.getZ():-forward.getZ())));
			myRigidBody->getPosition();
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
			std::cout << force << std::endl;
		}
		if (input->keyUp(K_SPACE)) {
			// Disparar
			// Aplicar fuerza
			forge::Vector3 forceVector =camTransform->getForward()* (- 1);
			forceVector.normalize();
			forceVector = forge::Vector3(forceVector.getX() * abs(cos(ballRotation)),
				forceVector.getY() * sin(ballRotation), forceVector.getZ() * abs(cos(ballRotation)));
			forceVector = forceVector * force;
			myRigidBody->setGravity(prevGrav);
			myRigidBody->applyForce(forceVector);
			force = 0;
			strengthControl = false;
			this->setEnabled(false);
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


float ShootComponent::getForce()
{
	return force;
}

float ShootComponent::getMaxForce()
{
	return maxForce;
}

void ShootComponent::deactivateStrengthControl() {
	strengthControl = false;
}

bool ShootComponent::hasShot() {
	return !positioning && !strengthControl;
}