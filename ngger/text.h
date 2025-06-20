#pragma once
#include <string.h>
class text
{
public:
	float x, y, h;
	char txt[255];
	float r, g, b;
	text(float x, float y, float h, float r, float g, float b, char *_txt):x(x),y(y),h(h),r(r),g(g),b(b){
		//strncpy_s(txt, strlen(_txt), _txt, 255);
		//txt[strlen(txt)] = '\x0';
	}
	
};

