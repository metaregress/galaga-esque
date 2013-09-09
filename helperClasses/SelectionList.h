/*
 * SelectionList.h
 *
 *  Created on: Sep 7, 2013
 *      Author: joe
 */

#ifndef SELECTIONLIST_H_
#define SELECTIONLIST_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "TTFText.h"
#include <vector>
#include <string>

class SelectionList {
public:
	SelectionList();
	SelectionList(std::vector<std::string> options, int x, int y, int textSize, bool wraparound = false);
	virtual ~SelectionList();
	int handleEvent(SDL_Event event);
	void displayElements(SDL_Surface* destination);
	int getIndex();
	void setIndex(int index);
	bool getDisplayFlag();
	void setDisplayFlag(bool value);

private:
	int currentIndex;
	int upperRightX;
	int upperRightY;
	int fontSize;
	bool wrap;
	bool displayFlag;
	TTFText pointerImage;
	std::vector<TTFText> optionList;
};

#endif /* SELECTIONLIST_H_ */
