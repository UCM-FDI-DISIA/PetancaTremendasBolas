#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_
#include <Component.h>
#include <Vector3.h>
class Entity;
class Transform;
class Scene;
class ShootComponent;
class UIManager;
namespace forge {
	class Vector3;
}

class GameManager:public Component {
private:
	//Booleanos de control
	bool isP1;
	bool firstTurn;
	bool turnStarted;
	bool cinematicCamera;
	bool init;

	//Contadores
	int myBallCounterP1;
	int myBallCounterP2;
	int maxBalls;
	int points1;
	int points2;

	//Variables del juego
	float pointRadius;
	float speed;
	float maxForce;

	//Vectores de bolas de los jugadores y nombres de las escenas
	std::vector<Entity*> ballsP1;
	std::vector<Entity*> ballsP2;
	std::vector<std::string> sceneNames;

	//Referencia a componentes relevantes aljuego
	Entity* boliche;
	Transform* cam;
	ShootComponent* currentBall;
	UIManager* manager;
	forge::Vector3 initialCamPos;
public:
	static const std::string id;

	GameManager();
	~GameManager();

	bool initComponent(ComponentData* data) override;
	void update() override;

	/// <summary>
	/// Metod para calcular los puntos con respecto a la distancia del boliche
	/// </summary>
	/// <param name="player1">Booleano para saber si eres el jugador 1 o 2</param>
	/// <returns>Los puntos para actualizar la UI</returns>
	int calculatePoints(bool player1);

	/// <summary>
	/// Crea la bola a instanciar para el jugador
	/// </summary>
	/// <param name="player1">Para saber si se crea la bola para P1 o P2</param>
	void createBall(bool player1);
	void changeScene(std::string scene);


};
#endif // !GAME_MANAGER_H_
