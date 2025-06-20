#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <cmath>
#include "utils.h"
#define M_PI 3.14

class window;
struct color4_t {
	float r;
	float g;
	float b;
	float a;
};
class drawing
{	
public:
	static void drawRect(float x, float y, float w, float h, color4_t color);
	static void drawLine(float x1, float y1, float x2, float y2, color4_t color);
	static void drawCircle(float x, float y, float r, float segments, color4_t color);
	static void drawTriangle(vector2 pos1, vector2 pos2, vector2 pos3, color4_t color);
	static void fillCircle(float cx, float cy, float r, float segments, color4_t color);
	static void drawDigit(float x, float y, float height, int digit, color4_t color);
	static void drawText(float x, float y, float height, char* text, color4_t color);
	static void Begin();
	static void End(window* wnd);
};

