#ifndef OSIM_BODY
#define OSIM_BODY

#include <vector>
#include "misc/Types.h"
#include "misc/Vector2D.h"
#include "misc/RenderInstruction.h"
#include <cmath>

class Body{
protected:
	Vector2D position;
	Vector2D lastPos;
	void updatePhysics();
public:
	bool shouldBeDestroyed;
	Vector2D velocity;
	bool isStatic;
	double radius, mass;
	std::vector<Body*>* bodies;

	Vector2D getPos();
	virtual void update() {};
	virtual std::vector<RenderInstruction> getRenderInstructions() {};

	Body(Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies);
};

#endif
