#include "Control.h" 
#include <math.h>
#include "misc/Vector2D.h"
#include <SDL.h>

void Control::update() {
	if (!controlerPlayer)
		return;
	if(controlerPlayer->shouldBeDestroyed)
		controlerPlayer = NULL;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	bool accelererate = (state[SDL_SCANCODE_W] && controlScheme == 0) || 
		(state[SDL_SCANCODE_UP] && controlScheme == 1); 
	bool deccelerate  = (state[SDL_SCANCODE_S] && controlScheme == 0) || 
		(state[SDL_SCANCODE_DOWN] && controlScheme == 1); 
	bool left  = (state[SDL_SCANCODE_A] && controlScheme == 0) || 
		(state[SDL_SCANCODE_LEFT] && controlScheme == 1); 
	bool right = (state[SDL_SCANCODE_D] && controlScheme == 0) || 
		(state[SDL_SCANCODE_RIGHT] && controlScheme == 1); 
	if (right)
		controlerPlayer->rotation += 2;
	if (left)
		controlerPlayer->rotation -= 2;

	if (accelererate || deccelerate) {
		Vector2D velVect(0, 0);
		velVect.x = cos(controlerPlayer->rotation * M_PI / 180);
		velVect.y = sin(controlerPlayer->rotation * M_PI / 180);
		velVect *= controlerPlayer->maxAcceleration;
		if (deccelerate)
			velVect *= -1;
		controlerPlayer->velocity += velVect;
	}
}
