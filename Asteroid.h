#pragma once
#include "Entity.h"

class Asteroid : public Entity {
private:
	sf::CircleShape collision_circle;

public:
	Asteroid();
	Asteroid(sf::Texture& tex);
	Asteroid(sf::Texture& tex, sf::Vector2f in_position, sf::Vector2f in_velocity);

	void update(float dt);

	sf::CircleShape get_collision_circle() { return collision_circle; }

};