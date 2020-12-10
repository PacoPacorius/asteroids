#include "Game.h"
#include <iostream>
#include <stdlib.h>

Game::Game() {
	ship.set_tex(textures.ship);
}

void Game::update(float dt) {
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
		if (ship.can_fire()) {
			Bullet bullet(textures.bullet, ship);
			bullets.push_back(bullet);
		}
	}

	//check collisions
	for (unsigned int j = 0; j < asteroids.size(); j++) {
		if (are_colliding(ship.get_collision_circle(), asteroids[j].get_collision_circle())) {
			//on asteroid-player collision

		}
		for (unsigned int i = 0; i < bullets.size(); i++) {
			if (are_colliding(bullets[i].get_collision_circle(), asteroids[j].get_collision_circle())) {
				//on asteroid-bullet collision
			}

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

		asteroid.set_velocity({ (std::rand() % 1000) / 10.f, (std::rand() % 1000) / 10.f });
		asteroids.push_back(asteroid);
	}

}

bool Game::is_out_of_bounds(const Entity entity) {

	return (entity.get_position().x < -50 ||
		entity.get_position().x > WINDOW_WIDTH + 50 ||
		entity.get_position().y < -50 ||
		entity.get_position().y > WINDOW_HEIGHT + 50);
}

bool Game::are_colliding(sf::CircleShape& c1, sf::CircleShape& c2) {
	float R = c1.getRadius() + c2.getRadius();
	
	sf::Vector2f P = c1.getPosition() - c2.getPosition();
	float P_length_squared = P.x * P.x + P.y * P.y;

	if (R * R > P_length_squared) {
		c1.setFillColor(sf::Color(255,100,100,100));
		c2.setFillColor(sf::Color(255, 100, 100, 100));
		return true;
	}
	else {
		c1.setFillColor(sf::Color(100, 100, 255, 100));
		c2.setFillColor(sf::Color(100, 100, 255, 100));
		return false;
	}
}

