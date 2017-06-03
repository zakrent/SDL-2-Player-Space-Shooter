#ifndef OSIM_CONTROL
#define OSIM_CONTROL

#include "Player.h"

class Control{
public:
	Player* controlerPlayer;
	int controlScheme;
	void update();
};	

#endif
