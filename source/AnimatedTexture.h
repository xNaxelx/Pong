#pragma once

#include "Texture.h"
#include <vector>

class AnimatedTexture : public Texture
{
public:
	std::vector<SDL_Rect> spriteClips;
	int currentFrame = 0;

	AnimatedTexture(int framesCount, int x, int y, int width, int heigth);

	void Render(int x, int y, SDL_Renderer* renderer, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE) override;
private:

};

