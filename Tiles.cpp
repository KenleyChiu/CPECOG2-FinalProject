#include "Tiles.h"

Tiles::Tiles(uint32_t* sprite_tracker, int width, int height, int x, int y, int damage, int change_speed, int type, int new_x, int new_y, int key)
{
	this->x = x;
	this->y = y;
	this->sprite_tracker = sprite_tracker;
	this->width = width;
	this->height = height;
	this->change_speed = change_speed;
	this->damage = damage;
	this->type = type;
	this->key = key;
	this->new_x = new_x;
	this->new_y = new_y;


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

int Tiles::getType()
{
	return type;
}

int Tiles::getKey()
{
	return key;
}

int Tiles::getChangeSpeed()
{
	return change_speed;
}

int Tiles::getNewX()
{
	return new_x;
}

int Tiles::getNewY()
{
	return new_y;
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

void Tiles::setChangeSpeed(int change_speed)
{
	this->change_speed = change_speed;
}

void Tiles::setType(int type)
{
	this->type = type;
}
