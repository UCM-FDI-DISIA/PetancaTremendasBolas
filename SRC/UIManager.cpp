#include <SceneManager.h>
#include <Entity.h>
#include <Invoker.h>
#include <MainForge.h>
#include "UIManager.h"
#include <Text.h>
#include <ProgressBar.h>
#include<SceneManager.h>
#include <Scene.h>
#include "GameManager.h"
const std::string UIManager::id = "UIManager";

UIManager::UIManager() : 
	pointsP1(nullptr), 
	pointsP2(nullptr),
	tPlayer(nullptr), 
	forceBar(nullptr), 
	init(false)  {
	myGameManager = nullptr;
}

UIManager::~UIManager() {

}

bool UIManager::initComponent(ComponentData* data) {
	entity->getInvoker().registerFunction("play", [&]() { play(); });
	entity->getInvoker().registerFunction("exit", [&]() { exit(); });
	return true;
}

void UIManager::update() {
	if (!init && sceneManager.getActiveSceneId() != "TitleScreen" && sceneManager.getActiveSceneId() != "SkinSelector") {
		registerUI();
		init = true;
	}
}

void UIManager::play() {
	if (myGameManager == nullptr) {
		myGameManager = sceneManager.getActiveScene()->getEntityByHandler("GameManager")->getComponent<GameManager>();
	}
	sceneManager.changeScene("SkinSelection", true);
}

void UIManager::exit() {
	MainForge::Exit();
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
		aux = "Jugador 1: ";
		aux += std::to_string(points);
		pointsP1->setText(aux);
	}
	else {
		aux = "Jugador 2: ";
		aux += std::to_string(points);
		pointsP2->setText(aux);
	}
}

void UIManager::updateTurn(bool p1){
	if (p1) {
		tPlayer->setText("JUGADOR 1");
	}
	else {
		tPlayer->setText("JUGADOR 2");
	}
}
