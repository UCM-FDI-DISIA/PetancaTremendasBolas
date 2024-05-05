#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_
#include <Component.h>
#include <Vector3.h>

class Entity;
class Transform;
class Scene;
namespace forge {
	class Vector3;
}

class GameManager:public Component {
private:
	bool isP1;
	bool firstTurn;
	bool turnStarted;
	bool cinematicCamera;
	int myBallCounterP1;
	int myBallCounterP2;
	int maxBalls;
	int points1;
	int points2;
	float pointRadius;
	float speed;
	std::vector<Entity*> ballsP1;
	std::vector<Entity*> ballsP2;

	Transform* bolichePos;
	float cameraOffset;
	Scene* scene;
	Transform* cam;
	forge::Vector3 initialCamPos;
public:
	static const std::string id;

	GameManager();
	~GameManager();

	bool initComponent(ComponentData* data) override;
	void update() override;
	int calculatePoints(bool player1);

};
#endif // !GAME_MANAGER_H_
