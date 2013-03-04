/*
 * Image.cpp
 *
 * Individual image file; can render itself if passed a surface.
 *
 *  Created on: Aug 30, 2012
 *      Author: joe
 */

#include "Image.h"
using namespace std;

Image::Image() {

}

Image::~Image() {
}

void Image::loadImage( std::string filename ){
	//image to load
	SDL_Surface* loadedImage = NULL;

	//optimized image to return
	SDL_Surface* optimizedImage = NULL;

	loadedImage = IMG_Load( filename.c_str() );

	if( loadedImage != NULL ){
		//optimize that shit
		optimizedImage = SDL_DisplayFormat( loadedImage );

		//If the image was optimized just fine
		if( optimizedImage != NULL ) {
			//Map the color key
			Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0x00, 0x00, 0x00 );
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
		}
		SDL_FreeSurface( loadedImage );
	}

	finalImage = optimizedImage;
}

void Image::displayImage( int x, int y, SDL_Surface* destination, SDL_Rect* clip){
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface( finalImage, clip, destination, &offset);
}

void Image::freeImage(){
	SDL_FreeSurface(finalImage);
}
