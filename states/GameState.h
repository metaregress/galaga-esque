/*
 * GameState.h
 *
 *  Created on: Feb 19, 2013
 *      Author: joe
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "SDL/SDL.h"

class GameState {
public:
	GameState();
	virtual ~GameState();

	virtual void handleEvents() = 0;
	virtual void logic() = 0;
	virtual void render() = 0; //may need to pass this the screen...

	virtual GameState* getNextState() = 0;

	bool checkCollision( SDL_Rect A, SDL_Rect B );
};

#endif /* GAMESTATE_H_ */
