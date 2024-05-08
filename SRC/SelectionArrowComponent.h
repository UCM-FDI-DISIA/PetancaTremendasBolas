#pragma once
#include "Component.h"
class Button;
class SelectionArrowComponent : public Component {
private:
	Button* button;
	bool left;
	
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
};