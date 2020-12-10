#pragma once
#include "SFML/Graphics.hpp"
class Textures
{
	
public:
	sf::Texture ship;
	sf::Texture asteroid;
	sf::Texture bullet;

	Textures() {
		ship.loadFromFile("Assets/Ship.png");
		asteroid.loadFromFile("Assets/Asteroid.png");
		bullet.loadFromFile("Assets/Bullet.png");
	}

};


