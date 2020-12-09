#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

class Game {
private:
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;

public:
	Player ship;
	Game();
	Player& get_ship() { return ship; };
	Asteroid& get_asteroid(int index) { return asteroids[index]; };
	Bullet& get_bullet(int index) { return bullets[index]; };
	std::vector<Asteroid>& get_asteroids() { return asteroids; };
	std::vector<Bullet>& get_bullets() { return bullets; };

	void update();

	void create_asteroid(sf::Texture tex);

};