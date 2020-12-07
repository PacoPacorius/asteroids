#include "Player.h"

Player::Player() : Entity() { rotation = 0.f; }
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position, sf::Vector2f in_velocity) : Entity(player_tex) {
	position = in_position;
	velocity = in_velocity;

	rotation = 0.f;
}