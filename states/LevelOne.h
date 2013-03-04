/*
 * LevelOne.h
 *
 *  Created on: Feb 20, 2013
 *      Author: joe
 */

#ifndef LEVELONE_H_
#define LEVELONE_H_

#include "GameState.h"
#include "../entities/GenericEntity.h"
#include "../entities/PlayerEntity.h"
#include "../entities/Bullet.h"
#include "../entities/StraightDownEnemy.h"

#include "../helperClasses/Image.h"
#include "../helperClasses/TTFText.h"

#include <vector>

class LevelOne : public GameState {
public:
	static const int LEVEL_WIDTH = 420;
	static const int LEVEL_HEIGHT = 400;

	LevelOne();
	virtual ~LevelOne();

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

	void drawScoreboard(SDL_Surface *destination);

	int score;

	int lives;
	Image scoreboardShip;

	void keepInBounds(GenericEntity *entity);
	bool checkOutOfBounds(GenericEntity entity);

	PlayerEntity playerShip;

	Image background;
	int backgroundY;

	std::vector<GenericEnemy> enemies;
};

#endif /* LEVELONE_H_ */
