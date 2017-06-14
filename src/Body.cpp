#include "Body.h"
#include <stdlib.h>
#include "misc/Physics.h"

Body::Body(Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies)
: radius(_radius), mass(_mass), position(_position), velocity(_velocity), bodies(_bodies), lastPos(_position) {
	isStatic = false;
	shouldBeDestroyed = false;
}

void Body::updatePhysics(){
	lastPos = position;
	if(isStatic)
		return;
	for(int i = 0; i < 100; i++){
		for(Body* body : *bodies) {
			if (body->getPos() == position)
				continue;
			long double distance = sqrt(pow(position.x - body->getPos().x, 2.0) + pow(position.y - body->getPos().y, 2.0));
			Vector2D gravVec = (body->getPos() - position);
			gravVec.normalize();
			gravVec *= calculateGravitationalAcceleration(distance, body->mass);
			velocity += gravVec*0.01;
			if(checkForBodyCollision(*this, *body) && mass < body->mass)
				shouldBeDestroyed = true;
		}
		position += velocity*0.01;
	}
}

Vector2D Body::getPos() {
	return position;
}
	
//std::vector<RenderInstruction> Body::getRenderInstructions(){
//	RenderInstruction inst(position, lastPos,(abs(velocity.x)+abs(velocity.y))*1.5, 50 ,255-((abs(velocity.x)+abs(velocity.y))*1.5));
//	std::vector<RenderInstruction> retVec;
	//retVec.push_back(inst);
//	return retVec;
//}
