#pragma once
#include "Entity.h"

class Asteroid : public Entity {
public:

private:
	Asteroid();
	Asteroid(sf::Texture tex);
	Asteroid(sf::Texture tex, sf::Vector2f in_position, sf::Vector2f in_velocity);
};