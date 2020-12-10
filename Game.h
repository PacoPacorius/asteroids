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

	std::vector<std::unique_ptr<Asteroid>> asteroids;
	std::vector<std::unique_ptr<Bullet>> bullets;


public:
	Player ship;
	Game();
	Player& get_ship() { return ship; };
	std::vector<std::unique_ptr<Asteroid>>& get_asteroids() { return asteroids; };
	std::vector<std::unique_ptr<Bullet>>& get_bullets() { return bullets; };
	Textures& get_textures() { return textures; };

	void create_asteroid();
	void update(float dt);



};