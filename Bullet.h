#pragma once
//#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"

class Bullet : public Entity {
private:
	sf::CircleShape collision_circle;
	
 
public:
	Bullet();
	Bullet(sf::Texture bullet_tex);
	Bullet(sf::Texture bullet_tex, sf::Vector2f in_position, sf::Vector2f in_velocity);
	Bullet(Player& player);
	
	sf::CircleShape get_collision_circle() { return collision_circle; }
};