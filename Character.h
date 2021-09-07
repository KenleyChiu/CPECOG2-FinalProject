#pragma once
#include <iostream>
class Character
{
public:
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	uint32_t* getSpriteTracker();
	int getHealth();
	void setWidth(int width);
	void setHeight(int height);
	void setX(int x);
	void setY(int y);
	void setSpriteTracker(uint32_t* sprite_tracker);
private:
	int x;
	int y;
	uint32_t *sprite_tracker;
	int width;
	int height;
	int health;
};

