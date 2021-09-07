#include "Char_sprite.h"

Char_sprite::Char_sprite(uint32_t* sprite_tracker, int width, int height, int Xdir, int Ydir)
{
	this->sprite_tracker = sprite_tracker;
	this->width = width;
	this->height = height;
	this->Xdir = Xdir;
	this->Ydir = Ydir;
}

int Char_sprite::getWidth()
{
	return width;
}

int Char_sprite::getHeight()
{
	return height;
}

int Char_sprite::getX()
{
	return x;
}

int Char_sprite::getY()
{
	return y;
}

int Char_sprite::getHealth()
{
	return health;
}

uint32_t* Char_sprite::getSprite()
{
	return sprite_tracker;
}

int Char_sprite::getXdir()
{
	return Xdir;
}

int Char_sprite::getYdir()
{
	return Ydir;
}


void Char_sprite::setX(int x)
{
	this->x = x;
}

void Char_sprite::setY(int y)
{
	this->y = y;

}

void Char_sprite::setSprite(uint32_t* sprite_tracker)
{
	this->sprite_tracker = sprite_tracker;
}

void Char_sprite::setWidth(int width)
{
	this->width = width;
}

void Char_sprite::setHeight(int height)
{
	this->height = height;
}

void Char_sprite::setHealth(int health)
{
	this->health = health; 
}

void Char_sprite::setXdir(int Xdir)
{
	this->Xdir = Xdir;
}

void Char_sprite::setYdir(int Ydir)
{
	this->Ydir = Ydir; 
}