#pragma once
//#include <SFML/Graphics.hpp>
#include "Entity.h"

// main thing is orientation, we can get the rotation of the player from its sprite

class Player : public Entity {
private:
	float rotation;
	const float TERMINAL_VELOCITY = 20.f;
	const float ACCELERATION = 2.f;
	const float ROTATION_SPEED = 5.f;
	

public:
	Player();
	Player(sf::Texture player_tex);
	Player(sf::Texture player_tex, sf::Vector2f in_position);
	void movement(float dt);													// will handle movement and rotation of both sprite and object
};