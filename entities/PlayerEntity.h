/*
 * PlayerEntity.h
 *
 *  Created on: Feb 24, 2013
 *      Author: joe
 */

#ifndef PLAYERENTITY_H_
#define PLAYERENTITY_H_

#include "GenericEntity.h"
#include "Bullet.h"
#include <vector>

class PlayerEntity : public GenericEntity {
public:
	PlayerEntity();
	PlayerEntity(int initialX, int initalY);
	virtual ~PlayerEntity();

	int handleEvent(SDL_Event event);
	int handleLogic();
	void display(SDL_Surface *destination);
	std::vector<Bullet>* getBullets();

protected:
	static const int SPEED = 5;

	static const int SINGLE_SHOT = 1;
	static const int DOUBLE_SHOT = 2;
	static const int SPREAD_SHOT = 3;

	static const int SHOT_TYPES = 3;

	int currentShotType;

	bool hasDoubleShot;
	bool hasSpreadShot;

	void move();
	void cycleShotType();
	void shoot();

	int xVelocity;
	int yVelocity;

	bool shooting;
	int shootCooldown;
	std::vector<Bullet> bullets;
};

#endif /* PLAYERENTITY_H_ */
