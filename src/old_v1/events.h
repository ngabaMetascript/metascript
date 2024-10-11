#ifndef SCENE_H
#define SCENE_F

#include "component.h"
class Scene{
	protected:
		Component* components;
};

class WebScene : public Scene{
	protected:
		char** head_links;
		char** foot_scripts;
}

class PhaserScene : public WebScene {

}

#endif
