/*
 * StraightDownEnemy.h
 *
 *  Created on: Feb 25, 2013
 *      Author: joe
 */

#ifndef STRAIGHTDOWNENEMY_H_
#define STRAIGHTDOWNENEMY_H_

#include "GenericEnemy.h"

class StraightDownEnemy : public GenericEnemy {
public:
	StraightDownEnemy();
	StraightDownEnemy(int initialX, int initialY);
	virtual ~StraightDownEnemy();

	void handleLogic();

protected:
	static const int SPEED = 3;
};

#endif /* STRAIGHTDOWNENEMY_H_ */
