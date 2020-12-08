#include "Player.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768

Player::Player() : Entity() { rotation = 0.f; }
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position) : Entity(player_tex, in_position) {
	rotation = 0.f;
}

void Player::input() {
	if (position.x > WINDOW_WIDTH + 10)
		spr.setPosition(sf::Vector2f(-10, position.y));
	else if (position.x < -10)
		spr.setPosition(sf::Vector2f(WINDOW_WIDTH + 10, position.y));

	if (position.y > WINDOW_HEIGHT + 10)
		spr.setPosition(sf::Vector2f(position.x, -10));
	else if (position.y < -10)
		spr.setPosition(sf::Vector2f(position.x, WINDOW_HEIGHT + 10));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		spr.move(sf::Vector2f(-.5f, 0.f));
		position = spr.getPosition();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		spr.move(sf::Vector2f(.5f, 0.f));
	}
		position = spr.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		spr.move(sf::Vector2f(0.f, -.5f));
		position = spr.getPosition();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		spr.move(sf::Vector2f(0.f, .5f));
		position = spr.getPosition();
	}
}