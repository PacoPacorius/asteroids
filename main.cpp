#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Textures.h"
#include "Game.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "THE FEELING YOU GET FROM A COCA COLA :("); 
    window.setFramerateLimit(130000000);

    Game game;

    sf::Clock clock;
    sf::Time dt;            // time of this loop only

    while (window.isOpen())
    {
        if (game.get_player_lives_sprites().size() > 0) {
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

            for (int i = 0; i < game.get_player_lives_sprites().size(); i++) window.draw(game.get_player_lives_sprites()[i]);


            window.draw(game.get_player_score_text());

            window.display();
        }
        else if (game.get_player_lives_sprites().size() < 1) {
            window.clear();
            sf::Text endScreenText;
            endScreenText.setFont(game.get_textures().font);
            endScreenText.setString("GAME OVER");      // \nSCORE: " + game.get_player_score_text().getString()
            sf::Text scoreText = game.get_player_score_text();
            scoreText.setString("SCORE: " + scoreText.getString());
            scoreText.setScale(.7f, .7f);
            endScreenText.setPosition((1024 - endScreenText.getLocalBounds().width) / 2, 300);
            scoreText.setPosition((1024 - scoreText.getLocalBounds().width*scoreText.getScale().x) / 2, 300 + endScreenText.getLocalBounds().height + 20);
            window.draw(endScreenText);
            window.draw(scoreText);
            window.display();

            sf::Event event;    
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
    }

	return 0;
}