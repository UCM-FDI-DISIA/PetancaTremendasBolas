#include "Factory.h"
#include "ForgeImport.h"
#include "ShootComponent.h"
#include "TestComponent.h"

FORGE_IMPORT void registerComponents(Factory& f) {
	/**
        * Para registrar componentes dentro del motor
        * hacer la siguiente llamada:
        * f.registerComponent<ComponentName>();
        */
    //f.registerComponent<ShootComponent>();
    f.registerComponent<TestComponent>();
}