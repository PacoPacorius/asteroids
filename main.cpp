#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "THE FEELING YOU GET FROM A COCA COLA :("); 

    sf::Texture tex_ship;
    if (!tex_ship.loadFromFile("Assets/Ship.png")) std::cout << "Hi" << std::endl;

    Player ship(tex_ship, sf::Vector2f(250.f, 300.f));
    
    
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
        window.clear();

        window.draw(ship.get_spr());

        window.display();
    }

	return 0;
}