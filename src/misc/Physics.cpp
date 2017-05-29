#include "Physics.h"

long double calculateGravitationalAcceleration(long double distance, uint32 foreignMass){
	long double gravConst = 0.1;
	return (gravConst*foreignMass)/(distance*distance);
}
