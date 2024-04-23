#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_
#include <Component.h>

class GameManager:public Component {
private:
	bool isP1;
	bool firstTurn;
	bool turnStarted;
	bool cinematicCamera;
	int myBallCounterP1;
	int myBallCounterP2;
	int maxBalls;
	std::vector<Entity*> ballsP1;
	std::vector<Entity*> ballsP2;

	forge::Vector3 iniPos;
	Scene* scene;
	Entity* cam;
public:
	static const std::string id;

	GameManager();
	~GameManager();

	bool initComponent(ComponentData* data) override;
	void update() override;

};
#endif // !GAME_MANAGER_H_
