#pragma once
//#include <SFML/Graphics.hpp>
#include "Entity.h"

// main thing is orientation, we can get the rotation of the player from its sprite

class Player : public Entity {
private:
	float rotation;
	float firing_timer;
	const float TERMINAL_VELOCITY = 20.f;
	const float ACCELERATION = 2.f;
	const float ROTATION_SPEED = 5.f;
	const float FIRING_COOLDOWN = 2.0f;
	

public:

	Player();
	Player(sf::Texture& player_tex);
	Player(sf::Texture& player_tex, sf::Vector2f in_position);
	void movement(float dt);													// will handle movement and rotation of both sprite and object

	float get_rotation() const { return rotation; }

	bool can_fire() { 
		if (firing_timer > FIRING_COOLDOWN) { firing_timer = 0; return true; }
		else return false;
	}


};