#pragma once
#ifndef SHOOT_COMPONENT_H_
#define SHOOT_COMPONENT_H_
#include <Component.h>

class Camera;
class Input;
class ShootComponent : public Component
{
private:
	bool positioning;
	bool strengthControl;

	Camera* cam;
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
}; 
#endif // SHOOT_COMPONENT_H_