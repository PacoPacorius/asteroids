#include "Entity.h"


Entity::Entity() {
	position = sf::Vector2f(0.f, 0.f);
	velocity = sf::Vector2f(0.f, 0.f);
}

Entity::Entity(sf::Texture& in_tex) {
	position = sf::Vector2f(0.f, 0.f);
	velocity = sf::Vector2f(0.f, 0.f);

	spr.setTexture(in_tex);
	spr.setPosition(position);
}

Entity::Entity(sf::Texture& in_tex, sf::Vector2f in_position) {
	position = in_position;
	velocity = sf::Vector2f(0.f, 0.f);

	spr.setTexture(in_tex);
	spr.setPosition(position);
}

void Entity::update() {

}