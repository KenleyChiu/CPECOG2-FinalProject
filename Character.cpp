#include "Character.h"
Character::Character(uint32_t* sprite_tracker, int width, int height, int Xdir, int Ydir, int x, int y, int health, int x_speed, int y_speed)
{
	this->x = x;
	this->y = y;
	this->health = health;
	this->sprite_tracker = sprite_tracker;
	this->width = width;
	this->height = height;
	this->Xdir = Xdir;
	this->Ydir = Ydir;
	this->x_speed = x_speed;
	this->y_speed = y_speed;
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

void Character::changeXPos()
{
	x = x + x_speed;
}

void Character::changeYPos()
{
	y = y + y_speed;
}

void Character::setXspeed(int x_speed)
{
	this->x_speed = x_speed;
}

void Character::setYspeed(int y_speed)
{
	this->y_speed = y_speed;
}
