/*
 * LevelOneBoss.cpp
 *
 *  Created on: Jun 18, 2013
 *      Author: joe
 */

#include "LevelOneBoss.h"

LevelOneBoss::LevelOneBoss() {
	// TODO Auto-generated constructor stub

}

LevelOneBoss::LevelOneBoss(int initialX, int initialY){
	GenericEntity::initEntity(initialX, initialY, 100, 40);

	image.loadImage("levelOneBoss.png");

	pointValue = 200;
	currentHP = 5;
	maxHP = 5;

	initialDrop = 50;
}

LevelOneBoss::~LevelOneBoss() {
	// TODO Auto-generated destructor stub
}

void LevelOneBoss::handleLogic(){
	if(initialDrop>=0){
		initialDrop--;
		box.y += SPEED;
	}
	else{
		box.y += SPEED;
	}
}
