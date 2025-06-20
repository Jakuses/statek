#pragma once
#include <windows.h>	
#include <gl/GL.h>
#include <gl/GLU.h>
#include "text.h"
#include <vector>
class window
{
	ATOM wndclass=NULL;
	
	char* title; 
	void createWindowclass();
	void createWindow();
	void HandleEvents();
	void InitGL();
public:
	bool redraw = false;
	int width;
	int height;
	std::vector<text>texttoDraw;
	window(int width, int height, const char* title);
	void Update();
	void Draw();
	HDC hdc;
	HWND ptr;
	char keys[255];
	void AddTextToDraw(text txt);
	
};

