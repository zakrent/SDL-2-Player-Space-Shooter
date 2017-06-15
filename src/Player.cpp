#include "Player.h"
#include "misc/Vector2D.h"
#include <math.h>
#include "Bullet.h"
#include <SDL.h>

Player::Player(Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies, bool isInRedTeam) :
	Body(_position, _velocity, _radius, _mass, _bodies), maxAcceleration(0.006), rotation(0), isInRedTeam(isInRedTeam) { 
		cannonHeat = 0;
		cannonDelayActive = false;
	};

void Player::update(){
	if(!cannonActive){
		cannonHeat -= 0.2;
		if(cannonHeat <= 0)
			cannonActive = true;
	}
	cannonDelayActive = !cannonDelayActive;
	Body::updatePhysics();
}

std::vector<RenderInstruction> Player::getRenderInstructions(){
	std::vector<RenderInstruction> instructions;
	Vector2D TriangleP1(position.x+2*radius*(cos(rotation*M_PI/180)),position.y+2*radius*(sin(rotation*M_PI/180)));
	Vector2D TriangleP2(position.x+radius*(cos((120+rotation)*M_PI/180)),position.y+radius*(sin((120+rotation)*M_PI/180)));
	Vector2D TriangleP3(position.x+radius*(cos((240+rotation)*M_PI/180)),position.y+radius*(sin((240+rotation)*M_PI/180)));	
	int redCol = 255 * isInRedTeam;
	int greCol = 255 * !isInRedTeam;
	int bluCol = 255 * !isInRedTeam;
	instructions.push_back(RenderInstruction(TriangleP1, TriangleP2, redCol, greCol, bluCol));
	instructions.push_back(RenderInstruction(TriangleP1, TriangleP3, redCol, greCol, bluCol));
	instructions.push_back(RenderInstruction(TriangleP2, TriangleP3, redCol, greCol, bluCol));
	return instructions;
}

void Player::shoot(){
	if(cannonHeat > 20 || !cannonActive){
		cannonActive = false;
		return;
	}
	if(cannonDelayActive)
		return;
	cannonHeat += 2;
	Vector2D bulVel(0,0); 
	bulVel.x = cos(rotation * M_PI / 180);
	bulVel.y = sin(rotation * M_PI / 180);
	bulVel.normalize();
	bulVel *= 3;
	bulVel += velocity;
	Vector2D bulPos = this->getPos();
	bulPos += bulVel*3;
	bodies->push_back(new Bullet(bulPos, bulVel, 1, 0.0002, bodies, isInRedTeam)); 
}
