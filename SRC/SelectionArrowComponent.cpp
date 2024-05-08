#include "SelectionArrowComponent.h"
#include "ComponentData.h"
#include "Serializer.h"
#include <Entity.h>
#include <Button.h>
const std::string SelectionArrowComponent::id = "SelectionArrowComponent";

SelectionArrowComponent::SelectionArrowComponent():
	button(entity->getComponent<Button>())
{
	serializer(left, "left");
}

bool SelectionArrowComponent::initComponent(ComponentData* data) {
	return true;
}

void SelectionArrowComponent::update() {
	
}