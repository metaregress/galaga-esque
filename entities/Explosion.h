/*
 * Explosion.h
 *
 *  Created on: May 26, 2013
 *      Author: joe
 */

#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "GenericEntity.h"

class Explosion : public GenericEntity {
public:
	Explosion();
	Explosion(int xPosition, int yPosition);
	virtual ~Explosion();
	void display(SDL_Surface *destination);
	bool getExpired();

private:
	void setClips();
	int frameCounter;
	int timer;
	SDL_Rect explosionFrames[3];
	bool expired;
};

#endif /* EXPLOSION_H_ */
