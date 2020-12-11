#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>

class Textures
{
	void load_texture(sf::Texture& tex, std::string path) {
		if (!tex.loadFromFile(path)) std::cout << "!!!!Error loading texture: " << path << std::endl;
	}

public:
	sf::Texture ship;
	sf::Texture asteroid;
	sf::Texture bullet;
	std::vector<sf::Texture> asteroid_textures;
	sf::Font font;

	Textures() {
		load_texture(ship, "Assets/Ship.png");
		load_texture(asteroid, "Assets/Asteroid.png");
		load_texture(bullet, "Assets/Bullet.png");
			sf::Texture asteroid_texture1;
			sf::Texture asteroid_texture2;
			sf::Texture asteroid_texture3;
			sf::Texture asteroid_texture4;
			sf::Texture asteroid_texture5;
			load_texture(asteroid_texture1, "Assets/Asteroid.png");
			load_texture(asteroid_texture2, "Assets/Asteroid2.png");
			load_texture(asteroid_texture3, "Assets/Asteroid3.png");
			load_texture(asteroid_texture4, "Assets/Asteroid4.png");
			load_texture(asteroid_texture5, "Assets/Asteroid5.png");
			asteroid_textures.push_back(asteroid_texture1);
			asteroid_textures.push_back(asteroid_texture2);
			asteroid_textures.push_back(asteroid_texture3);
			asteroid_textures.push_back(asteroid_texture4);
			asteroid_textures.push_back(asteroid_texture5);

			font.loadFromFile("Assets/PixelFJVerdana12pt.ttf");
	}

	sf::Texture& get_random_asteroid_texture() { return asteroid_textures[rand() % asteroid_textures.size()]; }
};


