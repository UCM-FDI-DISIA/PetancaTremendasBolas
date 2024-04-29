#include "TestComponent.h"
#include "Input.h"
#include "Transform.h"
#include "ComponentData.h"
#include "Entity.h"
#include "Animator.h"
#include "SceneManager.h"
#include "AudioSource.h"
#include "RigidBody.h"
#include "Collider.h"
const std::string TestComponent::id = "TestComponent";

TestComponent::TestComponent() :
	input(*Input::GetInstance()),
	movement(2.0f),
	transform(nullptr),
	animator(nullptr),
	audio(nullptr),
	rigidBody(nullptr),
	sceneManager(SceneManager::GetInstance()),
	anims(),
	activeAnim(0) {
}

bool TestComponent::initComponent(ComponentData* data) {
		transform = entity->getComponent<Transform>();	
		rigidBody = entity->getComponent<RigidBody>();
		return true;
}

void TestComponent::update() {

	if (input.keyPressed(K_W)) {
		//transform->setPositionZ(transform->getPosition().getZ() + movement);
		rigidBody->setPositionZ(transform->getPosition().getZ());
	}
	if (input.keyPressed(K_S)) {
		//transform->setPositionZ(transform->getPosition().getZ() - movement);
		rigidBody->setPositionZ(transform->getPosition().getZ() - movement);

	}
	if (input.keyPressed(K_D)) {
		//transform->setPositionX(transform->getPosition().getX() + movement);
		rigidBody->setPositionX(transform->getPosition().getX() + movement);
	}
	if (input.keyPressed(K_A)) {
		//transform->setPositionX(transform->getPosition().getX() - movement);
		rigidBody->setPositionX(transform->getPosition().getX() - movement);
	}
	if (input.keyPressed(K_RIGHT)) {
		//transform->rotateY(movement);
		rigidBody->rotateY(movement);
	}
	if (input.keyPressed(K_LEFT)) {
		//transform->rotateY(-movement);
		rigidBody->rotateY(-movement);
	}
}
