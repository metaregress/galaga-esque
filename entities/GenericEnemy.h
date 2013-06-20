/*
 * GenericEnemy.h
 *
 *  Created on: Mar 4, 2013
 *      Author: joe
 */

#ifndef GENERICENEMY_H_
#define GENERICENEMY_H_

#include "GenericEntity.h"

class GenericEnemy : public GenericEntity {
public:
	GenericEnemy();
	virtual ~GenericEnemy();

	virtual void handleLogic() = 0;

	bool damage(int amount);

	int getPointValue();
	int getMaxHP();
	int getCurrentHP();


protected:
	int pointValue;
	int currentHP;
	int maxHP;
};

#endif /* GENERICENEMY_H_ */
