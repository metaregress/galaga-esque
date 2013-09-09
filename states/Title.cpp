/*
 * Title.cpp
 *
 *  Created on: Feb 20, 2013
 *      Author: joe
 */

#include "Title.h"

Title::Title() {
	nextState = STATE_NULL;

	titleText = TTFText("GALAGA", 50, "Roboto-Medium.ttf");

	std::vector<std::string> optionText = std::vector<std::string>();
	optionText.push_back("Play");
	optionText.push_back("Quit");

	titleOptions = SelectionList(optionText, 175, 150, 30, true);

//	startSound = Mix_LoadWAV("car-ignition-edit.wav");
//	Mix_PlayChannel( -1, startSound, 0 );
}

Title::~Title() {
	// TODO Auto-generated destructor stub
}

void Title::handleEvents(){
	while(SDL_PollEvent( &event ) ){
		titleOptions.handleEvent(event);
		if(event.type==SDL_KEYDOWN){
			if(event.key.keysym.sym==SDLK_SPACE){
				int selectIndex = titleOptions.getIndex();
				if(selectIndex==0){
					nextState = STATE_GAME;
				}
				else if(selectIndex == 1){
					nextState = STATE_EXIT;
				}
			}
		}

		if( event.type == SDL_QUIT ){
			nextState = STATE_EXIT;
		}
	}
}

void Title::logic(){

}

void Title::render(SDL_Surface* destination){
	GameState::clearScreen(destination);
	titleText.displayText(125, 100, destination);
	titleOptions.displayElements(destination);
}

GameState* Title::getNextState(){
	if(nextState==STATE_NULL){
		return this;
	}
	else if(nextState==STATE_EXIT){
		return NULL;
	}
	else if(nextState==STATE_GAME){
		return new LevelOne();
	}
	else{
		return this;
	}
}
