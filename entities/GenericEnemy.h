/*
 * GenericEnemy.h
 *
 *  Created on: Mar 4, 2013
 *      Author: joe
 */

#ifndef GENERICENEMY_H_
#define GENERICENEMY_H_

#include "GenericEntity.h"
#include "Bullet.h"
#include <vector>

class GenericEnemy : public GenericEntity {
public:
	GenericEnemy();
	virtual ~GenericEnemy();

	virtual void handleLogic() = 0;

	bool damage(int amount);

	int getPointValue();
	int getMaxHP();
	int getCurrentHP();

	std::vector<Bullet>* getBullets();
	void display(SDL_Surface* destination);


protected:
	int pointValue;
	int currentHP;
	int maxHP;
	std::vector<Bullet> bullets;
};

#endif /* GENERICENEMY_H_ */
