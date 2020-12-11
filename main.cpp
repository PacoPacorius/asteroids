#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Textures.h"
#include "Game.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "THE FEELING YOU GET FROM A COCA COLA :("); 
    window.setFramerateLimit(500);

    Game game;


    game.create_asteroid(3, 3.f);
 
    


    sf::Clock clock;
    sf::Time dt = clock.getElapsedTime();            // time of this loop only
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        dt = clock.restart();

        game.update(dt.asSeconds());

        window.clear();

        window.draw(game.get_ship().get_spr());
       // window.draw(game.get_ship().get_collision_circle());

        for (int i = 0; i < game.get_asteroids().size(); i++) {
            window.draw(game.get_asteroids()[i].get_spr());
         //   window.draw(game.get_asteroids()[i].get_collision_circle());

        }
        for (int i = 0; i < game.get_bullets().size(); i++) {
            window.draw(game.get_bullets()[i].get_spr());
           // window.draw(game.get_bullets()[i].get_collision_circle());
        }

        window.draw(game.get_player_score_text());

        window.display();
    }

	return 0;
}