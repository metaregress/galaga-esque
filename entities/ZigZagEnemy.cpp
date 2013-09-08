/*
 * ZigZagEnemy.cpp
 *
 *  Created on: Apr 8, 2013
 *      Author: joe
 */

#include "ZigZagEnemy.h"

ZigZagEnemy::ZigZagEnemy() {
	// TODO Auto-generated constructor stub

}

ZigZagEnemy::ZigZagEnemy(int initialX, int initialY){
	GenericEntity::initEntity(initialX, initialY, 20, 20);

	image.loadImage("zigZagEnemy.png");

	pointValue = 15;
	currentHP = 1;
	maxHP = 1;
	zigCounter = 0;

	bullets = std::vector<Bullet>();
}

ZigZagEnemy::~ZigZagEnemy() {
	// TODO Auto-generated destructor stub
}

void ZigZagEnemy::handleLogic(){
	zigCounter++;
	if(zigCounter>40){
		box.y += SPEED;
		box.x += SPEED;
	}
	else{
		box.y += SPEED;
		box.x -= SPEED;
	}
	if(zigCounter>80){
		zigCounter = 0;
	}
}
