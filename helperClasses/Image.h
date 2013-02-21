/*
 * Image.h
 *
 *  Created on: Aug 30, 2012
 *      Author: joe
 */

#ifndef Image_H_
#define Image_H_
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

class Image {
public:
	Image();
	virtual ~Image();
	void loadImage( std::string filename );
	void displayImage( int x, int y, SDL_Surface* destination, SDL_Rect* clip=NULL );
	void freeImage();

private:
	SDL_Rect box;
	SDL_Surface* finalImage;
	std::string filename;

};

#endif /* Image_H_ */
