/*
 * Title.h
 *
 *  Created on: Feb 20, 2013
 *      Author: joe
 */

#ifndef TITLE_H_
#define TITLE_H_

#include "GameState.h"
#include "LevelOne.h"
#include "SDL/SDL_mixer.h"
#include "../helperClasses/TTFText.h"
#include "../helperClasses/Button.h"
#include "../helperClasses/SelectionList.h"

class Title : public GameState {
public:
	Title();
	virtual ~Title();

	void handleEvents();
	void logic();
	void render(SDL_Surface* destination);

	GameState* getNextState();

protected:
	//Game states
	enum GameStates {
		STATE_NULL,
		STATE_EXIT,
		STATE_GAME
	};

	TTFText titleText;
	Button playGame;
	Button quitButton;
	SelectionList titleOptions;

	Mix_Chunk *startSound;
};

#endif /* TITLE_H_ */
