#include "Player.h"

Player::Player() : Entity() { rotation = 0.f; }
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position) : Entity(player_tex, in_position) {
	rotation = 0.f;
}

void Player::input(float dt) {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && velocity.x > -TERMINAL_VELOCITY) {
		velocity += sf::Vector2f(-ACCELERATION, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && velocity.x < TERMINAL_VELOCITY) {
		velocity += sf::Vector2f(ACCELERATION, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && velocity.y > -TERMINAL_VELOCITY) {
		velocity += sf::Vector2f(0.f, -ACCELERATION);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && velocity.y < TERMINAL_VELOCITY) {
		velocity += sf::Vector2f(0.f, ACCELERATION);
	}
		spr.move(dt * velocity);
		position = spr.getPosition();
}