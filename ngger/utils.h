#pragma once
#include <cstdlib>
struct vector2 {
	float x, y;
};
class utils

{
public:

	static float random(float min, float max);
	static void drawHeartLeft(float x, float y, float w, float h);
	static void drawHeartRight(float x, float y, float w, float h);
	static void intToString(char* dest, int num);
};

