#pragma once
#include "Component.h"
class Text;
class SelectionManager : public Component {
private:
	enum selectionSteps {
		player1Selecting,
		player2Selecting,
		mapSelecting,
		selectionConfirmation
	};
	/// <summary>
	/// Referencia a la bola de preview
	/// </summary>
	Entity* previewBall;
	/// <summary>
	/// Referencia al mapa de preview
	/// </summary>
	Entity* previewMap;
	/// <summary>
	/// Paso actual de la seleccion
	/// </summary>
	selectionSteps currentStep;
	/// <summary>
	/// La skin actualmente seleccionada
	/// </summary>
	int currentSkinSelection;
	/// <summary>
	/// El mapa actualmente seleccionado
	/// </summary>
	int currentMapSelection;

	/// <summary>
	/// Seleccion de skin del jugador 1
	/// </summary>
	int player1Selection;
	/// <summary>
	/// Seleccion de skin del jugador 2
	/// </summary>
	int player2Selection;
	/// <summary>
	/// Seleccion del mapa
	/// </summary>
	int mapSelection;

	bool confirmation;

	std::vector<std::string> materials;
	std::vector<std::string> maps;

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
	/// <summary>
	/// Cambia la logica de los botones a la seleccion de mapa
	/// </summary>
	void swapToMapSelection();
	/// <summary>
	/// Cambia el material de la bola
	/// </summary>
	void swapMaterial();
	/// <summary>
	/// Cambia la textura del mapa
	/// </summary>
	void swapMap();
	/// <summary>
	/// Desplaza el selector actual
	/// </summary>
	void moveLeft();
	/// <summary>
	/// Desplaza el selector actual
	/// </summary>
	void moveRight();

	void makeSelection();

	void confirmSelection();
};