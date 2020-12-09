#include "Game.h"
#include <iostream>

Game::Game(){
}

void Game::update(float dt){
	//WRAP SHIP
	if (ship.get_position().x > (int)WINDOW_WIDTH + 10) 
		ship.set_position(sf::Vector2f(-30, ship.get_position().y));
	else if (ship.get_position().x < -30)
		ship.set_position(sf::Vector2f((int)WINDOW_WIDTH + 10, ship.get_position().y));

	if (ship.get_position().y > (int)WINDOW_HEIGHT + 10)
		ship.set_position(sf::Vector2f(ship.get_position().x, -30));
	else if (ship.get_position().y < -30)
		ship.set_position(sf::Vector2f(ship.get_position().x, (int)WINDOW_HEIGHT + 10));
	std::cout << "x: " << ship.get_position().x << std::endl << "y: " << ship.get_position().y << std::endl;

	ship.movement(dt * 10);		// it works better with * 10 shut up sysk

}

void Game::create_asteroid(sf::Texture tex) {
	Asteroid asteroid(tex);
	asteroid.set_tex(tex);
	asteroids.push_back(asteroid);
}