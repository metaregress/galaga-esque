/*
 * TTFText.h
 *
 *  Created on: Jan 20, 2013
 *      Author: joe
 */

#ifndef TTFTEXT_H_
#define TTFTEXT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include <string>

class TTFText {
public:
	TTFText();
	TTFText( std::string initialText, int textSize, char* fontFile);
	virtual ~TTFText();
	int setText(std::string newText);
	std::string getText();
	int setSize(int textSize);
	int setColor(SDL_Color color);
	void displayText(int x, int y, SDL_Surface* destination);
	int loadFont(char* fontFile, int fontSize);
	void freeResources();
private:
	std::string text;
	int size;
	SDL_Surface* message;
	SDL_Color textColor;
	TTF_Font* font;

};

#endif /* TTFTEXT_H_ */
