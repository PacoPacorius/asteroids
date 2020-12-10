#include <vector>
#include "Textures.h"
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

class Game {
private:
	Textures textures;
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;


public:
	Player ship;
	Game();
	Player& get_ship() { return ship; };
	std::vector<Asteroid> get_asteroids() { return asteroids; };
	std::vector<Bullet> get_bullets() { return bullets; };
	Textures& get_textures() { return textures; };

	void create_asteroid(unsigned int number);
	void update(float dt);



};