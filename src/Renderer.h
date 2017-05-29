#ifndef OSIM_RENDERER
#define OSIM_RENDERER

#include <SDL.h>
#include <SDL_render.h>
#include "misc/RenderInstruction.h"

class Renderer {
public:
	const int WINDOW_WIDTH = 600;
	const int WINDOW_HEIGHT = 360;
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	void drawInstruction(RenderInstruction instruction);
	void beginRendering();
	void swapBuffers();
	
	Renderer();
	~Renderer();
};

#endif
