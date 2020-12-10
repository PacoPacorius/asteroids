#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>

class Textures
{
	void load_texture(sf::Texture& tex, std::string path) {
		if (!tex.loadFromFile(path)) std::cout << "!!!!Error loading texture: " << path << std::endl;
	}

public:
	sf::Texture ship;
	sf::Texture asteroid;
	sf::Texture bullet;

	Textures() {
		load_texture(ship, "Assets/Ship.png");
		load_texture(asteroid, "Assets/Asteroid.png");
		load_texture(bullet, "Assets/Bullet.png");
	}

};


