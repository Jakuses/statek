#include "asteroid.h"
#include "board.h"

asteroid::asteroid(float x, float y, float r, float segments, vector2 speedX, vector2 speedY, board* b) :
	x(x), y(y), r(r), segments(segments), speedX(speedX), speedY(speedY), b(b)
{

}

void asteroid::Draw()
{
	drawing::drawCircle(x, y, r, segments, { 1,1,1,1 });
}

void asteroid::Update()
{
	this->x += speedX.y * this->b->deltaTime;
	this->x -= speedX.x * this->b->deltaTime;
	this->y += speedY.y * this->b->deltaTime;
	this->y -= speedY.x * this->b->deltaTime;

	if (this->y > this->b->y + this->b->h)
	{
		this->_todelete = true;
	}
}
