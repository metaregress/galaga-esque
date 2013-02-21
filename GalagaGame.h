/*
 * GalagaGame.h
 *
 *  Created on: Feb 19, 2013
 *      Author: joe
 */

#ifndef GALAGAGAME_H_
#define GALAGAGAME_H_

#include "helperClasses/Game.h"

class GalagaGame : public Game{
public:
	GalagaGame();
	virtual ~GalagaGame();

protected:
	//Game states
	enum GameStates {
		STATE_NULL,
		STATE_EXIT,
		STATE_TITLE,
		STATE_LEVEL_1,
		STATE_GAME_OVER,
	};

};

#endif /* GALAGAGAME_H_ */
