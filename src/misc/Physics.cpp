#include "Physics.h"

long double calculateGravitationalAcceleration(long double distance, uint32 foreignMass){
	long double gravConst = 0.1;
	return (gravConst*foreignMass)/(distance*distance);
}

bool checkForBodyCollision(Body body1, Body body2){
	long double distance = sqrt(pow(body1.getPos().x - body2.getPos().x, 2.0) + pow(body1.getPos().y - body2.getPos().y, 2.0));
	return (body1.radius+body2.radius) > distance;
}
