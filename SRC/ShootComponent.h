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
	bool onStart;
	bool positioning;
	bool strengthControl;
	bool invert;
	double cameraOffset;
	double cameraOffsetWithoutY;
	double rotation;
	double ballRotation;
	double maxForce;
	double force;
	forge::Vector3 cameraPos;
	forge::Vector3 ballInitialPosition;
	forge::Vector3 forward;
	forge::Vector3 prevGrav;

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
	
	void activatePositioning();
	void deactivatePositioning();
	void activateStrengthControl();
	void deactivateStrengthControl();
	bool hasShot();
}; 
#endif // SHOOT_COMPONENT_H_