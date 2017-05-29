#include "misc/Vector2D.h"	
#include "Renderer.h"

Renderer::Renderer(){
    SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

Renderer::~Renderer(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Renderer::beginRendering(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void Renderer::swapBuffers(){
	SDL_RenderPresent(renderer);
}	

void Renderer::drawInstruction(RenderInstruction instruction){
	SDL_SetRenderDrawColor(
			renderer,
			instruction.colR,
			instruction.colG,
			instruction.colB,
			0xff);
	SDL_RenderDrawLine(
			renderer,
			(int)instruction.startPos.x,
			(int)instruction.startPos.y,
			(int)instruction.endPos.x,
			(int)instruction.endPos.y);
}	
