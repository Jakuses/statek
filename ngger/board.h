#pragma once
#include "ship.h"
#include "window.h"
#include "drawing.h"
#include <vector>
#include "bullet.h"
#include "asteroid.h"

#define ASTEROID_MIN_DELAY 500
#define ASTEROID_MAX_DELAY 5000

#define ASTEROID_MIN_SEGMENTS 3
#define ASTEROID_MAX_SEGMENTS 12

#define ASTEROID_MIN_R 10
#define ASTEROID_MAX_R 30

#define ASTEROID_MIN_SPEED_X -15
#define ASTEROID_MAX_SPEED_X 15

#define ASTEROID_MIN_SPEED_Y 20
#define ASTEROID_MAX_SPEED_Y 150

class board
{
private:
	window* wnd;
	int lastAsteroid = 0;
public:
	ship* player;
	float deltaTime;
	float x, y, w, h;
	float asteroidDelay;
	std::vector<bullet> bullets;
	std::vector<asteroid> asteroids;
	bool playing = true;
	
	board(float x, float y, float w, float h, window* wnd) :x(x), y(y), w(w), h(h),wnd(wnd) {
		this->player = new ship(400, 300, 50, 50, wnd, this); 
		this->deltaTime = 0;
		asteroids.push_back(asteroid(50, 50, 20, 5, { 0,4 }, { 0,50 }, this));
		this->asteroidDelay = ASTEROID_MAX_DELAY;
	}

	~board()
	{
		delete player;
	}

	void Draw();
	void update();
	void handleAsteroids();
};

