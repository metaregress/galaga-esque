/*
 * GameState.cpp
 *
 *  Created on: Feb 19, 2013
 *      Author: joe
 */

#include "GameState.h"

GameState::GameState() {
	// TODO Auto-generated constructor stub

}

GameState::~GameState() {
	// TODO Auto-generated destructor stub
}

void GameState::clearScreen(SDL_Surface* destination){
	SDL_FillRect( destination, &destination->clip_rect, SDL_MapRGB( destination->format, 0x00, 0x00, 0x00 ) );
}

bool GameState::checkCollision(SDL_Rect A, SDL_Rect B){
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

std::string GameState::numberToString( int number ){
	ostringstream ss;
	ss << number;
	return ss.str();
}

int GameState::stringToNumber( std::string theString ){
	istringstream ss(theString);
	int result;
	return ss >> result ? result : 0;
}
