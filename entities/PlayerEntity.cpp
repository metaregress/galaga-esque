/*
 * PlayerEntity.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: joe
 */

#include "PlayerEntity.h"

PlayerEntity::PlayerEntity() {


}

PlayerEntity::PlayerEntity(int initialX, int initialY){
	GenericEntity::initEntity(initialX, initialY, 19, 18);

	xVelocity = 0;
	yVelocity = 0;

	shooting = false;
	shootCooldown = 0;

	bullets = std::vector<Bullet>();

	currentShotType = SINGLE_SHOT;

	hasDoubleShot = true;
	hasSpreadShot = true;

	invincibility = false;
	invincibilityTimer = 0;
	invincibilityBlinkTimer = 0;

	image.loadImage("playerShip.png");

	shootSound = SoundEffect("high.wav");

	combo = 1;
}

PlayerEntity::~PlayerEntity() {
	// TODO Auto-generated destructor stub
}

void PlayerEntity::display(SDL_Surface *destination){
	if(invincibility){
		invincibilityBlinkTimer++;
	}
	if(invincibility && invincibilityBlinkTimer>=10){
		image.displayImage(box.x, box.y, destination);
	}
	if(invincibility && invincibilityBlinkTimer>=20){
		invincibilityBlinkTimer=0;
	}
	if(!invincibility){
		image.displayImage(box.x, box.y, destination);
	}

	for(unsigned int i=0; i<bullets.size(); i++){
		bullets.at(i).display(destination);
	}
}

int PlayerEntity::handleEvent(SDL_Event event){
	//If a key was pressed
	if(event.type==SDL_KEYDOWN){
		if(event.key.keysym.sym==SDLK_LEFT){
			xVelocity -= SPEED;
		}
		if(event.key.keysym.sym==SDLK_RIGHT){
			xVelocity += SPEED;
		}
		if(event.key.keysym.sym==SDLK_UP){
			yVelocity -= SPEED;
		}
		if(event.key.keysym.sym==SDLK_DOWN){
			yVelocity += SPEED;
		}
		if(event.key.keysym.sym==SDLK_z){
			cycleShotType();
		}
		if(event.key.keysym.sym==SDLK_SPACE){
			shoot();
		}

	}
	//If a key was released
	else if( event.type == SDL_KEYUP ) {
		//Adjust the velocity
		if(event.key.keysym.sym==SDLK_LEFT){
			xVelocity += SPEED;
		}
		if(event.key.keysym.sym==SDLK_RIGHT){
			xVelocity -= SPEED;
		}
		if(event.key.keysym.sym==SDLK_UP){
			yVelocity += SPEED;
		}
		if(event.key.keysym.sym==SDLK_DOWN){
			yVelocity -= SPEED;
		}
	}
	return 1;
}

int PlayerEntity::handleLogic(){
	for(unsigned int i=0; i<bullets.size(); i++){
		bullets.at(i).handleLogic();
	}
	move();
	if(shooting){
		shootCooldown++;
		if(shootCooldown == 15){
			shootCooldown = 0;
			shooting = false;
		}
	}

	if(invincibility){
		invincibilityTimer--;
		if(invincibilityTimer<=0){
			invincibility = false;
		}
	}

	return 1;
}

void PlayerEntity::move(){
	box.x += xVelocity;
	box.y += yVelocity;
}

void PlayerEntity::cycleShotType(){
	currentShotType++;
	if(currentShotType>SHOT_TYPES){
		currentShotType=1;
	}
}

void PlayerEntity::shoot(){
	if(!shooting){
		if(currentShotType==SINGLE_SHOT){
			bullets.push_back(Bullet(box.x+9, box.y-5, 0, -10));
		}
		else if(currentShotType==DOUBLE_SHOT){
			bullets.push_back(Bullet(box.x+2, box.y-5, 0, -10));
			bullets.push_back(Bullet(box.x+15, box.y-5, 0, -10));
		}
		else if(currentShotType==SPREAD_SHOT){
			bullets.push_back(Bullet(box.x+9, box.y-5, -10, -10));
			bullets.push_back(Bullet(box.x+9, box.y-5, 0, -10));
			bullets.push_back(Bullet(box.x+9, box.y-5, 10, -10));
		}
		shootSound.play();
		shooting = true;
	}
}

std::vector<Bullet>* PlayerEntity::getBullets(){
	return &bullets;
}

void PlayerEntity::setInvincibility(bool value, int duration){
	invincibility = value;
	invincibilityTimer = duration;
}

bool PlayerEntity::getInvincibility(){
	return invincibility;
}

int PlayerEntity::getCombo(){
	return combo;
}

void PlayerEntity::setCombo(int amount){
	combo = amount;
}
