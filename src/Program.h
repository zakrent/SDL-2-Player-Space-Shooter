#ifndef OSIM_PROGRAM
#define OSIM_PROGRAM

#include <SDL.h>
#include <vector>
#include "Body.h"
#include "Planet.h"
#include "Renderer.h"
#include "misc/Vector2D.h"

class Program {
private:
	const int MIN_UPDATE_TIME = 10;
	int lastUpdate;
	Renderer mainRenderer;
	std::vector<Body*> bodies;
public:
	void startMainLoop(); 

	Program();
	~Program();

};

#endif
