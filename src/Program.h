#ifndef OSIM_PROGRAM
#define OSIM_PROGRAM

#include <SDL.h>
#include <vector>
#include "Body.h"
#include "Planet.h"
#include "Player.h"
#include "Renderer.h"
#include "Control.h"
#include "misc/Vector2D.h"

class Program {
private:
	const int MIN_UPDATE_TIME = 15;
	int lastUpdate;
	Renderer mainRenderer;
	Control controller1;
	Control controller2;
	std::vector<Body*> bodies;
public:
	void startMainLoop(); 

	Program();
	~Program();

};

#endif
