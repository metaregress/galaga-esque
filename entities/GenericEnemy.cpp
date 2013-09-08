/*
 * GenericEnemy.cpp
 *
 *  Created on: Mar 4, 2013
 *      Author: joe
 */

#include "GenericEnemy.h"

GenericEnemy::GenericEnemy() {
	// TODO Auto-generated constructor stub

}

GenericEnemy::~GenericEnemy() {
	// TODO Auto-generated destructor stub
}

int GenericEnemy::getPointValue(){
	return pointValue;
}


/**
 * Function returns true if the damage was enough to destroy the enemy.
 */
bool GenericEnemy::damage(int amount){
	currentHP -= amount;
	if(currentHP <= 0){
		return true;
	}

	return false;

}

int GenericEnemy::getMaxHP(){
	return maxHP;
}

int GenericEnemy::getCurrentHP(){
	return currentHP;
}

std::vector<Bullet>* GenericEnemy::getBullets(){
	return &bullets;
}

void GenericEnemy::display(SDL_Surface *destination){
	image.displayImage(box.x, box.y, destination);

	for(unsigned int i=0; i<bullets.size(); i++){
		bullets.at(i).display(destination);
	}
}



