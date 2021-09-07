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
	uint32_t* getSpriteTracker();
	int getHealth();
	uint32_t* getSprite();
	void setX(int x);
	void setY(int y);
	void setSprite(uint32_t* sprite_tracker);
	void setWidth(int width);
	void setHeight(int height);
	void setX(int x);
	void setY(int y);
	void setSpriteTracker(uint32_t* sprite_tracker);
private:
	int x, y, width, height, health;
	uint32_t* sprite_tracker;

};

