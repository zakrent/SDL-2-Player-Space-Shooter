#ifndef OSIM_PHYSICS
#define OSIM_PHYSICS

#include "Types.h"
#include "Vector2D.h"
#include "../Body.h"
#include <cmath>


long double calculateGravitationalAcceleration(long double distance, uint32 foreignMass);

bool checkForBodyCollision(Body body1, Body body2);

#endif
