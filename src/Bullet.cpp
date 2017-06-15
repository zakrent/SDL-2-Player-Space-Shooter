#include "Bullet.h"

Bullet::Bullet(Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies, bool isInRedTeam) :
	Body(_position, _velocity, _radius, _mass, _bodies) { 
		life = 250;
		this->isGravitySource = false;
		this->isInRedTeam = isInRedTeam;
	};

void Bullet::update(){
	life--;
	if(life <= 0)
		shouldBeDestroyed = true;
	Body::updatePhysics();
}

std::vector<RenderInstruction> Bullet::getRenderInstructions(){
	RenderInstruction inst(position, lastPos,255*isInRedTeam,255*!isInRedTeam,255*!isInRedTeam);
	std::vector<RenderInstruction> retVec;
	retVec.push_back(inst);
	return retVec;
}
