#include "Asteroid.h"
#include <stdlib.h>

Asteroid::Asteroid() : Entity() {
	rotation_speed = 10.f * ((rand() % 10) - 5);
}

Asteroid::Asteroid(sf::Texture& tex) : Entity(tex) {
	rotation_speed = 10.f * ((rand() % 10) - 5);

	spr.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);

	collision_circle.setPosition(position);
	collision_circle.setRadius(tex.getSize().x / 2.0f);
	collision_circle.setOrigin(spr.getOrigin());
	collision_circle.setFillColor(sf::Color(50, 50, 255, 100));

}

Asteroid::Asteroid(sf::Texture& tex, sf::Vector2f in_position, sf::Vector2f in_velocity) : Entity(tex) {

	rotation_speed = 10.f* ((rand() % 10) - 5);

	spr.setOrigin(tex.getSize().x / 2.0f, tex.getSize().y / 2.0f);

	collision_circle.setPosition(position);
	collision_circle.setRadius(tex.getSize().x / 2.0f);
	collision_circle.setOrigin(spr.getOrigin());
	collision_circle.setFillColor(sf::Color(50, 50, 255, 100));

	set_position( in_position);
	velocity = in_velocity;
}

void Asteroid::update(float dt) {
	Entity::update(dt);
	collision_circle.setPosition(position);
	spr.rotate(rotation_speed * dt);
}

void Asteroid::set_scale(float scale) {
	spr.setScale(scale, scale);
	collision_circle.setScale(scale, scale);
	rotation_speed = rotation_speed /(scale * scale);
}
