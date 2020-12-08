#include "Player.h"

Player::Player() : Entity() { rotation = 0.f; }
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position) : Entity(player_tex, in_position) {
	rotation = 0.f;
}

void Player::input() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		spr.move(sf::Vector2f(-5.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		spr.move(sf::Vector2f(5.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		spr.move(sf::Vector2f(0.f, -5.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		spr.move(sf::Vector2f(0.f, 5.f));
}