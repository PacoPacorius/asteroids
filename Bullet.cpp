#include "Bullet.h"

Bullet::Bullet() : Entity() {}

Bullet::Bullet(sf::Texture& bullet_tex) : Entity(bullet_tex) {
	collision_circle.setRadius(bullet_tex.getSize().x / 2.0f);
}

Bullet::Bullet(sf::Texture& bullet_tex, sf::Vector2f in_position, sf::Vector2f in_velocity) {
	position = in_position;
	velocity = in_velocity;
}

Bullet::Bullet(Player& player) : Entity() {
	position = player.get_position();
	// velocity depending on player's orientation
}
