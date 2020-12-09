#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Game.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "THE FEELING YOU GET FROM A COCA COLA :("); 
    window.setFramerateLimit(50);

    sf::Texture tex_ship;
    if (!tex_ship.loadFromFile("Assets/Ship.png")) std::cout << "Hi" << std::endl;

    Game game;

    game.get_ship().set_tex(tex_ship);
    
    sf::Clock clock;
    //sf::Time current_time = clock.getElapsedTime();  // time elapsed
    //sf::Time last_time = clock.getElapsedTime();     // time elapsed before this loop
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

        game.update(dt.asSeconds() * 10);

        window.clear();

        window.draw(game.get_ship().get_spr());

        window.display();
    }

	return 0;
}