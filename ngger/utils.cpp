#include "utils.h"
#include "drawing.h"
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
