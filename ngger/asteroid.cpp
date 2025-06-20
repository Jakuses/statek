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
	this->x += speedX.y * this->b->deltaTime * 1 / (segments - ASTEROID_MIN_SEGMENTS + 1);
	this->x -= speedX.x * this->b->deltaTime;
	this->y += speedY.y * this->b->deltaTime * 1 / (segments - ASTEROID_MIN_SEGMENTS + 1);
	this->y -= speedY.x * this->b->deltaTime;


	if (this->y > this->b->y + this->b->h)
	{
		this->b->player->health -= this->segments > ASTEROID_MAX_SEGMENTS / 2 ? 2 : 1;
		this->_todelete = true;

	}
	if (this->x - this->r > this->b->x + this->b->w || this->x + this->r < this->b->x)
	{
		this->_todelete = true;

	}
}
