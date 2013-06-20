/*
 * SpiralEnemy.h
 *
 *  Created on: Apr 8, 2013
 *      Author: joe
 */

#ifndef SPIRALENEMY_H_
#define SPIRALENEMY_H_

#include "GenericEnemy.h"

class SpiralEnemy : public GenericEnemy{
public:
	SpiralEnemy();
	SpiralEnemy(int initialX, int initialY);
	virtual ~SpiralEnemy();

	void handleLogic();

protected:
	static const int SPEED=2;
	int horizontalTimer;
	int verticalTimer;
	int circleTimer;
	int initialDrop; //this gives it enough space into the level so it doesn't go out of bounds
};

#endif /* SPIRALENEMY_H_ */
