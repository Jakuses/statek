#include "drawing.h"
#include "window.h"
#include "font.h"

void drawing::drawRect(float x, float y, float w, float h, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_QUADS);
	glVertex3f(x, y, 0);
	glVertex3f(x, y+h, 0);
	glVertex3f(x+w, y+h, 0);
	glVertex3f(x+w, y, 0);
	glEnd();
}

void drawing::drawLine(float x1, float y1, float x2, float y2, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_LINES);
	glLineWidth(2);
	glVertex3f(x1, y1, 0);
	glVertex3f(x2, y2, 0);
	glEnd();
}

void drawing::drawCircle(float cx, float cy, float r, float segments, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i <= segments; i++)
	{
		float angle = 2.0f * (float)M_PI * (float)i / (float)segments;
		float x = cx + r * cos(angle);
		float y = cy + r * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
}

void drawing::drawTriangle(vector2 pos1, vector2 pos2, vector2 pos3, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_TRIANGLES);
	glVertex3f(pos1.x, pos1.y, 0);
	glVertex3f(pos2.x, pos2.y, 0);
	glVertex3f(pos3.x, pos3.y, 0);
	glEnd();
}
void drawing::fillCircle(float cx, float cy, float r, float segments, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_TRIANGLE_FAN);

	for (int i = 0; i <= segments; i++)
	{
		float angle = 2.0f * (float)M_PI * (float)i / (float)segments;
		float x = cx + r * cos(angle);
		float y = cy + r * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
}

void drawing::drawDigit(float x, float y, float h, int digit, color4_t color)
{
	char* dg = font::digit[digit];
	int w = h / 10;
	for (int i = 0; i < 15; i++)
	{
		if (dg[i] == 0)continue;
		switch (i)
		{
		case 0: {
			drawing::drawRect(x - h / 4, y - h / 2, h / 2, w, color);
			break;
		}
		case 1: {
			drawing::drawRect(x - h / 4, y - h / 2, w, h/2, color);
			break;
		}
		case 2: {
			drawing::drawRect(x + h / 4, y - h / 2, w, h / 2, color);
			break;
		}
		case 3: {
			drawing::drawRect(x - h / 4, y, h / 2, w, color);
			break;
		}
		case 4: {
			drawing::drawRect(x - h / 4, y , w, h / 2, color);
			break;
		}
		case 5: {
			drawing::drawRect(x + h / 4, y, w, h / 2, color);
			break;
		}
		case 6: {
			drawing::drawRect(x - h / 4, y + h/2, h / 2, w, color);
			break;
		}
		}
	}
}

void drawing::drawText(float x, float y, float height, char* txt, color4_t color)
{
	if (txt == NULL)return;
	int offset = 0;
	for (int i=0;i<strlen(txt);i++)
	{
		drawing::drawDigit(x + offset, y, height, txt[i] - '0', color);
		offset += height / 2 + height / 5;
	}
}

void drawing::Begin()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawing::End(window* wnd)
{
	SwapBuffers(wnd->hdc);
}
