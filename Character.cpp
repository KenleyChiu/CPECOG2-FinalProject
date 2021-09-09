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

int Character::getInvul()
{
	return 0;
}

void Character::setInvul(int invul)
{
	this->invul = invul;
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

int Character::CheckTileCollision(Tiles* tile)
{
	int char_bottom = y + height;
	int char_right = x + width;
	int tile_bottom = tile->getY() + tile->getHeight();
	int tile_right = tile->getX() + tile->getWidth();

	if (tile->getType() == 2 || tile->getType() == 3)
	{
		if (char_right + x_speed > tile->getX() && x + x_speed < tile_right && char_bottom > tile->getY() && y < tile_bottom)
			return 1;
		else if (char_bottom + y_speed > tile->getY() && y + y_speed < tile_bottom && char_right > tile->getX() && x < tile_right)
			return 1;
	}

	else
	{
		if (x + x_speed == tile->getX() && y + y_speed == tile->getY())
			return 1;
	}
	

	return 0;
}

void Character::ChangeCharacter(Tiles* tile)
{
	if (tile->getKey() != invul)
	{
		invul = tile->getKey();
		health = health - tile->getDamage();
		printf("%d\n", health);
	}
	if (tile->getType() == 4) health = 3;
}


