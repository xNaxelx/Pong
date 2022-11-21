#include "Texture.h"

Texture::Texture()
{
	texture = NULL;
	textureBox.w = 0;
	textureBox.h = 0;
}

Texture::~Texture()
{
	Free();
}

bool Texture::LoadFromFile(std::string path, SDL_Renderer* renderer)
{
	Free();

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		return false;
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			return false;
		}
		else
		{
			textureBox.w = loadedSurface->w;
			textureBox.h = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}
	return true;
}

bool Texture::LoadFromRenderedText(std::string textureText, TTF_Font* font ,SDL_Color textColor, SDL_Renderer* renderer)
{
	Free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			textureBox.w = textSurface->w;
			textureBox.h = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}


	return texture != NULL;
}

void Texture::Free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
		textureBox.w = 0;
		textureBox.h = 0;
	}
}

void Texture::Render(int x, int y, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, textureBox.w, textureBox.h};

	SDL_RenderCopyEx(renderer, texture, &textureBox, &renderQuad, angle, center, flip);
}

int Texture::getWidth()
{
	return textureBox.w;
}

int Texture::getHeight()
{
	return textureBox.h;
}