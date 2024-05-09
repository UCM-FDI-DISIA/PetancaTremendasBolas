#include "SelectionManager.h"
#include "ComponentData.h"
#include "Serializer.h"
#include <Entity.h>
#include <Mesh.h>
#include <Text.h>
#include <SceneManager.h>
#include <Scene.h>
#include <Input.h>

const std::string SelectionManager::id = "SelectionManager";

SelectionManager::SelectionManager() :
	previewBall(nullptr),
	currentStep(player1Selecting),
	text(nullptr),
	player1Selection(0),
	player2Selection(0),
	currentSelection(0),
	confirmation(false){
	serializer(materials, "materials");
}

bool SelectionManager::initComponent(ComponentData* data) {
	entity->getInvoker().registerFunction("moveLeft", [&]() {
		moveLeft();
		});
	entity->getInvoker().registerFunction("moveRight", [&]() {
		moveRight();
		});
	entity->getInvoker().registerFunction("selectSkin", [&]() {
		selectSkin();
		});
	
	return true;
}

void SelectionManager::update() {
	if (previewBall == nullptr) {
		previewBall = scene->getEntityByHandler("PreviewBall");
	}
	if (Input::GetInstance()->keyDown(K_A))
	{
		moveLeft();
	}
	if (Input::GetInstance()->keyDown(K_D))
	{
		moveRight();
	}
	if (Input::GetInstance()->keyDown(K_SPACE))
	{
		selectSkin();
	}
}

void SelectionManager::nextStep()
{
}

void SelectionManager::swapMaterial()
{
	auto ballMat = previewBall->getComponent<Mesh>();
	ballMat->setMaterial(materials[currentSelection]);
}

void SelectionManager::moveLeft()
{
	std::cout << "Left" << std::endl;
	currentSelection--;
	//Si llega al principio de la lista, se mueve al final
	if (currentSelection < 0)
	{
		currentSelection = (int)materials.size() - 1;
	}
	//Si el jugador 1 selecciona la misma opcion que el jugador 2, se mueve a la siguiente
	if (currentStep == player2Selecting && player1Selection == currentSelection)
	{
		currentSelection--;
		//Es necesario volver a controlar si se ha llegado al principio de la lista, por si el jugador 1 selecciona la primera opcion
		if (currentSelection < 0)
		{
			currentSelection = (int)materials.size() - 1;
		}
	}
	swapMaterial();
}

void SelectionManager::moveRight()
{
	currentSelection++;
	//Si llega al final de la lista, se mueve al principio
	if (currentSelection >= materials.size())
	{
		currentSelection = 0;
	}
	//Si el jugador 1 selecciona la misma opcion que el jugador 2, se mueve a la siguiente
	if (currentStep == player2Selecting && player1Selection == currentSelection)
	{
		currentSelection++;
		//Es necesario volver a controlar si se ha llegado al final de la lista, por si el jugador 1 selecciona la ultima opcion
		if (currentSelection >= materials.size())
		{
			currentSelection = 0;
		}
	}
	swapMaterial();
}

void SelectionManager::selectSkin()
{
	if (currentStep == player1Selecting)
	{
		player1Selection = currentSelection;
		currentStep = player2Selecting;
		moveRight();
	}
	else if (currentStep == player2Selecting)
	{
		player2Selection = currentSelection;
		currentStep = selectionConfirmation;
	}
	else if (currentStep == selectionConfirmation)
	{
		confirmSelection();
	}
}

void SelectionManager::confirmSelection()
{
	std::cout << "Seleccion confirmada" << std::endl;
}
