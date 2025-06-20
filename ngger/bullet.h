#pragma once
#include "utils.h"
class board;
class bullet
{
public:
	float x, y, w, h;
	vector2 speedx, speedy;
	board* b;
	bool _todelete = false;
	bullet(float x, float y, vector2 speedx, vector2 speedy, board* board);
	void draw();
	void update();
	void collisionsWithAsteroid();
};

