#pragma once
#include "GameObject.h"
class PlayerStick : public GameObject
{
public:
	PlayerStick(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer);

	void UpdateMove() override;
	void HandleEvent(SDL_Event* event) override;

private:
	bool isKeyUpPerformed = false;
	bool isKeyDownPerformed = false;
};

