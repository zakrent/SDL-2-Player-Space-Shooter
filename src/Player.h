#ifndef OSIM_PLAYER
#define OSIM_PLAYER

#include "Body.h"
#include "Player.h"

class Player : public Body{
public:
	double maxAcceleration;
	int rotation;
	void update();
	std::vector<RenderInstruction> getRenderInstructions();

	Player( Vector2D _position, Vector2D _velocity, double _radius, double _mass, std::vector<Body*>* _bodies );
	~Player() {};
};	

#endif
