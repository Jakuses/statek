#pragma once
#include "utils.h"
#include "drawing.h"

class board;
class asteroid
{
public:
	float x, y, r, segments;
	board* b;
	vector2 speedX;
	vector2 speedY;
	bool _todelete = false;
	asteroid(float x, float y, float r, float segments, vector2 speedX, vector2 speedY, board* b);
	void Draw();
	void Update();


};

