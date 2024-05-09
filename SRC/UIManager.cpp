#include <SceneManager.h>
#include <Entity.h>
#include <Invoker.h>
#include "UIManager.h"

const std::string UIManager::id = "UIManager";

UIManager::UIManager() {

}

UIManager::~UIManager() {

}

bool UIManager::initComponent(ComponentData* data) {
	entity->getInvoker().registerFunction("play", [&]() { play(); });
	return true;
}

void UIManager::play() {
	sceneManager.changeScene("Valencia", true);
}