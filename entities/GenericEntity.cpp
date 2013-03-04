/*
 * GenericEntity.cpp
 *
 *  Created on: Jan 27, 2013
 *      Author: joe
 */

#include "GenericEntity.h"

GenericEntity::GenericEntity() {


}

GenericEntity::~GenericEntity() {
	// TODO Auto-generated destructor stub
}

void GenericEntity::initEntity(int startingX, int startingY, int width, int height){

	box.x = startingX;
	box.y = startingY;
	box.w = width;
	box.h = height;

	image = Image();
}

int GenericEntity::getX(){
	return box.x;
}

int GenericEntity::getY(){
	return box.y;
}

void GenericEntity::setCoords(int x, int y){
	box.x = x;
	box.y = y;
}

void GenericEntity::display(SDL_Surface *destination){
	image.displayImage(box.x, box.y, destination);
}

SDL_Rect GenericEntity::getRect(){
	return box;
}

int GenericEntity::handleEvent(SDL_Event event){
	return 1;
}
