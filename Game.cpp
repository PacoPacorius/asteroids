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

	for (int i = 0; i < asteroids.size(); i++) { 
		asteroids[i].update(dt); 	
	}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update(dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if ( ship.can_fire() ) {
			Bullet bullet(textures.bullet, ship);
			bullets.push_back(bullet);
		}
	}

	//deletion of out-of-bounds objects
	for (unsigned int i = 0; i < asteroids.size(); i++) {
		if (is_out_of_bounds(asteroids[i])) { asteroids.erase(asteroids.begin() + i); std::cout << "deleted asteroid" << std::endl; }
	}
	for (unsigned int i = 0; i < bullets.size(); i++) {
		if (is_out_of_bounds(bullets[i])) { bullets.erase(bullets.begin() + i); std::cout << "deleted bullet" << std::endl; }
	}

}

void Game::create_asteroid(unsigned int number) {

	//create asteroid at random place outside screen
	for (unsigned int i = 0; i < number; i++) {
		Asteroid asteroid(textures.asteroid);

		/*	
		*	* * * * * * * * * * * * * *
		*	* HERE'S THE PLAN MY DUDE *
		*	* * * * * * * * * * * * * *
		* 
		*  1. generate random numbers 17 - 49 (17 because of the origin point, 49 because anything more than 50 off the edge will get immediately deleted
		* 
		*  2. generate another set of numbers 0 - 3 which will determine on which side of the screen the asteroids will spawn
		* 
		*  3. depending on the side of the screen subtract from zero or add the numbers to the window dimensions
		* 
		*  4. generate a random angle at which the asteroids will fly towards (will take into account which side of the screen the asteroid is)
		*  NOTE: I should probs test out which angles mean which directions, I know that degrees are clockwise but does up mean -45 to 45 or 0 to 90?
		* 
		*  5. give the asteroids a velocity using the code from the bullets and ship movement
		* 
		*  6. profit
		*/

		asteroid.set_velocity({ (std::rand() % 1000) / 10.f, (std::rand() % 1000) / 10.f });		// sets a random velocity for each of the asteroids
		asteroids.push_back(asteroid);
	}

}

bool Game::is_out_of_bounds(const Entity entity) {

	return (entity.get_position().x < -50 ||
		entity.get_position().x > WINDOW_WIDTH + 50 ||
		entity.get_position().y < -50 ||
		entity.get_position().y > WINDOW_HEIGHT + 50);
	}