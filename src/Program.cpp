#include "Program.h"

Program::Program() : controller1(0), controller2(1){
	bodies.push_back(new Planet(Vector2D(600,300),Vector2D(0,0),5,1800,&bodies));
	bodies.back()->isStatic = true;
	bodies.push_back(new Planet(Vector2D(900,300),Vector2D(0,-0.775),2,50,&bodies));
	bodies.push_back(new Planet(Vector2D(500,300),Vector2D(0,1.34),3,100,&bodies));
	controller1.controlerPlayer = NULL;
	controller2.controlerPlayer = NULL;
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

		controller1.update();
		controller2.update();
			
		for(int i = 0; i < bodies.size(); ++i){
			Body* body = bodies[i];
			if(body->shouldBeDestroyed){
				delete body;
				body=NULL;
				bodies.erase(bodies.begin()+i);
				continue;
			}
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

		if(controller1.controlerPlayer == NULL){
			Player* tempP1 = new Player(Vector2D(400,300),Vector2D(0,0.95),2,0.0001,&bodies, true);
			controller1.controlerPlayer = tempP1;
			bodies.push_back(tempP1);
		}
		if(controller2.controlerPlayer == NULL){
			Player* tempP2 = new Player(Vector2D(800,300),Vector2D(0,-0.95),2,0.0001,&bodies, false);
			controller2.controlerPlayer = tempP2;
			bodies.push_back(tempP2);
		}

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
