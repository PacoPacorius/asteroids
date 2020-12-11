#include "Game.h"
#include <iostream>
#include <stdlib.h>

Game::Game() {
	ship.set_tex(textures.ship);
	player_score_text.setFont(textures.font);
	player_score_text.setPosition(30, 40);
	player_score_text.setScale(0.7, 0.7);
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
				//sf::Vector2f new_velocity = { bullets[i].get_velocity().y/10.f, -bullets[i].get_velocity().x/10.f };
				if (asteroids[j].get_scale() > 0.8) {
					sf::Vector2f v1 = { ((rand() % 1000) - 500) / 5.f, ((rand() % 1000) - 500) / 5.f };
					sf::Vector2f v2 = { ((rand() % 1000) - 500) / 5.f, ((rand() % 1000) - 500) / 5.f };

					Asteroid asteroid1(textures.get_random_asteroid_texture(), asteroids[j].get_position(), v1);
					Asteroid asteroid2(textures.get_random_asteroid_texture(), asteroids[j].get_position(), v2);
					asteroid1.set_scale(asteroids[j].get_scale() * 0.7 * (1.f - ((rand() % 3) / 10.f)));
					asteroid2.set_scale(asteroids[j].get_scale() * 0.7 * (1.f - ((rand() % 3) / 10.f)));
					asteroids.push_back(asteroid1);
					asteroids.push_back(asteroid2);
				}

				player_score += 20;
				asteroids.erase(asteroids.begin() + j);
				if (j == asteroids.size()) break;
				bullets.erase(bullets.begin() + i);

			}

		}
	}
	player_score_text.setString(std::to_string(player_score));

	//deletion of out-of-bounds objects
	for (unsigned int i = 0; i < asteroids.size(); i++) {
		if (is_out_of_bounds(asteroids[i])) { asteroids.erase(asteroids.begin() + i); std::cout << "deleted asteroid" << std::endl; }
	}
	for (unsigned int i = 0; i < bullets.size(); i++) {
		if (is_out_of_bounds(bullets[i])) { bullets.erase(bullets.begin() + i); std::cout << "deleted bullet" << std::endl; }
	}

}

void Game::create_asteroid(unsigned int number_of_asteroids, float scale) {

	//create asteroid at random place outside screen
	for (unsigned int i = 0; i < number_of_asteroids; i++) {
		Asteroid asteroid(textures.get_random_asteroid_texture());
		asteroid.set_scale(scale);
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
	float R = c1.getRadius()*c1.getScale().x + c2.getRadius()*c2.getScale().y;
	
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

