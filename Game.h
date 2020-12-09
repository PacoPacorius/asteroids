#include <vector>
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

class Game {
private:
	Player ship;
	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;

public:
	Player get_ship();
	Asteroid get_asteroid(int index);
	Bullet get_bullet(int index);
	std::vector<Asteroid> get_asteroids();
	std::vector<Bullet> get_bullets();
};