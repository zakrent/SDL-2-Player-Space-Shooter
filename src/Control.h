#ifndef OSIM_CONTROL
#define OSIM_CONTROL

#include "Player.h"

class Control{
public:
	Player* controlerPlayer;
	int controlScheme;
	void update();
	Control(int _controlScheme) : controlScheme(_controlScheme) {};
};	

#endif
