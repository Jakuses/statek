#pragma once
#include <windows.h>	
#include <gl/GL.h>
#include <gl/GLU.h>
class window
{
	ATOM wndclass=NULL;
	
	char* title; 
	HWND ptr;

	void createWindowclass();
	void createWindow();
	void HandleEvents();
	void InitGL();

public:
	int width;
	int height;
	window(int width, int height, const char* title);
	void Update();
	void Draw();
	HDC hdc;
	char keys[255];
	
};

