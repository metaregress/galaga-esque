/*
 * GenericLevel.cpp
 *
 *  Created on: Apr 7, 2013
 *      Author: joe
 */

#include "GenericLevel.h"

GenericLevel::GenericLevel() {
	// TODO Auto-generated constructor stub

}

GenericLevel::~GenericLevel() {
	// TODO Auto-generated destructor stub
}

void GenericLevel::handleEvents(){
	while(SDL_PollEvent( &event ) ){
		if(!pause){
			playerShip.handleEvent(event);
		}
		else{
			if(resume.handleEvent(event)){
				pause = false;
			}
			else if(restartButton.handleEvent(event)){
				restart();
			}
			else if(pauseQuit.handleEvent(event)){
				nextState = STATE_EXIT;
			}
		}

		if( event.type == SDL_QUIT ){
			nextState = STATE_EXIT;
		}
		if(event.type==SDL_KEYDOWN){
			if(event.key.keysym.sym==SDLK_ESCAPE){
				pause = !pause;
			}
		}

	}
}

void GenericLevel::logic(){
	if(!pause){
		//collision detection ahoy
		playerShip.handleLogic();
		keepInBounds(&playerShip);
		std::vector<Bullet>* currentBullets = playerShip.getBullets();

		spawnEnemies();

		for(unsigned int i=0; i<enemies.size(); i++){
			SDL_Rect enemyRect = enemies.at(i)->getRect();
			for(unsigned int j=0; j<currentBullets->size(); j++){
				SDL_Rect bulletRect = currentBullets->at(j).getRect();
				if(GameState::checkCollision(bulletRect, enemyRect)){
					if(enemies.at(i)->damage(1)){
						score += playerShip.getCombo() * (enemies.at(i)->getPointValue());
						playerShip.setCombo(playerShip.getCombo()+1);
						explosions.push_back(new Explosion(enemies.at(i)->getX(), enemies.at(i)->getY()));
						enemies.erase(enemies.begin() + i);

					}
					currentBullets->erase(currentBullets->begin() + j);
				}
			}

			if(GameState::checkCollision(playerShip.getRect(), enemyRect)){
				if(!playerShip.getInvincibility()){
					lives--;
					enemies.erase(enemies.begin() + i);
					playerShip.setInvincibility(true);
					playerShip.setCombo(0);
				}
			}
		}

		//check if bullets have gone offscreen, and delete them if so
		for(unsigned int i=0; i<currentBullets->size(); i++){
			Bullet bullet = currentBullets->at(i);
			if(checkOutOfBounds(&bullet)){
				currentBullets->erase(currentBullets->begin() + i);
			}
		}

		//check if enemies have left the screen
		for(unsigned int i=0; i<enemies.size(); i++){
			enemies.at(i)->handleLogic();
			if(checkOutOfBounds(enemies.at(i))){
				enemies.erase(enemies.begin() + i);
			}
		}

		//check if explosions have expired
		for(unsigned int i=0; i<explosions.size(); i++){
			if(explosions.at(i)->getExpired()){
				explosions.erase(explosions.begin() + i);
			}
		}

		if(lives<=0){
			nextState = STATE_EXIT;
		}

		//	backgroundY += 1;
		//	if(backgroundY>=100){
		//		backgroundY = -400;
		//	}
	}
}

void GenericLevel::render(SDL_Surface* destination){
	GameState::clearScreen(destination);

	background.displayImage(0, backgroundY, destination);
	playerShip.display(destination);

	//render the enemies
	for(unsigned int i=0; i<enemies.size(); i++){
		enemies.at(i)->display(destination);
	}

	//render the explosions
	for(unsigned int i=0; i<explosions.size(); i++){
		explosions.at(i)->display(destination);
	}

	drawScoreboard(destination);

	if(pause){
		drawPauseMenu(destination);
	}
}

void GenericLevel::keepInBounds(GenericEntity *entity){
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
	if(entityRect.y < 40){
		entity->setCoords(entityRect.x, 40);
	}
}

bool GenericLevel::checkOutOfBounds(GenericEntity *entity){
	SDL_Rect entityRect = entity->getRect();
	if(entityRect.x > LEVEL_WIDTH){
		return true;
	}
	if(entityRect.x + entityRect.w < 0){
		return true;
	}
	if(entityRect.y > LEVEL_HEIGHT){
		return true;
	}
	if(entityRect.y + entityRect.h < 0){
		return true;
	}

	return false;
}

void GenericLevel::drawScoreboard(SDL_Surface* destination){
	SDL_Rect scoreboardDimensions;
	scoreboardDimensions.x = 0;
	scoreboardDimensions.y = 0;
	scoreboardDimensions.w = LEVEL_WIDTH;
	scoreboardDimensions.h = 30;
	SDL_FillRect( destination, &scoreboardDimensions, SDL_MapRGB( destination->format, 0x00, 0x00, 0x00 ) );

	std::string scoreString = "Score: " + GameState::numberToString(score);

	scoreText.setText(scoreString);

	scoreText.displayText(30, 5, destination);

	std::string comboString = "Combo: " + GameState::numberToString(playerShip.getCombo());

	comboText.setText(comboString);

	comboText.displayText(150, 5, destination);

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

void GenericLevel::drawPauseMenu(SDL_Surface* destination){
	SDL_Rect pauseBorderDimensions;
	pauseBorderDimensions.x = 120;
	pauseBorderDimensions.y = 170;
	pauseBorderDimensions.w = 200;
	pauseBorderDimensions.h = 100;

	SDL_Rect pauseInnerDimensions;
	pauseInnerDimensions.x = pauseBorderDimensions.x + 5;
	pauseInnerDimensions.y = pauseBorderDimensions.y + 5;
	pauseInnerDimensions.w = pauseBorderDimensions.w - 10;
	pauseInnerDimensions.h = pauseBorderDimensions.h - 10;

	SDL_FillRect( destination, &pauseBorderDimensions, SDL_MapRGB( destination->format, 0x00, 0x00, 0xFF ) );

	SDL_FillRect( destination, &pauseInnerDimensions, SDL_MapRGB( destination->format, 0x00, 0x00, 0x00 ) );

	pauseText.displayText(pauseBorderDimensions.x+60, pauseBorderDimensions.y+5, destination);

	resume.displayElements(destination);
	pauseQuit.displayElements(destination);
	restartButton.displayElements(destination);
}

void GenericLevel::restart(){
	enemySpawnTimer = 0;
	enemies.clear();
	explosions.clear();
	playerShip = PlayerEntity(200, 350);
	initStats();
}

void GenericLevel::initPauseMenu(){
	pause = false;
	resume = Button(130, 200, 100, 20, "Resume", 20);
	pauseQuit = Button(130, 230, 100, 20, "Quit", 20);
	restartButton = Button(190, 230, 100, 20, "Restart", 20);

	pauseText = TTFText("Pause", 30, "Roboto-Medium.ttf");
}

void GenericLevel::initStats(){
	score = 0;
	lives = 3;
	scoreText = TTFText("", 20, "Roboto-Medium.ttf");
	comboText = TTFText("", 20, "Roboto-Medium.ttf");
}
