#ifndef UIMANAGER_H_
#define UIMANAGER_H_

#include <Component.h>

class UIManager : public Component {
private:

public:
	static const std::string id;

	UIManager();

	~UIManager();

	bool initComponent(ComponentData* data) override;

	void play();
};
#endif //!UIMANAGER_H_