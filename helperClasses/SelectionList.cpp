/*
 * SelectionList.cpp
 *
 *  Created on: Sep 7, 2013
 *      Author: joe
 */

#include "SelectionList.h"

SelectionList::SelectionList() {
	// TODO Auto-generated constructor stub

}

SelectionList::~SelectionList() {
	// TODO Auto-generated destructor stub
}

SelectionList::SelectionList(std::vector<std::string> options, int x, int y, int textSize, bool wrapAround){
	upperRightX = x;
	upperRightY = y;

	currentIndex = 0;

	wrap = wrapAround;

	char* fontFile = "Roboto-Medium.ttf";

	fontSize = textSize;

	pointerImage = TTFText(">", fontSize, fontFile);

	optionList = std::vector<TTFText>();

	for(uint i=0; i<options.size(); i++){
		optionList.push_back(TTFText(options.at(i), textSize, fontFile));
	}
}

int SelectionList::getIndex(){
	return currentIndex;
}

void SelectionList::setIndex(int index){
	currentIndex = index;
}

bool SelectionList::getDisplayFlag(){
	return displayFlag;
}

void SelectionList::setDisplayFlag(bool value){
	displayFlag = value;
}

int SelectionList::handleEvent(SDL_Event event){
	if(event.type==SDL_KEYDOWN){
			if(event.key.keysym.sym==SDLK_UP){
				currentIndex--;
				if(currentIndex<0){
					if(wrap){
						currentIndex=optionList.size()-1;
					}
					else{
						currentIndex=0;
					}
				}
			}
			if(event.key.keysym.sym==SDLK_DOWN){
				currentIndex++;
				if(currentIndex>optionList.size()-1){
					if(wrap){
						currentIndex=0;
					}
					else{
						currentIndex=optionList.size()-1;
					}
				}
			}

		}

	return 1;
}

void SelectionList::displayElements(SDL_Surface* destination){
	if(displayFlag){
		int yOffset = 0;
		for(uint i=0; i<optionList.size(); i++){
			if(i==currentIndex){
				pointerImage.displayText(upperRightX-20, upperRightY + yOffset, destination);
			}
			optionList.at(i).displayText(upperRightX, upperRightY + yOffset, destination);

			yOffset += fontSize + 5;
		}
	}
}
