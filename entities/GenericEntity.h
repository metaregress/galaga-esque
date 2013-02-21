/*
 * GenericEntity.h
 *
 *  Created on: Jan 27, 2013
 *      Author: joe
 */

#ifndef GENERICENTITY_H_
#define GENERICENTITY_H_

#include "SDL/SDL.h"
#include "../helperClasses/Image.h"

class GenericEntity {
public:
	GenericEntity();
	virtual ~GenericEntity();

	void initEntity(int startingX, int startingY, int width, int height);

	void display(SDL_Surface* display);
	int handleEvent(SDL_Event event);

	SDL_Rect getRect();
	int getX();
	int getY();
	void setCoords(int x, int y);

protected:
	SDL_Rect box; //used for keeping track of the entity's position and collisions
	Image image;
};

#endif /* GENERICENTITY_H_ */
