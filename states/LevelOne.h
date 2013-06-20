/*
 * LevelOne.h
 *
 *  Created on: Feb 20, 2013
 *      Author: joe
 */

#ifndef LEVELONE_H_
#define LEVELONE_H_

#include "GameState.h"
#include "GenericLevel.h"
#include "../entities/GenericEntity.h"
#include "../entities/PlayerEntity.h"
#include "../entities/Bullet.h"
#include "../entities/StraightDownEnemy.h"
#include "../entities/SpiralEnemy.h"
#include "../entities/LevelOneBoss.h"

#include "../helperClasses/Image.h"
#include "../helperClasses/TTFText.h"
#include "../helperClasses/Button.h"

#include <vector>

class LevelOne : public GenericLevel {
public:
	static const int LEVEL_WIDTH = 420;
	static const int LEVEL_HEIGHT = 400;

	LevelOne();
	virtual ~LevelOne();

	GameState* getNextState();

protected:
	//Game states
	enum GameStates {
		STATE_NULL,
		STATE_EXIT,
		STATE_GAME
	};

	void spawnEnemies();
};

#endif /* LEVELONE_H_ */
