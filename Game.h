#include <vector>
#include "Textures.h"
#include "Entity.h"
#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

enum Sides {	// ante sysk s kanw tin xari k ftiaxnw enum
	LEFT = 0, UP, RIGHT, DOWN
};

class Game {
private:
	Textures textures;
	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	unsigned int player_score;
	unsigned int player_lives;
	sf::Text player_score_text;
	std::vector<sf::Sprite> player_lives_sprites;

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
	sf::Text& get_player_score_text() { return player_score_text; }
	std::vector<sf::Sprite>& get_player_lives_sprites() { return player_lives_sprites; }

	void create_asteroid(unsigned int number_of_asteroids, float scale = 1.f);
	void update(float dt);



};