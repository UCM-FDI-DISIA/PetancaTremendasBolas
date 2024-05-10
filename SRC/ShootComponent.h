#pragma once
#ifndef SHOOT_COMPONENT_H_
#define SHOOT_COMPONENT_H_
#include <Component.h>
#include <Vector3.h>

class Camera;
class Input;
class Transform;
class RigidBody;
class ShootComponent : public Component
{
private:
	// Booleanos de control
	bool onStart;
	bool positioning;
	bool strengthControl;
	bool invert;

	// Valores de fuerzas
	float cameraOffset;
	float cameraOffsetWithoutY;
	float rotation;
	float ballRotation;
	float maxForce;
	float force;

	// Vectores de direccion
	forge::Vector3 cameraPos;
	forge::Vector3 ballInitialPosition;
	forge::Vector3 forward;
	forge::Vector3 prevGrav;

	// Referencias a objetos
	Camera* cam;
	Transform* camTransform;
	RigidBody* myRigidBody;
	Input* input;
public:
	static const std::string id;
	ShootComponent ();
	~ShootComponent ();
	
	bool initComponent(ComponentData* data) override;

	void update() override;
	
	/// <summary>
	/// Comienza la fase de posicionamiento de la bola
	/// </summary>
	void activatePositioning();

	/// <summary>
	/// Continua el flujo de disparo desactivando el posicionamiento
	/// </summary>
	void deactivatePositioning();

	/// <summary>
	/// Activa la fase de lanzamiento en la que se mide la fuerza del tiro
	/// </summary>
	void activateStrengthControl();

	/// <summary>
	/// Desactiva la fase de lanzamiento una vez lanzado
	/// </summary>
	void deactivateStrengthControl();

	/// <summary>
	/// Devuelve un booleano segun si se ha disparado ya o no
	/// </summary>
	bool hasShot();

#pragma region geters
	/// <summary>
	/// Devuelve la fuerza de tiro actual
	/// </summary>
	/// <returns></returns>
	float getForce();

	/// <summary>
	/// Devuelve la fuerza de tiro maxima que se puede alcanzar
	/// </summary>
	float getMaxForce();
#pragma endregion
}; 
#endif // SHOOT_COMPONENT_H_