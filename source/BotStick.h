#pragma once
#include "GameObject.h"
#include "Ball.h"
class BotStick : public GameObject
{
public:
	Ball* ball;
	BotStick(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer, Ball* ball);

	void UpdateMove() override;

	void Move(float vectorX, float vectorY) override;

private:
	
};

