#include "Walls.h"

Walls::Walls(int x, int y, uint32_t* sprite_tracker, int width, int height)
{
}

int Walls::getWidth()
{
	return width;
}

int Walls::getHeight()
{
	return height;
}

int Walls::getX()
{
	return x;
}

int Walls::getY()
{
	return y;
}

uint32_t* Walls::getSprite()
{
	return sprite_tracker;
}

void Walls::setX(int x)
{
	this->x = x;
}

void Walls::setY(int y)
{
	this->y = y;
}

void Walls::setSprite(uint32_t* sprite_tracker)
{
	this->sprite_tracker = sprite_tracker;
}

void Walls::setWidth(int width)
{
	this->width = width;
}

void Walls::setHeight(int height)
{
	this->height = height;
}
