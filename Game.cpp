#include "Game.h"
#include <iostream>
#include <stdlib.h>
	
Game::Game(){
	ship.set_tex(textures.ship);
}

void Game::update(float dt){
	//WRAP SHIP
	if (ship.get_position().x > (int)WINDOW_WIDTH + 20) 
		ship.set_position(sf::Vector2f(-20, ship.get_position().y));
	else if (ship.get_position().x < -20)
		ship.set_position(sf::Vector2f((int)WINDOW_WIDTH + 20, ship.get_position().y));

	if (ship.get_position().y > (int)WINDOW_HEIGHT + 20)
		ship.set_position(sf::Vector2f(ship.get_position().x, -20));
	else if (ship.get_position().y < -20)
		ship.set_position(sf::Vector2f(ship.get_position().x, (int)WINDOW_HEIGHT + 20));

	ship.movement(dt * 10);		// it works better with * 10 shut up syskAXAAXAXAXAX

	for (int i = 0; i < asteroids.size(); i++) asteroids[i].update(dt);

}

void Game::create_asteroid(unsigned int number) {

	//create asteroid at random place outside screen
	for (int i = 0; i < number; i++) {
		Asteroid asteroid(textures.asteroid);

		asteroid.set_velocity({ (std::rand() % 1000) / 10.f, (std::rand() % 1000) / 10.f });
		asteroids.push_back(asteroid);
	}

}