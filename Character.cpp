#include "Character.h"

Character::Character(int x, int y, uint32_t* sprite_tracker, int width, int height, int health, int Xdir, int Ydir)
{
}

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

int Character::getHealth()
{
	return health;
}

uint32_t* Character::getSprite()
{
	return sprite_tracker;
}

int Character::getXdir()
{
	return Xdir;
}

int Character::getYdir()
{
	return Ydir;
}


void Character::setX(int x)
{
	this->x = x;
}

void Character::setY(int y)
{
	this->y = y;

}

void Character::setSprite(uint32_t* sprite_tracker)
{
	this->sprite_tracker = sprite_tracker;
}

void Character::setWidth(int width)
{
	this->width = width;
}

void Character::setHeight(int height)
{
	this->height = height;
}

void Character::setHealth(int health)
{
	this->health = health; 
}

void Character::setXdir(int Xdir)
{
	this->Xdir = Xdir;
}

void Character::setYdir(int Ydir)
{
	this->Ydir = Ydir; 
}