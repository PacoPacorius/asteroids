#pragma once
#include "Entity.h"

// main thing is orientation, we can get the rotation of the player from its sprite

class Player : public Entity {
private:
	float rotation;

public:
	Player();
	Player(sf::Texture player_tex);
	Player(sf::Texture player_tex, sf::Vector2f in_position, sf::Vector2f in_velocity);
};