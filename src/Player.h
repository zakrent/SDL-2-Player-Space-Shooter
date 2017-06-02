#ifndef OSIM_PLAYER
#define OSIM_PLAYER

#include "Body.h"
#include "Player.h"

class Player : public Body{
public:
	int rotation;
	void update();
	std::vector<RenderInstruction> getRenderInstructions();

	Player( Vector2D _position, Vector2D _velocity, uint32 _radius, uint32 _mass, std::vector<Body*>* _bodies );
	~Player() {};
};	

#endif
