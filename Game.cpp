#define _USE_MATH_DEFINES

#define MAX_ASTEROIDS 11

#include "Game.h"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Game::Game() {
	srand(time(NULL));
  
	player_lives = 6;
	sf::Sprite live_sprite;
	live_sprite.setTexture(textures.ship);
	live_sprite.setPosition(20, 60);
	live_sprite.setScale(0.7f, 0.7f);
	player_lives_sprites.push_back(live_sprite);
	for (unsigned int i = 0; i < player_lives; i++) {
		live_sprite.move(30, 0);
		player_lives_sprites.push_back(live_sprite);
	}


	ship.set_tex(textures.ship);
	player_score_text.setFont(textures.font);
	player_score_text.setPosition(20, 30);
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
			ship.set_position({ WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f });
			ship.set_velocity({ 0.f, 0.f });
			player_lives--;
			player_lives_sprites.pop_back();
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

	//regeneration of asteroids
	if (asteroids.size() < MAX_ASTEROIDS) {
		create_asteroid(MAX_ASTEROIDS - asteroids.size(), 3.f);
	}

}



float degrees_to_radians(float degrees); /*{
	return (degrees * M_PI) / 180;
}*/

void Game::create_asteroid(unsigned int number_of_asteroids, float scale) {

	//create asteroid at random place outside screen
	for (unsigned int i = 0; i < number_of_asteroids; i++) {
		Asteroid asteroid(textures.get_random_asteroid_texture());
		asteroid.set_scale(scale);

		/*	
		*	* * * * * * * * * * * * * *
		*	* HERE'S THE PLAN MY DUDE *
		*	* * * * * * * * * * * * * *
		* 
		*  1. generate random numbers 21 - 49 (21 because of player screen wrapping, 49 because anything more than 50 off the edge will get immediately deleted)
		* 
		*  2. generate another set of numbers 0 - 3 which will determine on which side of the screen the asteroids will spawn (LEFT: 0, UP: 1, RIGHT: 2, DOWN: 3)
		* 
		*  3. depending on the side of the screen subtract from zero or add the numbers to the window dimensions
		* 
		*  4. generate a random angle at which the asteroids will fly towards (will take into account which side of the screen the asteroid is)
		*  NOTE: I should probs test out which angles mean which directions, I know that degrees are clockwise but does up mean -45 to 45 or 0 to 90?
		* 
		*  5. give the asteroids a velocity using the code from the bullets and ship movement
		* 
		*  6. profit
		* 
		*  Coordinates that are allowed for each side:		===============================================
		*												   |	 |         x 	     |           y         |
		*												   |LEFT |-49 - -21          |-49 - HEIGHT+20      |
		*												   |UP   |-20 - WIDTH+49     |-49 - -21			   |
		*												   |RIGHT|WIDTH+21 - WIDTH+49|-20 - HEIGHT+49      |
		*												   |DOWN |-49 - WIDTH+20     |HEIGHT+21 - HEIGHT+49|
		*												    ===============================================
		*/		

		float temp_x, temp_y;
		float radians, degrees, absolute_velocity = std::rand() % 1000 / 10.f + 10.f;
		
		Sides side = Sides(rand() % 4);		// pick a random side

		switch (side) {												// POSITIONAL AND ANGULAR HELL
		case LEFT:
			temp_x = (-1) * (rand() % 29 + 21);
			temp_y = rand() % (WINDOW_HEIGHT + 20 + 49 + 1) - 49;
			degrees = rand() % (91) + 90 - 45;
			break;
		case UP:
			temp_x = rand() % (WINDOW_WIDTH + 49 + 20 + 1) - 20;
			temp_y = (-1) * (rand() % 29 + 21);
			degrees = rand() % (91) + 180 - 45;
			break;
		case RIGHT:
			temp_x = rand() % 29 + 21 + WINDOW_WIDTH;
			temp_y = rand() % (WINDOW_HEIGHT + 49 + 20 + 1) - 20;
			degrees = rand() % (91) + 270 - 45;
			break;
		case DOWN:
			temp_x = rand() % (WINDOW_WIDTH + 20 + 49 + 1) - 49;
			temp_y = rand() % 29 + 21 + WINDOW_HEIGHT;
			degrees = rand() % (91) - 45;
			break;
		}

		radians = degrees_to_radians(degrees);

		asteroid.set_position({ temp_x, temp_y });
		asteroid.set_velocity({ absolute_velocity * sin(radians), -absolute_velocity * cos(radians) });		// sets a random velocity for each of the asteroids
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



// directions:
// 0 is up
// 90 is to the right
// 180 is down
// 270 is 

// lefts still go left?

