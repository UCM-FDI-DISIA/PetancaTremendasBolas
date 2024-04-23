#include "ShootComponent.h"
#include <Camera.h>
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Input.h>
#include <Transform.h>
#include <RigidBody.h>
#define PI 3.14159265359

const std::string ShootComponent::id = "ShootComponent";

ShootComponent::ShootComponent():input(Input::GetInstance()), cameraOffset(0), rotation(0){
	positioning = true;
	strengthControl = false;
	cam = nullptr;
	camTransform = nullptr;
	initialPos = forge::Vector3(0, 0, 0);
}

ShootComponent::~ShootComponent() {
}

bool ShootComponent::initComponent(ComponentData* data) {
	// Inicializar el componente
	cam = SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Camera>();
	camTransform= SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Transform>();
	cameraOffset = forge::Vector3(camTransform->getPosition() - entity->getComponent<Transform>()->getPosition()).magnitude();
	initialPos = camTransform->getPosition();
	return true;
}

void ShootComponent::update() {
	// Si se esta posicionando
	if (positioning) {
		// Posicionar
		if (input->keyDown(K_LEFT)) {
			// Mover a la izquierda
			rotation += 2;
			camTransform->setPosition(forge::Vector3(initialPos.getX() * cos(rotation), initialPos.getY(), initialPos.getZ() * sin(rotation)));
			camTransform->rotateY(2);
		}
		if (input->keyDown(K_RIGHT)) {
			// Mover a la derecha
			rotation -= 2;
			camTransform->setPosition(forge::Vector3(initialPos.getX() * cos(rotation), initialPos.getY(), initialPos.getZ() * sin(rotation)));
			camTransform->rotateY(-2);
		}
		if (input->keyDown(K_UP)) {
			// Mover arriba
		}
		if (input->keyDown(K_DOWN)) {
			// Mover abajo
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