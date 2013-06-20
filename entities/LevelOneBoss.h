/*
 * LevelOneBoss.h
 *
 *  Created on: Jun 18, 2013
 *      Author: joe
 */

#ifndef LEVELONEBOSS_H_
#define LEVELONEBOSS_H_

#include "GenericEnemy.h"

class LevelOneBoss : public GenericEnemy{
public:
	LevelOneBoss();
	LevelOneBoss(int initialX, int initialY);
	virtual ~LevelOneBoss();

	void handleLogic();

protected:
	static const int SPEED=1;
	int initialDrop;
};

#endif /* LEVELONEBOSS_H_ */
