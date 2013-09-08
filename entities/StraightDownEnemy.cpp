/*
 * StraightDownEnemy.cpp
 *
 *  Created on: Feb 25, 2013
 *      Author: joe
 */

#include "StraightDownEnemy.h"

StraightDownEnemy::StraightDownEnemy() {
	// TODO Auto-generated constructor stub

}

StraightDownEnemy::StraightDownEnemy(int initialX, int initialY){
	GenericEntity::initEntity(initialX, initialY, 20, 20);

	image.loadImage("straightDownEnemy.png");

	pointValue = 10;
	currentHP = 1;
	maxHP = 1;

	bullets = std::vector<Bullet>();
}

StraightDownEnemy::~StraightDownEnemy() {
	// TODO Auto-generated destructor stub
}

void StraightDownEnemy::handleLogic(){
	box.y += SPEED;
}
