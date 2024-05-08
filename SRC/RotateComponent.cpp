#include "RotateComponent.h"
#include "ComponentData.h"
#include "Serializer.h"
#include <Entity.h>
#include <Transform.h>
#include <TimeForge.h>

const std::string RotateComponent::id = "RotateComponent";

RotateComponent::RotateComponent():
	transform(nullptr){
	serializer(rotationSpeed, "rotationSpeed");
}

bool RotateComponent::initComponent(ComponentData* data) {
	if (entity->hasComponent<Transform>())
	{	
		transform = entity->getComponent<Transform>();
		return true;
	}
	else
	{
		return false;
	}
}

void RotateComponent::update() {
	
	transform->rotateY(rotationSpeed * (float)forge::Time::deltaTime);

}