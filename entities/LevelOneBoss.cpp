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

LevelOneBoss::LevelOneBoss(int initialX, int initialY, int levelWidth){
	GenericEntity::initEntity(initialX, initialY, 100, 40);

	image.loadImage("levelOneBoss.png");

	pointValue = 200;
	currentHP = 5;
	maxHP = 5;

	initialDrop = 50;

	goingRight = true;
	scrollLimit = levelWidth;

	shotCooldown = 15;

	bullets = std::vector<Bullet>();
}

LevelOneBoss::~LevelOneBoss() {
	// TODO Auto-generated destructor stub
}

void LevelOneBoss::handleLogic(){
	move();
	shoot();

	for(unsigned int i=0; i<bullets.size(); i++){
		bullets.at(i).handleLogic();
	}
}

void LevelOneBoss::move(){
	if(initialDrop>=0){
		initialDrop--;
		box.y += SPEED;
	}
	else{
		if(goingRight){
			box.x += SPEED;
			if((box.x + box.w) > scrollLimit){
				box.x = scrollLimit - box.w;
				goingRight = false;
			}
		}
		else{
			box.x -= SPEED;
			if(box.x < 0){
				box.x = 0;
				goingRight = true;
			}
		}
	}
}

void LevelOneBoss::shoot(){
	if(shotCooldown<=0 && initialDrop<=0){
		bullets.push_back(Bullet(box.x+50, box.y+40, 0, 10));
		shotCooldown = 50;
	}
	else{
		shotCooldown--;
	}
}


