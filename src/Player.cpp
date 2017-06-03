#include "Player.h"
#include "misc/Vector2D.h"
#include <math.h>

Player::Player(Vector2D _position, Vector2D _velocity, uint32 _radius, uint32 _mass, std::vector<Body*>* _bodies) :
	Body(_position, _velocity, _radius, _mass, _bodies), maxAcceleration(0.008), rotation(0){ };

void Player::update(){
	Body::updatePhysics();
}

std::vector<RenderInstruction> Player::getRenderInstructions(){
	std::vector<RenderInstruction> instructions;
	Vector2D TriangleP1(position.x+2*radius*(cos(rotation*M_PI/180)),position.y+2*radius*(sin(rotation*M_PI/180)));
	Vector2D TriangleP2(position.x+radius*(cos((120+rotation)*M_PI/180)),position.y+radius*(sin((120+rotation)*M_PI/180)));
	Vector2D TriangleP3(position.x+radius*(cos((240+rotation)*M_PI/180)),position.y+radius*(sin((240+rotation)*M_PI/180)));	
	instructions.push_back(RenderInstruction(TriangleP1, TriangleP2, 255, 255, 255));
	instructions.push_back(RenderInstruction(TriangleP1, TriangleP3, 255, 255, 255));
	instructions.push_back(RenderInstruction(TriangleP2, TriangleP3, 255, 255, 255));
	return instructions;
}

