#ifndef OSIM_RENDERER
#define OSIM_RENDERER

#include <SDL.h>
#include <SDL_render.h>
#include "misc/RenderInstruction.h"

class Renderer {
public:
	const int WINDOW_WIDTH = 1366;
	const int WINDOW_HEIGHT = 768;
	SDL_Window* window;
	SDL_Renderer* renderer;
	void drawInstruction(RenderInstruction instruction);
	void beginRendering();
	void swapBuffers();
	
	Renderer();
	~Renderer();
};

#endif
