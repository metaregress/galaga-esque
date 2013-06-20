/*
 * TTFText.cpp
 *
 *  Created on: Jan 20, 2013
 *      Author: joe
 */

#include "TTFText.h"
TTFText::TTFText(){

}
TTFText::TTFText(std::string initialText, int textSize, char* fontFile) {
	text = initialText;

	size = textSize;

	SDL_Color color = { 0, 255, 0 };

	textColor = color;

	loadFont(fontFile, size);
}

TTFText::~TTFText() {
//	freeResources();
}

int TTFText::setText(std::string newText){
	text = newText;

	return 1;
}

std::string TTFText::getText(){
	return text;
}

int TTFText::setColor(SDL_Color color){
	textColor = color;

	return 1;
}

void TTFText::displayText(int x, int y, SDL_Surface* destination){
	char textChars[text.size()+1];
	strcpy(textChars, text.c_str());

	SDL_Surface *message = TTF_RenderText_Solid( font, textChars, textColor );

	SDL_Rect offset;

	offset.x = x;
	offset.y = y;

	SDL_BlitSurface( message, NULL, destination, &offset);
}

int TTFText::loadFont(char* fontFile, int fontSize){
	font = TTF_OpenFont( fontFile, size);

	if(font==NULL){
		return -1;
	}

	return 1;

}

void TTFText::freeResources(){
	SDL_FreeSurface(message);
	//Close the font that was used
	TTF_CloseFont( font );
}



