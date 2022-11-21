#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool LoadFromFile(std::string path, SDL_Renderer* renderer);
	bool LoadFromRenderedText(std::string textureText, TTF_Font* font, SDL_Color textColor, SDL_Renderer* renderer);
	void Render(int x, int y, SDL_Renderer* renderer, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);


	int getWidth();
	int getHeight();
protected:

	SDL_Texture* texture;
	SDL_Rect textureBox;

	void Free();
};

