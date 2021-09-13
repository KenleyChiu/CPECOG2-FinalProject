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

void Char_sprite::setXdir(int Xdir)
{
	this->Xdir = Xdir;
}

void Char_sprite::setYdir(int Ydir)
{
	this->Ydir = Ydir; 
}