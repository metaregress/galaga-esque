/*
 * Bullet.h
 *
 *  Created on: Feb 24, 2013
 *      Author: joe
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "GenericEntity.h"

class Bullet : public GenericEntity {
public:
	Bullet();
	Bullet(int xPosition, int yPosition, int initialXVelocity, int initialYVelocity);
	virtual ~Bullet();

	int handleLogic();

protected:
	void move();
	int xVelocity;
	int yVelocity;
};

#endif /* BULLET_H_ */
