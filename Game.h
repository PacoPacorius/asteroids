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


	bool is_out_of_bounds(const Entity entity);
	bool are_colliding(sf::CircleShape& c1, sf::CircleShape& c2);

public:
	Player ship;
	Game();
	Player& get_ship() { return ship; };
	std::vector<Asteroid> get_asteroids() { return asteroids; };
	std::vector<Bullet> get_bullets() { return bullets; };
	Textures& get_textures() { return textures; };

	void create_asteroid(unsigned int number_of_asteroids, float scale = 1.f);
	void update(float dt);



};