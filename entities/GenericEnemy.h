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
};

#endif /* GENERICENEMY_H_ */
