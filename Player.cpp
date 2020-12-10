#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include "Player.h"

Player::Player() : Entity() { 
	rotation = 0.f;
	spr.setOrigin(16.f, 16.f);
	spr.setPosition(50.f, 50.f);
}
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position) : Entity(player_tex, in_position) {
	rotation = 0.f;
}

float degrees_to_radians(float degrees) {
	return (degrees * M_PI) / 180;
}

void Player::movement(float dt) {
	float absolute_velocity = 0;
	float radians = 0.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		spr.rotate(-ROTATION_SPEED);
		//velocity += sf::Vector2f(-ACCELERATION * dt, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		spr.rotate(ROTATION_SPEED);
		//velocity += sf::Vector2f(ACCELERATION * dt, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && ACCELERATION * dt< TERMINAL_VELOCITY) {
		absolute_velocity = ACCELERATION * dt;
	}
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && velocity.y < TERMINAL_VELOCITY) {
		velocity += sf::Vector2f(0.f, ACCELERATION * dt);
	}*/

	/*spr.rotate(ROTATION_SPEED);
	if(ACCELERATION * dt < TERMINAL_VELOCITY) absolute_velocity = ACCELERATION * dt;*/

	std::cout << "x: " << velocity.x << std::endl << "y: " << velocity.y << std::endl;

	rotation = spr.getRotation();
	radians = degrees_to_radians(rotation);

	velocity += sf::Vector2f(absolute_velocity * sin(radians), -absolute_velocity * cos(radians));
	if (pow(velocity.x, 2) + pow(velocity.y, 2) > TERMINAL_VELOCITY * 50) velocity -= sf::Vector2f(absolute_velocity * sin(radians), -absolute_velocity * cos(radians));
	
	
	spr.move(dt * velocity);
	position = spr.getPosition();
}

