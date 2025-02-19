#define _USE_MATH_DEFINES

#include "Bullet.h"

Bullet::Bullet() : Entity() {}

Bullet::Bullet(sf::Texture& bullet_tex) : Entity(bullet_tex) {
	spr.setOrigin(bullet_tex.getSize().x / 2.0f, bullet_tex.getSize().y / 2.0f);

	collision_circle.setPosition(position);
	collision_circle.setRadius(bullet_tex.getSize().x / 2.0f);
	collision_circle.setOrigin(spr.getOrigin());
	collision_circle.setFillColor(sf::Color(50, 50, 255, 100));

}

Bullet::Bullet(sf::Texture& bullet_tex, sf::Vector2f in_position, sf::Vector2f in_velocity) {
	spr.setOrigin(bullet_tex.getSize().x / 2.0f, bullet_tex.getSize().y / 2.0f);

	set_position(position = in_position);
	velocity = in_velocity;

	collision_circle.setPosition(position);
	collision_circle.setRadius(bullet_tex.getSize().x / 2.0f);
	collision_circle.setOrigin(spr.getOrigin());
	collision_circle.setFillColor(sf::Color(50, 50, 255, 100));

}

Bullet::Bullet(sf::Texture& bullet_tex, Player& player) : Entity(bullet_tex) {
	spr.setOrigin(bullet_tex.getSize().x / 2.0f, bullet_tex.getSize().x / 2.0f);

	float radians = (player.get_rotation() * M_PI) / 180.f;

	set_position( player.get_position() + sf::Vector2f(16 * sin(radians), -16 * cos(radians)));
	velocity = sf::Vector2f(VELOCITY * sin(radians), -VELOCITY * cos(radians));

	collision_circle.setPosition(position);
	collision_circle.setRadius(bullet_tex.getSize().x / 2.0f);
	collision_circle.setOrigin(spr.getOrigin());
	collision_circle.setFillColor(sf::Color(50, 50, 255, 100));

}

void Bullet::update(float dt) {
	Entity::update(dt);
	collision_circle.setPosition(position);
}

