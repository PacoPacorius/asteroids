#include "Player.h"

Player::Player() : Entity() { rotation = 0.f; }
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position) : Entity(player_tex, in_position) {
	rotation = 0.f;
}

void Player::input() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		spr.move(sf::Vector2f(-1.f, 0.f));
		position = spr.getPosition();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		spr.move(sf::Vector2f(1.f, 0.f));
	}
		position = spr.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		spr.move(sf::Vector2f(0.f, -1.f));
		position = spr.getPosition();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		spr.move(sf::Vector2f(0.f, 1.f));
		position = spr.getPosition();
	}
}