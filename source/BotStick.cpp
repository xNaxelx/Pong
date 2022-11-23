#include "BotStick.h"

BotStick::BotStick(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer, Ball* ball)
    : GameObject(x, y, width, height, texturePath, renderer, timer)
{
    this->ball = ball;
    speed = 300.0F;
}

void BotStick::UpdateMove()
{
    if (rect.y + rect.h < (ball->GetRect()->y + ball->GetRect()->h))
    {
        Move(0, 1);
    }
    else if (rect.y > ball->GetRect()->y)
    {
        Move(0, -1);
    }
}

void BotStick::Move(float vectorX, float vectorY)
{
    rect.y += vectorY * speed * ((float)timer->GetDeltaTime() / 1000.0F);

    if (rect.y < 0) { rect.y = 0; }
    else if (rect.y > (480 - rect.h - 1)) { rect.y = (480 - rect.h - 1); } // *facepalm* magic number 480 - it "SCREEN_HEIGHT" in main()
}
