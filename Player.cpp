#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Player.h"

Player::Player() : Entity() { 
	rotation = 0.f;
	spr.setOrigin(16.f, 16.f);

	collision_circle.setPosition(position);
	collision_circle.setRadius(16.f);
	collision_circle.setOrigin(spr.getOrigin());
	collision_circle.setFillColor(sf::Color(50, 50, 255, 100));
}
Player::Player(sf::Texture& player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture& player_tex, sf::Vector2f in_position) : Entity(player_tex, in_position) {
	rotation = 0.f;
}

float degrees_to_radians(float degrees) {
	return (degrees * M_PI) / 180;
}

void Player::movement(float dt) {
	collision_circle.setPosition(position);
	//SORRY i added this here because of the dt // no prob my dude its all good
	firing_timer += dt;

	float absolute_velocity = 0;																// the total velocity of the ship at any given time
	float radians = 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		spr.rotate(-ROTATION_SPEED * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		spr.rotate(ROTATION_SPEED * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ACCELERATION * dt < TERMINAL_VELOCITY)
		absolute_velocity = ACCELERATION * dt;


	rotation = spr.getRotation();
	radians = degrees_to_radians(rotation);

	// absolute velocity gets shared between the x and y axis depending on the rotation of the ship
	// if the total velocity (which should be the same as absolute_velocity?) exceeds a certain point, then an opposing force is added, not letting the player exceed it
	velocity += sf::Vector2f(absolute_velocity * sin(radians), -absolute_velocity * cos(radians));	
	if (pow(velocity.x, 2) + pow(velocity.y, 2) > TERMINAL_VELOCITY * 50) velocity -= sf::Vector2f(absolute_velocity * sin(radians), -absolute_velocity * cos(radians));
	

	spr.move(dt * velocity);
	position = spr.getPosition();
}

