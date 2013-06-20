/*
 * GenericLevel.h
 *
 *  Created on: Apr 7, 2013
 *      Author: joe
 */

#ifndef GENERICLEVEL_H_
#define GENERICLEVEL_H_

#include "GameState.h"
#include "../entities/GenericEntity.h"
#include "../entities/PlayerEntity.h"
#include "../entities/Bullet.h"
#include "../entities/StraightDownEnemy.h"
#include "../entities/ZigZagEnemy.h"
#include "../entities/Explosion.h"

#include "../helperClasses/Image.h"
#include "../helperClasses/TTFText.h"
#include "../helperClasses/Button.h"


#include <vector>


class GenericLevel : public GameState{
public:
	static const int LEVEL_WIDTH = 420;
	static const int LEVEL_HEIGHT = 400;

	GenericLevel();
	virtual ~GenericLevel();

	void handleEvents();
	void logic();
	void render(SDL_Surface* destination);

	virtual GameState* getNextState() = 0;

	void restart();

protected:
	void drawScoreboard(SDL_Surface *destination);

	int score;
	TTFText scoreText;
	TTFText comboText;

	int lives;
	Image scoreboardShip;

	void keepInBounds(GenericEntity *entity);
	bool checkOutOfBounds(GenericEntity *entity);

	PlayerEntity playerShip;

	Image background;
	int backgroundY;

	void initPauseMenu();
	void drawPauseMenu(SDL_Surface *destination);

	void initStats();

	bool pause;

	Button resume;
	Button pauseQuit;
	Button restartButton;
	TTFText pauseText;

	std::vector<GenericEnemy*> enemies;
	std::vector<Explosion*> explosions;
	virtual void spawnEnemies() = 0;
	int enemySpawnTimer;
};

#endif /* GENERICLEVEL_H_ */
