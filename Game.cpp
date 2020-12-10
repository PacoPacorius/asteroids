#include "Game.h"
#include <iostream>

Game::Game(){
	ship.set_tex(textures.ship);
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

	ship.input(dt);

}

void Game::create_asteroid() {

	std::unique_ptr<Asteroid> asteroid(new Asteroid(textures.asteroid));
	asteroids.push_back(std::move(asteroid));
	

}