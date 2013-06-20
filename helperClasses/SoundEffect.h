/*
 * SoundEffect.h
 *
 * Wrapper class for SDL Mixer sound effect. WAV only at the moment.
 *
 *  Created on: Apr 6, 2013
 *      Author: joe
 */

#ifndef SOUNDEFFECT_H_
#define SOUNDEFFECT_H_

#include "SDL/SDL_mixer.h"
#include <string>

class SoundEffect {
public:
	SoundEffect();
	SoundEffect( std::string filename );
	virtual ~SoundEffect();

	void play();
	void loadSound( std::string filename );
	void setChannel( int newChannel );
	void setLoop( int newIterations );

private:
	Mix_Chunk *sound;
	int channel;
	int iterations;
};

#endif /* SOUNDEFFECT_H_ */
