#include "SelectionManager.h"
#include "ComponentData.h"
#include "Serializer.h"
#include <Entity.h>
#include <Mesh.h>
#include <Text.h>
#include <SceneManager.h>
#include <Scene.h>
#include <Input.h>
#include "GameManager.h"
#include <Image.h>

const std::string SelectionManager::id = "SelectionManager";

SelectionManager::SelectionManager() :
	previewBall(nullptr),
	previewMap(nullptr),
	currentStep(player1Selecting),
	player1Selection(0),
	player2Selection(0),
	currentSkinSelection(0),
	currentMapSelection(0),
	confirmation(false){
	serializer(materials, "materials");
	serializer(maps, "maps");
}

bool SelectionManager::initComponent(ComponentData* data) {
	return true;
}

void SelectionManager::update() {
	if (previewBall == nullptr) {
		previewBall = scene->getEntityByHandler("PreviewBall");
		currentSkinSelection = 0;
		swapMaterial();
	}
	if (previewMap == nullptr) {
		previewMap = scene->getEntityByHandler("PreviewMap");
		currentMapSelection = 0;
		if (previewMap != nullptr){
			swapMap();
			previewMap->setEnabled(false);
		}
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

void SelectionManager::swapToMapSelection()
{
	previewBall->setEnabled(false);
	previewMap->setEnabled(true);

}

void SelectionManager::swapMaterial()
{
	auto ballMat = previewBall->getComponent<Mesh>();
	ballMat->setMaterial(materials[currentSkinSelection]);
}

void SelectionManager::swapMap()
{
	auto mapImg = previewMap->getComponent<Image>();
	mapImg->setMaterial(maps[currentMapSelection]);
}

void SelectionManager::moveLeft()
{
	if (currentStep != mapSelection)
	{
		currentSkinSelection--;
		//Si llega al principio de la lista, se mueve al final
		if (currentSkinSelection < 0)
		{
			currentSkinSelection = (int)materials.size() - 1;
		}
		//Si el jugador 1 selecciona la misma opcion que el jugador 2, se mueve a la siguiente
		if (currentStep == player2Selecting && player1Selection == currentSkinSelection)
		{
			currentSkinSelection--;
			//Es necesario volver a controlar si se ha llegado al principio de la lista, por si el jugador 1 selecciona la primera opcion
			if (currentSkinSelection < 0)
			{
				currentSkinSelection = (int)materials.size() - 1;
			}
		}
		swapMaterial();
	}
	else
	{
		//TODO: Implementar movimiento de seleccion de mapa
		currentMapSelection--;
		if (currentMapSelection < 0)
		{
			currentMapSelection = (int)maps.size() - 1;
		}
		swapMap();
	}
}

void SelectionManager::moveRight()
{
	if (currentStep != mapSelection)
	{
		currentSkinSelection++;
		//Si llega al final de la lista, se mueve al principio
		if (currentSkinSelection >= materials.size())
		{
			currentSkinSelection = 0;
		}
		//Si el jugador 1 selecciona la misma opcion que el jugador 2, se mueve a la siguiente
		if (currentStep == player2Selecting && player1Selection == currentSkinSelection)
		{
			currentSkinSelection++;
			//Es necesario volver a controlar si se ha llegado al final de la lista, por si el jugador 1 selecciona la ultima opcion
			if (currentSkinSelection >= materials.size())
			{
				currentSkinSelection = 0;
			}
		}
		swapMaterial();
	}
	else
	{
		//TODO: Implementar movimiento de seleccion de mapa
		currentMapSelection++;
		if (currentMapSelection >= maps.size())
		{
			currentMapSelection = 0;
		}
		swapMap();
	}
}

void SelectionManager::selectSkin()
{
	if (currentStep == player1Selecting)
	{
		player1Selection = currentSkinSelection;
		currentStep = player2Selecting;
		moveRight();
	}
	else if (currentStep == player2Selecting)
	{
		player2Selection = currentSkinSelection;
		currentStep = mapSelection;
		swapToMapSelection();
	}
	else if (currentStep == selectionConfirmation)
	{
		confirmSelection();
	}
}

void SelectionManager::confirmSelection()
{
	scene->getEntityByHandler("GameManager")->getComponent<GameManager>()->setSkins(materials[player1Selection], materials[player2Selection]);
}
