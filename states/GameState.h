/*
 * GameState.h
 *
 *  Created on: Feb 19, 2013
 *      Author: joe
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "SDL/SDL.h"

#include <vector>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

class GameState {
public:
	GameState();
	virtual ~GameState();

	virtual void handleEvents() = 0;
	virtual void logic() = 0;
	virtual void render(SDL_Surface* destination) = 0; //may need to pass this the screen...

	virtual GameState* getNextState() = 0;

	bool checkCollision( SDL_Rect A, SDL_Rect B );
	void clearScreen(SDL_Surface *destination);

protected:
	//Game states
	enum GameStates {
		STATE_NULL,
		STATE_EXIT,
	};

	int nextState;

	SDL_Event event;

	std::string numberToString( int number);
	int stringToNumber( std::string theString );
};

#endif /* GAMESTATE_H_ */
