#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Character
{
public:
	Character(int x, int y, uint32_t* sprite_tracker, int width, int height, int health);
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	int getHealth();
	uint32_t* getSprite();
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);
	void setDamage(int health);

private:
	int x, y, width, height, health;
	uint32_t* sprite_tracker;

};

