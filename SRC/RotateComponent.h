#pragma once
#include "Component.h"
class Transform;
class RotateComponent : public Component {
private:
	float rotationSpeed;
	Transform* transform;
public:
	static const std::string id;	
	/// <summary>
	/// Constructora por defecto del component RotateComponent
	/// </summary>
	RotateComponent();
	/// <summary>
	/// Se llama en la creacion del componente RotateComponent
	/// </summary>
	/// <param name="data">Bloque con la informacion guardada para el componente</param>
	bool initComponent(ComponentData* data) override;
	/// <summary>
	/// Actualiza la logica del componente, llamandose en cada iteracion del bucle principal
	/// </summary>
	void update() override;
};