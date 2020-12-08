#include "Asteroid.h"

Asteroid::Asteroid() : Entity() {}
Asteroid::Asteroid(sf::Texture tex) : Entity(tex) {}

Asteroid::Asteroid(sf::Texture tex, sf::Vector2f in_position, sf::Vector2f in_velocity) : Entity(tex) {
	position = in_position;
	velocity = in_position;
}