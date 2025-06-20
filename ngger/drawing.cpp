#include "drawing.h"
#include "window.h"
void drawing::drawRect(int x, int y, int w, int h, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_QUADS);
	glVertex3f(x, y, 0);
	glVertex3f(x, y+h, 0);
	glVertex3f(x+w, y+h, 0);
	glVertex3f(x+w, y, 0);
	glEnd();
}

void drawing::drawLine(int x1, int y1, int x2, int y2, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_LINES);
	glLineWidth(2);
	glVertex3f(x1, y1, 0);
	glVertex3f(x2, y2, 0);
	glEnd();
}

void drawing::drawCircle(int cx, int cy, int r, int segments, color4_t color)
{
	glColor4f(color.r, color.g, color.b, color.a);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i <= segments; i++)
	{
		float angle = 2.0f * M_PI * (float)i / (float)segments;
		float x = cx + r * cos(angle);
		float y = cy + r * sin(angle);
		glVertex2f(x, y);
	}

	glEnd();
}

void drawing::Begin()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawing::End(window* wnd)
{
	SwapBuffers(wnd->hdc);
}
