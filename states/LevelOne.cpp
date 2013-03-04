/*
 * LevelOne.cpp
 *
 *  Created on: Feb 20, 2013
 *      Author: joe
 */

#include "LevelOne.h"

LevelOne::LevelOne() {
	playerShip = PlayerEntity(200, 350);
	background = Image();
	background.loadImage("background.png");
	backgroundY = -400;

	enemies = std::vector<GenericEnemy>();

	enemies.push_back(StraightDownEnemy(50, 40));

	score = 0;
	lives = 3;

	scoreboardShip = Image();
	scoreboardShip.loadImage("playerShip.png");
}

LevelOne::~LevelOne() {
	// TODO Auto-generated destructor stub
}

void LevelOne::handleEvents(){
	while(SDL_PollEvent( &event ) ){
		playerShip.handleEvent(event);
		if( event.type == SDL_QUIT ){
			nextState = STATE_EXIT;
		}
	}
}

void LevelOne::logic(){
	//collision detection ahoy
	playerShip.handleLogic();
	keepInBounds(&playerShip);
	std::vector<Bullet>* currentBullets = playerShip.getBullets();
	//check if bullets have gone offscreen, and delete them if so
	for(unsigned int i=0; i<currentBullets->size(); i++){
		Bullet bullet = currentBullets->at(i);
		if(checkOutOfBounds(bullet)){
			currentBullets->erase(currentBullets->begin() + i);
		}
	}

	//handle enemy logic
	for(unsigned int i=0; i<enemies.size(); i++){
		enemies.at(i).handleLogic();
		if(checkOutOfBounds(enemies.at(i))){
			enemies.erase(enemies.begin() + i);
		}
	}

//	backgroundY += 1;
//	if(backgroundY>=100){
//		backgroundY = -400;
//	}
}

void LevelOne::render(SDL_Surface* destination){
	GameState::clearScreen(destination);

	background.displayImage(0, backgroundY, destination);
	playerShip.display(destination);

	//render the enemies
	for(unsigned int i=0; i<enemies.size(); i++){
		enemies.at(i).display(destination);
	}

	drawScoreboard(destination);
}

GameState* LevelOne::getNextState(){
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

void LevelOne::keepInBounds(GenericEntity *entity){
	SDL_Rect entityRect = entity->getRect();
	if(entityRect.x + entityRect.w > LEVEL_WIDTH){
		entity->setCoords(LEVEL_WIDTH - entityRect.w, entityRect.y);
	}
	if(entityRect.x < 0){
		entity->setCoords(0, entityRect.y);
	}
	if(entityRect.y + entityRect.h > LEVEL_HEIGHT){
		entity->setCoords(entityRect.x, LEVEL_HEIGHT-entityRect.h);
	}
	if(entityRect.y < 0){
		entity->setCoords(entityRect.x, 0);
	}
}

bool LevelOne::checkOutOfBounds(GenericEntity entity){
	SDL_Rect entityRect = entity.getRect();
	if(entityRect.x > LEVEL_WIDTH){
		return true;
	}
	if(entityRect.x + entityRect.w < 0){
		return true;
	}
	if(entityRect.y > LEVEL_HEIGHT){
		return true;
	}
	if(entityRect.y + entityRect.h < 40){
		return true;
	}

	return false;
}

void LevelOne::drawScoreboard(SDL_Surface* destination){
	SDL_Rect scoreboardDimensions;
	scoreboardDimensions.x = 0;
	scoreboardDimensions.y = 0;
	scoreboardDimensions.w = LEVEL_WIDTH;
	scoreboardDimensions.h = 30;
	SDL_FillRect( destination, &scoreboardDimensions, SDL_MapRGB( destination->format, 0x00, 0x00, 0x00 ) );

	std::string scoreString = "Score: " + GameState::numberToString(score);

	TTFText scoreText = TTFText(scoreString, 20, "Roboto-Medium.ttf");

	scoreText.displayText(30, 5, destination);

	int livesX = 300;
	for(int i=0; i<lives; i++){
		scoreboardShip.displayImage(livesX, 5, destination);
		livesX += 25;
	}

	SDL_Rect barDimensions;
	barDimensions.x = 0;
	barDimensions.y = 30;
	barDimensions.w = LEVEL_WIDTH;
	barDimensions.h = 5;
	SDL_FillRect( destination, &barDimensions, SDL_MapRGB( destination->format, 0x00, 0x00, 0xFF ) );
}
