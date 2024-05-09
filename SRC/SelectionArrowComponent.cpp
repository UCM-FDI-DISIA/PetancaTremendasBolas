#include "SelectionArrowComponent.h"
#include "ComponentData.h"
#include "Serializer.h"
#include "SelectionManager.h"
#include <Entity.h>
#include <Button.h>
#include <Scene.h>

const std::string SelectionArrowComponent::id = "SelectionArrowComponent";

SelectionArrowComponent::SelectionArrowComponent():
	selectionManager(nullptr)
{

}

bool SelectionArrowComponent::initComponent(ComponentData* data) {
	Invoker& invoker = entity->getInvoker();
	invoker.registerFunction("left", [&]() {
		callLeft();
		});
	invoker.registerFunction("right", [&]() {
		callRight();
		});
	invoker.registerFunction("select", [&]() {
		callSelect();
		});
	return true;
}

void SelectionArrowComponent::update() {
	if (selectionManager == nullptr) {
		selectionManager = scene->getEntityByHandler("SelectionManager")->getComponent<SelectionManager>();
		std::cout << "SelectionArrowComponent update" << std::endl;
	}
}

void SelectionArrowComponent::callLeft() {
	std::cout << "lol" << std::endl;
	if (selectionManager == nullptr)
	{
		return;
	}
	std::cout << "xd" << std::endl;
	selectionManager->moveLeft();
}

void SelectionArrowComponent::callRight() {
	if (selectionManager == nullptr)
	{
		return;
	}
	selectionManager->moveRight();
}

void SelectionArrowComponent::callSelect() {
	if (selectionManager == nullptr)
	{
		return;
	}
	selectionManager->selectSkin();
}
