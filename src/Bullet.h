#ifndef OSIM_BULLET
#define OSIM_BULLET

#include "Body.h"

class Bullet : public Body{
private:
	int life;
public:
	bool isInRedTeam;
	void update();
	std::vector<RenderInstruction> getRenderInstructions();

	Bullet( Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies, bool isInRedTeam);
	~Bullet() {};
};

#endif
