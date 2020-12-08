#pragma once
#include <SFML/Graphics.hpp>

/// ENTITY
/// T H I S  will take care of position, physics, movements, textures, sprites, collisions(todo)
/// 
/// maybe handle rotation from here? Asteroids could have one common texture and we could rotate that to give an illusion of many different asteroids
/// ENTITY

class Entity {
protected:
	sf::Vector2f position;		// (x, y) position coordinates of the entity
	sf::Vector2f velocity;		// (x, y) velocity of the entity
	sf::Vector2f acceleration;		// (x, y) acceleration of the entity

private:
	sf::Texture tex;
	sf::Sprite spr;

public:
	Entity();
	Entity(sf::Texture in_tex);
	Entity(sf::Texture in_tex, sf::Vector2f in_position);
	sf::Vector2f get_position() const { return position; }
	sf::Vector2f get_velocity() const { return velocity; }
	sf::Vector2f get_acceleration() const { return acceleration; }
	sf::Texture get_tex() const { return tex; }
	sf::Sprite get_spr() const { return spr; }

	void set_position(sf::Vector2f in_position) { position = in_position; }
	void set_velocity(sf::Vector2f in_velocity) { velocity = in_velocity; }
	void set_acceleration(sf::Vector2f in_acceleration) { acceleration = in_acceleration; }
	void set_tex(sf::Texture in_tex) { tex = in_tex; }
};

