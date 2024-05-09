#ifndef UIMANAGER_H_
#define UIMANAGER_H_

#include <Component.h>
class Text;
class ProgressBar;
class GameManager;
class UIManager : public Component {
private:
	ProgressBar* forceBar;
	Text* pointsP1;
	Text* pointsP2;
	Text* tPlayer;
	bool init;

	GameManager* myGameManager;

	/// <summary>
	/// Registra la UI de la petanca
	/// </summary>
	void registerUI();
public:
	static const std::string id;

	/// <summary>
	/// Constructora del UIManager
	/// </summary>	
	UIManager();

	/// <summary>
	/// Destructora del UIManager
	/// </summary>	
	~UIManager();

	/// <summary>
	/// Inicializa la UIManager con los parametros adecuados
	/// </summary>
	/// <param name="data">Parametros necesarios para la iniciacion del componente</param>
	bool initComponent(ComponentData* data) override;

	/// <summary>
	/// Actualizacion de la interfaz
	/// </summary>
	void update() override;

	/// <summary>
	/// Cierra el juego
	/// </summary> 
	void exit();
	/// <summary>
	/// Carga de la siguiente
	/// </summary> 
	void play();

	/// <summary>
	/// Actualiza la barra con respecto a dos valores
	/// </summary>
	/// <param name="value">Valor a actualizar</param>
	/// <param name="maxValue">Valor maximo de la barra</param>
	void updateProgressBar(float value, float maxValue);

	/// <summary>
	/// Actualiza los puntos de los dos jugadores
	/// </summary>
	/// <param name="points">Puntos a poner</param>
	/// <param name="p1">Si es el jugador 1</param>
	void updatePoints(int points, bool p1);

	/// <summary>
	/// Escribe de quien es el turno actual
	/// </summary>
	/// <param name="p1">Si es el jugador 1</param>
	void updateTurn(bool p1);
};
#endif //!UIMANAGER_H_