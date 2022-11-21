#pragma once

#include <SDL.h>
#include "Texture.h"
#include "Observer.h"
#include <string>

class GameObject : public IObserver
{
public:
	int speed = 10;

	void UpdateTexture(SDL_Renderer* renderer) override;
	//void HandleEvent(SDL_Event &event) override;

	GameObject();
	GameObject(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer);
	~GameObject();

	void Move(int vectorX, int vectorY);
	void Render(SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip);

	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
protected:
	SDL_Rect rect;

	Texture texture;
};

