#ifndef UIMANAGER_H_
#define UIMANAGER_H_

#include <Component.h>
class Text;
class ProgressBar;
class UIManager : public Component {
private:
	ProgressBar* forceBar;
	Text* pointsP1;
	Text* pointsP2;
	Text* tPlayer;
	bool init;

	/// <summary>
	/// Registra la UI de la petanca
	/// </summary>
	void registerUI();
public:
	static const std::string id;

	UIManager();

	~UIManager();

	bool initComponent(ComponentData* data) override;

	void update() override;

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