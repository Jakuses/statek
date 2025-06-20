#pragma once
#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <cmath>
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
	static void drawRect(int x, int y, int w, int h, color4_t color);
	static void drawLine(int x1, int y1, int x2, int y2, color4_t color);
	static void drawCircle(int x,int y, int r, int segments, color4_t color);
	static void Begin();
	static void End(window* wnd);
};

