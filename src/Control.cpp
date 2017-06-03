#include "Control.h"
#include <math.h>
#include "misc/Vector2D.h"
#include <SDL.h>

void Control::update() {
	if (!controlerPlayer)
		return;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_D])
		controlerPlayer->rotation += 2;
	if (state[SDL_SCANCODE_A])
		controlerPlayer->rotation -= 2;

	if (state[SDL_SCANCODE_W] || state[SDL_SCANCODE_S]) {
		Vector2D velVect(0, 0);
		velVect.x = cos(controlerPlayer->rotation * M_PI / 180);
		velVect.y = sin(controlerPlayer->rotation * M_PI / 180);
		velVect *= controlerPlayer->maxAcceleration;
		if (state[SDL_SCANCODE_S])
			velVect *= -1;
		controlerPlayer->velocity += velVect;
	}
}
