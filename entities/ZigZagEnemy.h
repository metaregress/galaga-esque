/*
 * ZigZagEnemy.h
 *
 *  Created on: Apr 8, 2013
 *      Author: joe
 */

#ifndef ZIGZAGENEMY_H_
#define ZIGZAGENEMY_H_

#include "GenericEnemy.h"

class ZigZagEnemy : public GenericEnemy {
public:
	ZigZagEnemy();
	ZigZagEnemy(int initialX, int initialY);
	virtual ~ZigZagEnemy();

	void handleLogic();
protected:
	static const int SPEED = 2;
	int zigCounter;
};

#endif /* ZIGZAGENEMY_H_ */
