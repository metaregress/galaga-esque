/**
 * Main method and junk
 *
 */
#include <string>

#include "GalagaGame.h"

GalagaGame theGame;

int main( int argc, char* args[]){

	theGame = GalagaGame();

	theGame.runGame();
}
