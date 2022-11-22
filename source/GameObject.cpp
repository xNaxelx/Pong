#include "GameObject.h"

void GameObject::UpdateTexture(SDL_Renderer* renderer)
{
	texture.Render(rect.x, rect.y, renderer);
}

//void GameObject::HandleEvent(SDL_Event &event)
//{
//	
//}

GameObject::GameObject()
{
	rect.x = 0;
	rect.y = 0;
	speed = 0;
}

GameObject::GameObject(int x, int y, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer)
{
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	texture.LoadFromFile(texturePath, renderer);
	this->timer = timer;
}

GameObject::~GameObject()
{
	texture.~Texture();
}

void GameObject::Move(float vectorX, float vectorY)
{
	rect.x += vectorX * speed * ((float)timer->GetDeltaTime() / 1000.0F);
	rect.y += vectorY * speed * ((float)timer->GetDeltaTime() / 1000.0F);
}

void GameObject::Render(SDL_Renderer* renderer, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	texture.Render(rect.x, rect.y, renderer, angle, center, flip);
}

int GameObject::GetX()
{
	return rect.x;
}

int GameObject::GetY()
{
	return rect.y;
}

int GameObject::GetWidth()
{
	return rect.w;
}

int GameObject::GetHeight()
{
	return rect.h;
}