#pragma once
//#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

class Bullet : public Entity {
private:
	float VELOCITY = 1000.f;
	sf::CircleShape collision_circle;
	
 
public:
	Bullet();
	Bullet(sf::Texture& bullet_tex);
	Bullet(sf::Texture& bullet_tex, sf::Vector2f in_position, sf::Vector2f in_velocity);
	Bullet(sf::Texture& bullet_tex, Player& player);

	void update(float dt);

	void set_scale(float scale) { spr.setScale(scale, scale); collision_circle.setScale(scale, scale); }
	sf::CircleShape& get_collision_circle() { return collision_circle; }
};