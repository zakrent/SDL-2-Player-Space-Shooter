#include "Bullet.h"

Bullet::Bullet(Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies) :
	Body(_position, _velocity, _radius, _mass, _bodies) { 
		life = 100;
	};

void Bullet::update(){
	life--;
	if(life <= 0)
		shouldBeDestroyed = true;
	Body::updatePhysics();
}

std::vector<RenderInstruction> Bullet::getRenderInstructions(){
	RenderInstruction inst(position, lastPos,(std::abs(velocity.x)+std::abs(velocity.y))*1.5, 50 ,255-((std::abs(velocity.x)+std::abs(velocity.y))*1.5));
	std::vector<RenderInstruction> retVec;
	retVec.push_back(inst);
	return retVec;
}
