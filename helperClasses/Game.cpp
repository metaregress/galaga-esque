/*
 * Game.cpp
 *
 * The main class for handling things like winstates,
 * doing legwork and so on.
 *
 *  Created on: Sep 16, 2012
 *      Author: joe
 */

#include "Game.h"

Game::Game() {
	//initialize graphics
	initGraphics();
	initAudio();
}

Game::~Game() {

}


void Game::clearScreen(){
	//Fill the screen white
	SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0x00, 0x00, 0x00 ) );
}

std::string Game::numberToString( int number ){
	ostringstream ss;
	ss << number;
	return ss.str();
}

int Game::stringToNumber( std::string theString ){
	istringstream ss(theString);
	int result;
	return ss >> result ? result : 0;
}

bool Game::initGraphics(){
	screen = NULL;

	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 ){
		return false;
	}

	//Initialize SDL_ttf
	if( TTF_Init() == -1 ) {
		return false;
	}

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	if(screen == NULL){
		return false;
	}

	SDL_WM_SetCaption( "Galaga", NULL ); //TODO: make this a function's job so it can be easily modified by children

	//Open the font
	font = TTF_OpenFont( "Roboto-Medium.ttf", 28 ); //TODO: make this a function's job so it can be easily modified by children

	return true;
}

bool Game::initAudio(){
	//Initialize SDL_mixer
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
		return false;
	}

	return true;
}


int Game::runGame(){
	//can haz event loop
	fpsTimer = Timer();
	clearScreen();

	while( currentState != NULL ){
		fpsTimer.start();
		currentState->handleEvents();

		currentState->logic();

		currentState = currentState->getNextState();

		if(currentState!=NULL){
			currentState->render(screen);
		}

		//Update the screen
		if( SDL_Flip( screen ) == -1 ) {
			return 1;
		}

		if( fpsTimer.get_ticks() < (1000 / FRAMES_PER_SECOND)  ){
			//Sleep the remaining frame time
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fpsTimer.get_ticks() );
		}

	}


	cleanUpGraphics();
	cleanUpAudio();

	return 1;
}

void Game::cleanUpGraphics(){
	//Close the font that was used
	TTF_CloseFont( font );
	//Quit SDL_ttf
	TTF_Quit();
	//Quit SDL
	SDL_Quit();
}

void Game::cleanUpAudio(){
	//Quit SDL_mixer
	Mix_CloseAudio();
}

bool Game::checkCollision( SDL_Rect A, SDL_Rect B ) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	//Calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;
	//Calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
	if( bottomA < topB ) {
		return false;
	}
	if( topA > bottomB ) {
		return false;
	}
	if( rightA < leftB ) {
		return false;
	}
	if( leftA > rightB ) {
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
