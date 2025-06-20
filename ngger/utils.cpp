#include "utils.h"
#include "drawing.h"
#include <algorithm>
float utils::random(float _min, float _max)
{
    return rand() % ((int)_max - (int)_min) + _min;
}

void utils::drawHeartLeft(float x, float y, float w, float h)
{
    drawing::fillCircle(x,y,w/2, 10, {1,0,0,1});
    drawing::drawTriangle({ x - w / 2,y + h * 2 / 8 }, { x + w/2,y + h * 2 / 8 }, {x + w/2,y + h}, { 1,0,0,1 });

}

void utils::drawHeartRight(float x, float y, float w, float h)
{
    drawing::fillCircle(x, y, w / 2, 10, { 1,0,0,1 });
    drawing::drawTriangle({ x - w / 2,y + h * 2 / 8 }, { x + w / 2,y + h* 2/8}, {x - w / 2,y + h}, {1,0,0,1});
}

void utils::intToString(char* dest, int num)
{
    if (num == 0)
    {
        dest[0] = '0';
        dest[1] = '\x0';
        return;
    }
    int i = 0;
    while (num > 0)
    {
        dest[i++] = num % 10 + '0';
        num /= 10;
    }
    dest[i] = '\x0';
    std::reverse(dest, dest + i);
}
