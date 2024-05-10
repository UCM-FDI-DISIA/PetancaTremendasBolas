#pragma once
#include "Component.h"
class SelectionManager;
class Button;
class SelectionArrowComponent : public Component {
private:
	SelectionManager* selectionManager;
public:
	static const std::string id;	
	/// <summary>
	/// Constructora por defecto del component SelectionArrowComponent
	/// </summary>
	SelectionArrowComponent();
	/// <summary>
	/// Se llama en la creacion del componente SelectionArrowComponent
	/// </summary>
	/// <param name="data">Bloque con la informacion guardada para el componente</param>
	bool initComponent(ComponentData* data) override;
	/// <summary>
	/// Actualiza la logica del componente, llamandose en cada iteracion del bucle principal
	/// </summary>
	void update() override;
	/// <summary>
	/// Llama a cambiar el objeto hacia la izquierda
	/// </summary>
	void callLeft();
	/// <summary>
	/// Llama a cambiar el objeto hacia la derecha
	/// </summary>
	void callRight();
	/// <summary>
	/// Llama a seleccionar el objeto
	/// </summary>
	void callSelect();
};