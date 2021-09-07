#include "Character.h"

int Character::getWidth()
{
	return width;
}

int Character::getHeight()
{
	return height;
}

int Character::getX()
{
	return x;
}

int Character::getY()
{
	return y;
}

uint32_t* Character::getSpriteTracker()
{
	return sprite_tracker;
}

int Character::getHealth()
{
	return health;
}

void Character::setWidth(int width)
{
	this->width = width;
}

void Character::setHeight(int height)
{
	this->height = height;
}

void Character::setX(int x)
{
	this->x = x;
}

void Character::setY(int y)
{
	this->y = y;

}

void Character::setSpriteTracker(uint32_t* sprite_tracker)
{
	this->sprite_tracker = sprite_tracker;
}
