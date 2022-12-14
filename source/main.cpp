#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include "Time.h"
#include "UpdateSystem.h"
#include "PlayerStick.h"
#include "BotStick.h"
#include "Text.h"
#include "AudioMixer.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

UpdateSystem updateSystem;

SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font = NULL;

Time* timer = new Time();

bool Init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
					{
						printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
						success = false;
					}
				}
			}
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
				success = false;
			}
		}
	}

	return success;
}

void Close()
{
	TTF_CloseFont(font);
	font = NULL;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	delete timer;
	timer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int SDL_main(int argc, char* args[])
{
	if (!Init())
	{
		std::cout <<("Failed to initialize!\n");

		Close();

		return -1;
	}

	bool quit = false;
	SDL_Event event;

	Ball* ball = new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, 50, 50, "textures/Ball.png", renderer, timer);
	updateSystem.Attach(ball);
	ball->renderer = renderer;
	PlayerStick* player = new PlayerStick(540, 0, 10, 50, 150, "textures/StickAnimated.png", renderer, timer);
	updateSystem.Attach(player);
	BotStick* bot = new BotStick(50, 0, 1, 50, 150, "textures/Stick.png", renderer, timer, ball);
	updateSystem.Attach(bot);
	ball->player = player;
	ball->bot = bot;

	Text* botScore = new Text("textures/ttf/8-bit-hud.ttf", 50, 190, 50, "0", renderer);
	Text* playerScore = new Text("textures/ttf/8-bit-hud.ttf", 50, 400, 50, "0", renderer);
	updateSystem.Attach(botScore);
	updateSystem.Attach(playerScore);
	ball->botScore = botScore;
	ball->playerScore = playerScore;

	AudioMixer* audioMixer = new AudioMixer("sound/CollisionReaction.wav");
	ball->audioMixer = audioMixer;

	timer->InitTime();

	while (!quit)
	{
		timer->UpdateTime();
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT) { quit = true; }

			updateSystem.NotifyHandleEvent(&event); 
		}
		updateSystem.NotifyUpdateMove();


		SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer);

		updateSystem.NotifyUpdateTextures(renderer);

		SDL_RenderPresent(renderer);
	}

	Close();

	return 0;
}