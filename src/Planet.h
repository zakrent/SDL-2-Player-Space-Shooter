#ifndef OSIM_PLANET
#define OSIM_PLANET

#include "Body.h"

class Planet : public Body{
public:
	void update();
	std::vector<RenderInstruction> getRenderInstructions();

	Planet( Vector2D _position, Vector2D _velocity, uint32 _radius, uint32 _mass, std::vector<Body*>* _bodies );
	~Planet() {};
};	

#endif
