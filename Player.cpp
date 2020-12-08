#include "Player.h"

Player::Player() : Entity() { rotation = 0.f; }
Player::Player(sf::Texture player_tex) : Entity(player_tex) { rotation = 0.f; }

Player::Player(sf::Texture player_tex, sf::Vector2f in_position) : Entity(player_tex) {
	position = in_position;

	rotation = 0.f;
}