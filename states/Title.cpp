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

	playGame = Button(175, 150, 60, 30, "Play");
	quitButton = Button(175, 180, 60, 30, "Quit");

}

Title::~Title() {
	// TODO Auto-generated destructor stub
}

void Title::handleEvents(){
	while(SDL_PollEvent( &event ) ){
		if(playGame.handleEvent(event)){
			nextState = STATE_GAME;
		}
		else if(quitButton.handleEvent(event)){
			nextState = STATE_EXIT;
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
	playGame.displayElements(destination);
//	playGame.displayArea(destination);
	quitButton.displayElements(destination);
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
