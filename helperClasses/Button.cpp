/*
 * Button.cpp
 *
 *  Created on: Dec 31, 2012
 *      Author: joe
 */

#include "Button.h"

Button::Button() {


}

Button::~Button() {

}

Button::Button(int x, int y, int width, int height, int textSize){
	box.x = x;
	box.y = y;
	box.w = width;
	box.h = height;

	text = TTFText();
	image = Image();
}

Button::Button(int x, int y, int width, int height, std::string buttonText, int textSize){
	box.x = x;
	box.y = y;
	box.w = width;
	box.h = height;

	char* fontName = "Roboto-Medium.ttf";
	text = TTFText(buttonText, textSize, fontName);

	image = Image();
}

bool Button::handleEvent(SDL_Event event){
	//mouse offsets
	int x = 0, y = 0;

	if(event.type == SDL_MOUSEBUTTONDOWN){
		//left mouse button pressed
		if(event.button.button == SDL_BUTTON_LEFT){
			x = event.button.x;
			y = event.button.y;

			if( (x>box. x) && (x<box.x + box.w) && (y>box.y) && (y<box.y + box.h)){
				return true;
			}
		}
	}

	return false;
}

int Button::setText(std::string message){
	text.setText(message);

	return 1;
}

int Button::textColor(SDL_Color color){
	text.setColor(color);

	return 1;
}

int Button::setImage(std::string filename){
	image.loadImage(filename);

	return 1;
}

void Button::displayArea(SDL_Surface* destination){
	SDL_FillRect( destination, &box, SDL_MapRGB( destination->format, 0xFF, 0xFF, 0xFF ) );
}

void Button::displayElements(SDL_Surface* destination){
	image.displayImage(box.x, box.y, destination);
	text.displayText(box.x, box.y, destination);

}

SDL_Rect Button::getRect(){
	return box;
}
