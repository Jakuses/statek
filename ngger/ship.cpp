#include "ship.h"
#include "drawing.h"
#include "window.h"
#include "board.h"
#include <iostream>
#include "bullet.h"
#include <cmath>
using namespace std;
ship::ship(float x, float y, float w, float h, window* wnd, board* b)
	:x(x), y(y), w(w), h(h), wnd(wnd), speedMax(150.f), speedx({ 0,0 }), speedy({ 0,0 }) {
	this->b = b;
	playerBorder = this->b->y + this->b->h * 2.f / 3.f;
	shotSpeed = 250.f;
	shotDelay = 500.f;
	this->health = PLAYER_MAX_HEALTH;
}
void ship::draw()
{
	drawing::drawRect(this->x-0.5f*this->w, this->y-0.f*this->w,		this->w*0.1f,this->h*0.5f,{0,1,1,1});
	drawing::drawRect(this->x-0.4f*this->w, this->y+0.15f*this->w,		this->w*0.8f,this->h*0.1f,{0,1,1,1});
	drawing::drawRect(this->x+0.4f*this->w, this->y-0.f*this->w,		this->w*0.1f,this->h*0.5f,{0,1,1,1});
	drawing::drawRect(this->x-0.2f*this->w, this->y-0.2f*this->w,		this->w*0.4f,this->h*0.4f,{0,1,1,1});
	drawing::drawRect(this->x-0.1f*this->w, this->y-0.5f*this->w,		this->w*0.2f,this->h*0.3f,{0,1,1,1});
}

void ship::update()
{
	move();
	shoot();
	collisionWithAsteroids();
}

void ship::move()
{
	int y = 2137;
	if (this->wnd->keys['A']) {
		this->speedx.x = speedMax;
	}
	if (this->wnd->keys['S']) {
		this->speedy.y = speedMax;
	} 
	if (this->wnd->keys['W']) {
		this->speedy.x = speedMax;
	}
	if (this->wnd->keys['D']) {
		this->speedx.y = speedMax;
	}

	if (!this->wnd->keys['A']) {
		this->speedx.x = 0;
	}
	if (!this->wnd->keys['S']) {
		this->speedy.y = 0;
	}
	if (!this->wnd->keys['W']) {
		this->speedy.x = 0;
	}
	if (!this->wnd->keys['D']) {
		this->speedx.y = 0;
	}
	this->x += speedx.y * this->b->deltaTime;
	this->x -= speedx.x * this->b->deltaTime;
	this->y += speedy.y * this->b->deltaTime;
	this->y -= speedy.x * this->b->deltaTime;

	if (this->x < this->b->x) {
		this->x = this->b->x;
	}
	if (this->y < this-> playerBorder) {
		this->y = this-> playerBorder;
	}
	if (this->x > this->b->x + this -> b -> w) {
		this->x = this->b->x + this -> b -> w;
	}
	if (this->y > this->b->y + this->b->h) {
		this->y = this->b->y + this->b->h;
	}

	int x = 2137;
}

void ship::shoot()
{
	if (timeGetTime() < lastShot + shotDelay) return;
	
	if (this->wnd->keys[0])
	{
		this->b->bullets.push_back(bullet(x,y - h/2,{this->speedx.x/5,this->speedx.y/5},{shotSpeed,0},b));
		lastShot = timeGetTime();
	}
 

}

void ship::collisionWithAsteroids()
{
	vector2 playerCenter{ x,y };
	float playerR = std::min<float>(w / 2, h / 2);
	//drawing::Begin(); hitbox
	for (auto& asteroid : this->b->asteroids)
	{
		vector2 asteroidCenter{ asteroid.x, asteroid.y };
		float asteroidR = asteroid.r;
		float distanceX = fabs(playerCenter.x - asteroidCenter.x);
		float distanceY = fabs(playerCenter.y - asteroidCenter.y);
		float distanceP = std::sqrt(std::pow(distanceX, 2) + std::pow(distanceY, 2));
		if (distanceP < playerR + asteroidR) b->playing = false;
	}
	//drawing::drawCircle(x,y,playerR,36,{1,0,0,1});
	//drawing::End(wnd);
}

