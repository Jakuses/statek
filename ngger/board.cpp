#include "board.h"
void board::Draw(){
	if (player == NULL) return;

	//borders
	drawing::drawLine(x, y, x + w, y, {1,1,1,1});
	drawing::drawLine(x, y+h, x + w, y+h, { 1,1,1,1 });
	drawing::drawLine(x, y, x, y+h, { 1,1,1,1 });
	drawing::drawLine(x+w, y, x+w, y+h, { 1,1,1,1 });

	for (auto& bullet : bullets) {
		bullet.draw();
	}
	for (auto& asteroid : asteroids) {
		asteroid.Draw();

	}  
	int offset = 0;
	for (int i = 0; i < this->player->health; i++) {
		if(i%2==0)utils::drawHeartLeft(this->x + 20 + i * 20 + offset, this->y + 20, 20, 20);
		else {
			utils::drawHeartRight(this->x + 18 + i * 20 + offset, this->y + 20, 20, 20);
			offset += 10;
		}
	}
	player->draw();
}
void board::update(){
	if (player == NULL) return;
	player->update();
	this->handleAsteroids();
	for (auto& bullet : bullets) {
		bullet.update();
	}

	for (int i = 0; i < this->bullets.size(); i++)
	{
		if (this->bullets.at(i)._todelete)
		{
			this->bullets.erase(this->bullets.begin() + i);
		}
	}

	for (auto& asteroid : asteroids) {
		asteroid.Update();
	}

	for (int i = 0; i < this->asteroids.size(); i++)
	{
		if (this->asteroids.at(i)._todelete)
		{
			this->asteroids.erase(this->asteroids.begin() + i);
		}
	}
	if (this->player->health == 0) playing = false;

}

void board::handleAsteroids()
{
	if (timeGetTime() < lastAsteroid + asteroidDelay)return;
	lastAsteroid = timeGetTime();
	//create
	float r_r = utils::random(ASTEROID_MIN_R, ASTEROID_MAX_R);
	float r_segments = utils::random(ASTEROID_MIN_SEGMENTS, ASTEROID_MAX_SEGMENTS);
	float r_speedX = utils::random(ASTEROID_MIN_SPEED_X, ASTEROID_MAX_SPEED_X);
	float r_speedY = utils::random(ASTEROID_MIN_SPEED_Y, ASTEROID_MAX_SPEED_Y);
	float r_x = utils::random(this->x, this->x + this->w);
	float r_y = this->y - r_r;


	this->asteroids.push_back(asteroid(r_x, r_y, r_r, r_segments, { r_speedX, 0 }, { 0,r_speedY }, this));
}
