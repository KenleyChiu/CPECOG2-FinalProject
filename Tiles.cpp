#include "Tiles.h"

Tiles::Tiles(int x, int y, uint32_t* sprite_tracker, int width, int height, int damage, float change_speed)
{
}

int Tiles::getWidth()
{
	return width;
}

int Tiles::getHeight()
{
	return height;
}

int Tiles::getX()
{
	return x;
}

int Tiles::getY()
{
	return y;
}

int Tiles::getDamage()
{
	return damage;
}

float Tiles::getChangeSpeed()
{
	return change_speed;
}

uint32_t* Tiles::getSprite()
{
	return sprite_tracker;
}

void Tiles::setX(int x)
{
	this->x = x;
}

void Tiles::setY(int y)
{
	this->y = y;
}

void Tiles::setSprite(uint32_t* sprite_tracker)
{
	this->sprite_tracker = sprite_tracker;
}

void Tiles::setWidth(int width)
{
	this->width = width;

}

void Tiles::setHeight(int height)
{
	this->height = height;

}

void Tiles::setDamage(int damage)
{
	this->damage = damage;
}

void Tiles::setChangeSpeed(float change_speed)
{
	this->change_speed = change_speed;
}
