#include "PlayerStick.h"

PlayerStick::PlayerStick(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer)
    : GameObject(x, y, width, height, texturePath, renderer, timer)
{

};

void PlayerStick::UpdateMove()
{
    if (isKeyUpPerformed)
    {
        Move(0, -1);
    }
    else if (isKeyDownPerformed)
    {
        Move(0, 1);
    }
}

void PlayerStick::HandleEvent(SDL_Event* event) 
{
    if (event->type == SDL_KEYDOWN && event->key.repeat == 0)
    {
        switch (event->key.keysym.sym)
        {
        case SDLK_UP: isKeyUpPerformed = true; break;
        case SDLK_DOWN: isKeyDownPerformed = true; break;
        }
    }
    else if (event->type == SDL_KEYUP && event->key.repeat == 0)
    {
        switch (event->key.keysym.sym)
        {
        case SDLK_UP: isKeyUpPerformed = false; break;
        case SDLK_DOWN: isKeyDownPerformed = false; break;
        }
    }
}

void PlayerStick::Move(int vectorX, int vectorY)
{
    rect.y += vectorY * speed * ((float)timer->GetDeltaTime() / 1000.0F);

    if (rect.y < 0) { rect.y = 0; }
    else if (rect.y > (480 - rect.h - 1)) { rect.y = (480 - rect.h - 1); } // *facepalm* magic number 480 - it "SCREEN_HEIGHT" in main()
}
