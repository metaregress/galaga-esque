/*
 * SoundEffect.cpp
 *
 *  Created on: Apr 6, 2013
 *      Author: joe
 */

#include "SoundEffect.h"

SoundEffect::SoundEffect() {
	channel = -1;
	iterations = 0;

}

SoundEffect::SoundEffect(std::string filename){
	sound = Mix_LoadWAV(filename.c_str());
	channel = -1;
	iterations = 0;
}

SoundEffect::~SoundEffect() {
	// TODO Auto-generated destructor stub
}

void SoundEffect::loadSound(std::string filename){
	sound = Mix_LoadWAV(filename.c_str());
}

void SoundEffect::play(){
	Mix_PlayChannel( channel, sound, iterations );
}

void SoundEffect::setChannel(int newChannel){
	channel = newChannel;
}

void SoundEffect::setLoop( int newIterations ){
	iterations = newIterations;
}
