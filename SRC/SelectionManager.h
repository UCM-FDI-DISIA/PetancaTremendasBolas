#pragma once
#include "Component.h"
class Text;
class SelectionManager : public Component {
private:
	enum selectionSteps {
		player1Selecting,
		player2Selecting,
		selectionConfirmation
	};

	Entity* previewBall;

	Text* text;

	selectionSteps currentStep;
	
	int currentSelection;
	
	int player1Selection;
	int player2Selection;
	bool confirmation;

	std::vector<std::string> materials;

public:
	static const std::string id;	
	/// <summary>
	/// Constructora por defecto del component SelectionManager
	/// </summary>
	SelectionManager();
	/// <summary>
	/// Se llama en la creacion del componente SelectionManager
	/// </summary>
	/// <param name="data">Bloque con la informacion guardada para el componente</param>
	bool initComponent(ComponentData* data) override;
	/// <summary>
	/// Actualiza la logica del componente, llamandose en cada iteracion del bucle principal
	/// </summary>
	void update() override;

	void nextStep();

	void swapMaterial();

	void moveLeft();

	void moveRight();

	void selectSkin();

	void confirmSelection();
};