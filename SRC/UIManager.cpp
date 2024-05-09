#include <SceneManager.h>
#include <Entity.h>
#include <Invoker.h>
#include "UIManager.h"
#include <Text.h>
#include <ProgressBar.h>
#include<SceneManager.h>
#include <Scene.h>
const std::string UIManager::id = "UIManager";

UIManager::UIManager():pointsP1(nullptr), pointsP2(nullptr), tPlayer(nullptr), forceBar(nullptr), init(false)  {
	
}

UIManager::~UIManager() {

}

bool UIManager::initComponent(ComponentData* data) {
	//entity->getInvoker().registerFunction("play", [&]() { play(); });
	return true;
}

void UIManager::update()
{
	if (!init && sceneManager.getActiveSceneId() == "Test") {
		registerUI();
		init = true;
	}
}

void UIManager::play() {
	sceneManager.changeScene("Valencia", true);
}

void UIManager::registerUI() {
	pointsP1 = sceneManager.getActiveScene()->getEntityByHandler("PuntosP1")->getComponent<Text>();
	pointsP2 = sceneManager.getActiveScene()->getEntityByHandler("PuntosP2")->getComponent<Text>();
	tPlayer = sceneManager.getActiveScene()->getEntityByHandler("Turn")->getComponent<Text>();
	forceBar = sceneManager.getActiveScene()->getEntityByHandler("ForceBar")->getComponent<ProgressBar>();
}

void UIManager::updateProgressBar(float value, float maxValue) {
	forceBar->setValue(value / maxValue);
}

void UIManager::updatePoints(int points, bool p1){
	std::string aux;
	if (p1) {
		aux = "Points p1: ";
		aux += std::to_string(points);
		pointsP1->setText(aux);
	}
	else {
		aux = "Points p2: ";
		aux += std::to_string(points);
		pointsP1->setText(aux);
	}
}

void UIManager::updateTurn(bool p1){
	if (p1) {
		tPlayer->setText("PLAYER 1 TURN");
		tPlayer->setColor({ 0, 0, 1, 1 });
	}
	else {
		tPlayer->setText("PLAYER 2 TURN");
		tPlayer->setColor({ 1, 0, 0, 1 });
	}
}