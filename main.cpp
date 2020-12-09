#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Game.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "THE FEELING YOU GET FROM A COCA COLA :("); 

    sf::Texture tex_ship;
    if (!tex_ship.loadFromFile("Assets/Ship.png")) std::cout << "Hi" << std::endl;

    Game game;

    game.get_ship().set_tex(tex_ship);
    
    
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

        game.update();

        window.clear();

        window.draw(game.get_ship().get_spr());

        window.display();
    }

	return 0;
}