/*
 * Button.h
 *
 *  Created on: Dec 31, 2012
 *      Author: joe
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "Image.h"
#include "TTFText.h"
#include <string>

class Button {
public:
	Button();
	Button(int x, int y, int width, int height, std::string buttonText, int textSize=28);
	Button(int x, int y, int width, int height, int textSize=28);
	virtual ~Button();

	bool handleEvent(SDL_Event event);
	int setText(std::string message);
	int textColor(SDL_Color color);
	int setImage(std::string filename);
	void displayElements(SDL_Surface* destination);
	void displayArea(SDL_Surface* destination);
	SDL_Rect getRect();

private:
	SDL_Rect box;
	TTFText text;
	Image image;
	bool selected;
};

#endif /* BUTTON_H_ */
