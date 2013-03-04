/*
 * Bullet.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: joe
 */

#include "Bullet.h"

Bullet::Bullet() {
	// TODO Auto-generated constructor stub

}

Bullet::Bullet(int xPosition, int yPosition, int initialXVelocity, int initialYVelocity){
	GenericEntity::initEntity(xPosition, yPosition, 5, 5);

	xVelocity = initialXVelocity;
	yVelocity = initialYVelocity;

	image.loadImage("bullet.png");
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

int Bullet::handleLogic(){
	move();
}

void Bullet::move(){
	box.x += xVelocity;
	box.y += yVelocity;
}
