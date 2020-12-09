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

	ship.input(dt);

}