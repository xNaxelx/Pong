#include "AnimatedTexture.h"

AnimatedTexture::AnimatedTexture(int framesCount, int x, int y, int width, int heigth)
{
	spriteClips.resize(framesCount);

	for (int i = 0; i < framesCount; i++)
	{
		spriteClips[i].x = x + width * i;
		spriteClips[i].y = y;
		spriteClips[i].w = width;
		spriteClips[i].h = heigth;
	}
}

void AnimatedTexture::Render(int x, int y, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, spriteClips[currentFrame].w, spriteClips[currentFrame].h};

	SDL_RenderCopyEx(renderer, texture, &spriteClips[currentFrame], &renderQuad, angle, center, flip);
}