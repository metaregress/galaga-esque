/*
 * SpiralEnemy.cpp
 *
 *  Created on: Apr 8, 2013
 *      Author: joe
 */

#include "SpiralEnemy.h"

SpiralEnemy::SpiralEnemy() {
	// TODO Auto-generated constructor stub

}

SpiralEnemy::SpiralEnemy(int initialX, int initialY){
	GenericEntity::initEntity(initialX, initialY, 20, 20);

	image.loadImage("spiralEnemy.png");

	pointValue = 20;
	currentHP = 1;
	maxHP = 1;

	circleTimer = 0;

	initialDrop = 50;

	bullets = std::vector<Bullet>();
}

SpiralEnemy::~SpiralEnemy() {
	// TODO Auto-generated destructor stub
}

void SpiralEnemy::handleLogic(){
	circleTimer ++;
	if(initialDrop>=0){
		initialDrop--;
		box.y += SPEED;
	}
	else{

		if(circleTimer>=45){
			box.x += SPEED;
			box.y -= SPEED;
		}
		else if(circleTimer >=35){
			box.x -= SPEED;
			box.y -= SPEED;
		}
		else if(circleTimer >= 15){
			box.x -= SPEED;
			box.y += SPEED;
		}
		else{
			box.x += SPEED;
			box.y += SPEED;
		}
		circleTimer++;
		if(circleTimer>=60){
			circleTimer = 0;
		}
	}
}
