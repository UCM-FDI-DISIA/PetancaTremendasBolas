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
	bool end;
	bool playing;
	bool waitForRefresh;
	bool endUI;

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
	float winnerTime;

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

	//Valores relacionados con la seleccion de skins
	std::string player1Skin;
	std::string player2Skin;
	std::string mapSelected;
public:
	static const std::string id;

	GameManager();
	~GameManager();

	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Inicializa las variables del gameManager que no se pueden inicializar en el initComponent
	/// </summary>
	void initVariables();

	void update() override;
	/// <summary>
	/// Bucle de juego principal
	/// </summary>
	void mainLoop();

	/// <summary>
	/// Metod para calcular los puntos con respecto a la distancia del boliche
	/// </summary>
	/// <param name="player1">Booleano para saber si eres el jugador 1 o 2</param>
	/// <returns>Los puntos para actualizar la UI</returns>
	
	int calculatePoints(bool player1);

	void cinematicCameraPhase();

	/// <summary>
	/// Crea la bola a instanciar para el jugador
	/// </summary>
	/// <param name="player1">Para saber si se crea la bola para P1 o P2</param>
	void createBall(bool player1);

	/// <summary>
	/// Cambia el material de la bola según la escogida
	/// </summary>
	/// <param name="skinP1">Material para el jugador 1</param>
	/// <param name="skinP2">Material para el jugador 2</param>
	void setSkins(std::string skinP1, std::string skinP2);

	/// <summary>
	/// Elije el mapa en el que se jugará
	/// </summary>
	/// <param name="map">Mapa para jugar</param>
	void setMap(std::string map);

	/// <summary>
	/// Cambia la escena e inicia el juego si es un mapa jugable
	/// </summary>
	/// <param name="scene">Escena para comenzar</param>
	void changeScene(std::string const& scene);

	/// <summary>
	/// Inicia la fase final del juego en la que se reinician los valores y se muestra al jugador
	/// </summary>
	void endGamePhase();

	/// <summary>
	/// Inicia las variables necesarias para empezar el juego
	/// </summary>
	/// <param name="playing">booleano para empezar o parar del juego</param>
	void setPlaying(bool playing);

	/// <summary>
	/// Cheackea si hay colision de las bolas para el sonido
	/// </summary>
	void checkCollisions();
};
#endif // !GAME_MANAGER_H_
