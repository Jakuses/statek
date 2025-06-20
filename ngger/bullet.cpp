#include "bullet.h"
#include "drawing.h"
#include "board.h"
bullet::bullet(float x, float y, vector2 speedx, vector2 speedy, board* b) :
	x(x), y(y), speedx(speedx), speedy(speedy), b(b){
	w = 5;
	h = 10;
}
void bullet::draw() {
	drawing::drawRect(x-w/2, y, w, h, { 1,0,0,1 });

}
void bullet::update() {
	this->x += speedx.y * this->b->deltaTime;
	this->x -= speedx.x * this->b->deltaTime;
	this->y += speedy.y * this->b->deltaTime;
	this->y -= speedy.x * this->b->deltaTime;

	if (this->y + this->h < this->b->y)
	{
		this->_todelete = true;
	}
	this->collisionsWithAsteroid();
}

void bullet::collisionsWithAsteroid()
{
	for (auto& asteroid : this->b->asteroids)
	{
		if (this->x + this->w > asteroid.x-asteroid.r && this->x < asteroid.x + asteroid.r &&
			this->y + this->h > asteroid.y-asteroid.r && this->y < asteroid.y + asteroid.r)
		{
			this->_todelete = true;
			asteroid.segments--;
			if (asteroid.segments < 3)
			{
				this->b->player->score += 10;
				asteroid._todelete = true;
			}

		}
	}
}
