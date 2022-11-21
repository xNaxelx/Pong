#include "PlayerStick.h"

PlayerStick::PlayerStick(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer)
    : GameObject(x, y, width, height, texturePath, renderer)
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
