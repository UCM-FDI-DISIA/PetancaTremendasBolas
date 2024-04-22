#include "ShootComponent.h"
#include <Camera.h>
#include <SceneManager.h>
#include <Scene.h>
#include <Entity.h>
#include <Input.h>

const std::string ShootComponent::id = "ShootComponent";

ShootComponent::ShootComponent():input(Input::GetInstance()) {
	positioning = false;
	strengthControl = false;
	cam = nullptr;
}

ShootComponent::~ShootComponent() {
}

bool ShootComponent::initComponent(ComponentData* data) {
	// Inicializar el componente
	cam = SceneManager::GetInstance()->getActiveScene()->getEntityByHandler("cam")->getComponent<Camera>();
	
	return true;
}

void ShootComponent::update() {
	// Si se esta posicionando
	if (positioning) {
		// Posicionar
		if (input->keyDown(K_LEFT)) {
			// Mover a la izquierda
			//Mover la camara con transform de la camara??? 
			//Y luego cambiar al modo de disparo con strengthControl
		}
		if (input->keyDown(K_RIGHT)) {
			// Mover a la derecha
		}
		if (input->keyDown(K_UP)) {
			// Mover arriba
		}
		if (input->keyDown(K_DOWN)) {
			// Mover abajo
		}
	}
	// Si se esta controlando la fuerza
	if (strengthControl) {
		// Controlar la fuerza
		// sacar el vector al que esta mirando la camara y aplicar una fuerza en esa direccion 
		// con el vector unitario por la fuerza que se le quiera aplicar dejando presionado el espacio
		// La fuerza variara con una funcion sinusoidal para bajar a 0 y subir a un maximo y luego volver a bajar a 0
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