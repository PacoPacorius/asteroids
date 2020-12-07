#include "Bullet.h"

Bullet::Bullet() : Entity() {}
Bullet::Bullet(sf::Texture bullet_tex) : Entity(bullet_tex) {}

Bullet::Bullet(sf::Vector2 in_position, sf::Vector2 in_velocity) {
	position = in_position;
	get_velocity=in_velocity;
}

Bullet::Bullet(Player& player) : Entity() {
	position = player.get_position();
	// velocity depending on player's orientation
}
