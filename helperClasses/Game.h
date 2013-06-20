/*
 * Game.h
 *
 *  Created on: Sep 16, 2012
 *      Author: joe
 */

#ifndef GAME_H_
#define GAME_H_
#include <vector>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"
#include "Timer.h"
#include "../states/GameState.h"

using namespace std;

class Game {
	private:


	public:
	Game();
	virtual ~Game();
	int runGame();
	bool checkCollision( SDL_Rect A, SDL_Rect B );

	protected:
	static const int SCREEN_WIDTH = 420;
	static const int SCREEN_HEIGHT = 400;
	static const int SCREEN_BPP = 32;
	static const int FRAMES_PER_SECOND = 60;

	//The frame rate regulator
	Timer fpsTimer;

	TTF_Font *font;
	SDL_Surface* screen;
	SDL_Event event;

	int stateId;
	int nextState;

	GameState *currentState;

	bool initGraphics();
	bool initAudio();

	void cleanUpGraphics();
	void cleanUpVideo();
	void cleanUpAudio();

	void clearScreen();

	std::string numberToString( int number);
	int stringToNumber( std::string theString );
};

#endif /* GAME_H_ */
