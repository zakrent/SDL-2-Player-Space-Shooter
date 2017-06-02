#include "Program.h"

Program::Program(){
	bodies.push_back(new Planet(Vector2D(300,150),Vector2D(0,0),10,1000,&bodies));
	bodies.back()->isStatic = true;
	bodies.push_back(new Planet(Vector2D(400,150),Vector2D(0,-0.7),2,1,&bodies));
}


Program::~Program(){
	SDL_Quit();
}

void Program::startMainLoop(){
	lastUpdate = 0;
	bool running = true;
	std::vector<RenderInstruction> renderInstructions;
	while(running){
		
		renderInstructions.clear();

		for(Body* body : bodies){
			body->update();
			for(RenderInstruction instruction : body->getRenderInstructions()){
				renderInstructions.push_back(instruction);
			}
		}
		
		mainRenderer.beginRendering();
		for(RenderInstruction instruction : renderInstructions){
			mainRenderer.drawInstruction(instruction);
		}
		mainRenderer.swapBuffers();

		SDL_Event event;	
		while( SDL_PollEvent( &event) != 0 ) {
			switch(event.type){
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
			}
		}

		if (!SDL_TICKS_PASSED(SDL_GetTicks() + 1, lastUpdate + MIN_UPDATE_TIME)) {
					SDL_Delay((lastUpdate + MIN_UPDATE_TIME) - SDL_GetTicks());
		}
		lastUpdate = SDL_GetTicks();
	}
}
