#include "Program.h"

Program::Program(){
	bodies.push_back(new Planet(Vector2D(600,300),Vector2D(0,0),5,500,&bodies));
	bodies.back()->isStatic = true;
    bodies.push_back(new Planet(Vector2D(500,300),Vector2D(0,0.6),2,50,&bodies));
    bodies.push_back(new Planet(Vector2D(400,300),Vector2D(0,0.5),2,100,&bodies));
	Player* tempPl = new Player(Vector2D(700,300),Vector2D(0,-0.5),2,0.1,&bodies);
	controller.controlerPlayer = tempPl;
	bodies.push_back(tempPl);
}


Program::~Program(){
    for(int i = 0; i < bodies.size(); ++i){
        delete bodies[i];
        bodies.erase(bodies.begin()+i);
    }
	SDL_Quit();
}

void Program::startMainLoop(){
	lastUpdate = 0;
	bool running = true;
	std::vector<RenderInstruction> renderInstructions;
	while(running){
		
		renderInstructions.clear();

        controller.update();

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
