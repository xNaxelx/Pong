#pragma once
#include "GameObject.h"
#include <SDL.h>

class Ball : public GameObject
{
public:
	GameObject* player;
	GameObject* bot;


	Ball(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer);

	void UpdateMove() override;

	//void Move(float vectorX, float vectorY) override;

	SDL_Rect* GetRect();
private:
	float vectorX = 1;
	float vectorY = 0;
};

