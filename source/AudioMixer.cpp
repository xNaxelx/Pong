#include "AudioMixer.h"

AudioMixer::AudioMixer(std::string pathCRsound)
{
	collisionReaction = Mix_LoadWAV(pathCRsound.c_str());
	if (collisionReaction == NULL)
	{
		printf("Failed to load collision reaction sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

AudioMixer::~AudioMixer()
{
	Mix_FreeChunk(collisionReaction);
	collisionReaction = NULL;
}

void AudioMixer::PlaySound(Mix_Chunk* sound)
{
	Mix_PlayChannel(-1, sound, 0);
}