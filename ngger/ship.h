#pragma once
#include "window.h"
#include "utils.h"
class board;
class ship
{
public:
	float x, y, w, h,speedMax, playerBorder,shotSpeed, shotDelay;
	int lastShot = 0;
	vector2 speedx, speedy;
	board* b;
	ship(float x, float y, float w, float h, window* wnd, board* b);
	void draw();
	void update();
	void move();
	void shoot();
	void collisionWithAsteroids();
private:
	window* wnd;
};

