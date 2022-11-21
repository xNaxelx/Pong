#pragma once
#include "GameObject.h"
class PlayerStick : public GameObject
{
public:
	PlayerStick(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer);

	void UpdateMove() override;
	void HandleEvent(SDL_Event* event) override;

	void Move(int vectorX, int vectorY) override;

private:
	bool isKeyUpPerformed = false;
	bool isKeyDownPerformed = false;
};

