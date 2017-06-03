#include "Planet.h"
#include "misc/Vector2D.h"
#include <math.h>

Planet::Planet(Vector2D _position, Vector2D _velocity, uint32 _radius, uint32 _mass, std::vector<Body*>* _bodies) :
        Body(_position, _velocity, _radius, _mass, _bodies) {};

void Planet::update(){
	Body::updatePhysics();
}

std::vector<RenderInstruction> Planet::getRenderInstructions(){
	std::vector<RenderInstruction> instructions;
	Vector2D currentPos(position.x + (cos(0) * radius),position.y + (sin(0) * radius));
	RenderInstruction currentInstr(Vector2D(0,0),Vector2D(0,0),0,0,0);
	for(int i = 0; i<=360; i += 10){
		currentInstr.startPos = currentPos;
		currentPos.x = position.x + (cos(i*M_PI/180) * radius);
		currentPos.y = position.y + (sin(i*M_PI/180) * radius);
		currentInstr.endPos = currentPos;
		currentInstr.colG = int(mass)/10 % 255;
		currentInstr.colB = 255;
		currentInstr.colR = int(mass)/10 % 255;
		instructions.push_back(currentInstr);
	}
    return instructions;
}

