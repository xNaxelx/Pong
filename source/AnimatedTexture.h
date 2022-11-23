#pragma once

#include "Texture.h"

class AnimatedTexture : public Texture
{
public:
	int animationFrames;
	SDL_Rect spriteClips[];

	AnimatedTexture(int framesCount);
private:

};

