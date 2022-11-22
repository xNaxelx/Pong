#include "Ball.h"

Ball::Ball(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer)
	: GameObject(x, y, width, height, texturePath, renderer, timer){}

void Ball::UpdateMove()
{
	if (rect.x <= (0 + 50 + bot->GetWidth())) //collision with bot
	{
		if ((bot->GetY() < rect.y + rect.h) && (bot->GetY() + bot->GetHeight() > rect.y))
		{
			vectorX = 1.0F;
			vectorY = (float)(((rect.y + rect.h / 2.0F) - (bot->GetY() + bot->GetHeight() / 2.0F)) / ((bot->GetHeight() / 2.0F)));
		}
	}
	if (rect.x + rect.w >= (640 - 50 - player->GetWidth())) //collision with player
	{
		if ((player->GetY() < rect.y + rect.h) && (player->GetY() + player->GetHeight() > rect.y))
		{
			vectorX = -1.0F;
			vectorY = (float)(((rect.y + rect.h / 2.0F) - (player->GetY() + player->GetHeight() / 2.0F)) / ((player->GetHeight() / 2.0F)));
		}
	}
	if (rect.y <= 0) //collision with top
	{
		vectorY *= -1.0F;
	}
	if (rect.y >= 480 - rect.h) //collision with down
	{
		vectorY *= -1.0F;
	}

	Move(vectorX, vectorY);
}
SDL_Rect* Ball::GetRect()
{
	return &rect;
}