#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "Text.h"
#include "AudioMixer.h"

class Ball : public GameObject
{
public:
	GameObject* player;
	GameObject* bot;
	Text* botScore;
	Text* playerScore;
	SDL_Renderer* renderer;
	AudioMixer* audioMixer;

	int intPlayerScore = 0;
	int intBotScore = 0;


	Ball(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer);

	void UpdateMove() override;

	void UpdateScoreOnScreen();
	SDL_Rect* GetRect();
private:
	float vectorX = 1;
	float vectorY = 0;
};

