/*
 * Explosion.cpp
 *
 *  Created on: May 26, 2013
 *      Author: joe
 */

#include "Explosion.h"

Explosion::Explosion() {
	// TODO Auto-generated constructor stub

}

Explosion::Explosion(int initialX, int initialY){
	GenericEntity::initEntity(initialX, initialY, 20, 20);

	image.loadImage("explosion-sprites.png");

	setClips();

	frameCounter = 0;
	timer = 0;
}

Explosion::~Explosion() {
	// TODO Auto-generated destructor stub
}

void Explosion::display(SDL_Surface *destination){
	if(timer >=10){
		frameCounter++;
		timer=0;
	}
	if(frameCounter>=2){
		frameCounter = 0; //really I want to stop here
		expired = true;
	}

	image.displayImage(box.x, box.y, destination, &explosionFrames[frameCounter]);

	timer++;
}

void Explosion::setClips(){
	explosionFrames[0].x = 0;
	explosionFrames[0].y = 0;
	explosionFrames[0].w = 20;
	explosionFrames[0].h = 20;

	explosionFrames[1].x = 20;
	explosionFrames[1].y = 0;
	explosionFrames[1].w = 20;
	explosionFrames[1].h = 20;

	explosionFrames[2].x = 40;
	explosionFrames[2].y = 0;
	explosionFrames[2].w = 20;
	explosionFrames[2].h = 20;
}

bool Explosion::getExpired(){
	return expired;
}
