#include "Player.h"
#include "misc/Vector2D.h"
#include <math.h>
#include "Bullet.h"
#include <SDL.h>

Player::Player(Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies, bool isInRedTeam) :
	Body(_position, _velocity, _radius, _mass, _bodies), maxAcceleration(0.008), rotation(0), isInRedTeam(isInRedTeam){ 
		lastShotTime = 0;	
	};

void Player::update(){
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
	if (!SDL_TICKS_PASSED(SDL_GetTicks(), lastShotTime + 50)) {
		return;
	}
	lastShotTime = SDL_GetTicks();
	Vector2D bulVel(0,0); 
	bulVel.x = cos(rotation * M_PI / 180);
	bulVel.y = sin(rotation * M_PI / 180);
	bulVel.normalize();
	bulVel *= 4;
	bulVel += velocity;
	Vector2D bulPos = this->getPos();
	bulPos += bulVel*2;
	bodies->push_back(new Bullet(bulPos, bulVel, 1, 0.0002, bodies, isInRedTeam)); 
}
