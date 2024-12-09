#include "GameMenu.hpp"
#include <iostream>
using namespace std;
void Game::InGame(){
     Event event;

    GameWindow.draw(backgroung_main);

        while (GameWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                GameWindow.close();
             if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::S) {
                        leftpointer.displacement(1);

                } else if (event.key.code == sf::Keyboard::W) {
                        leftpointer.displacement(-1);
                    
                } else if (event.key.code == sf::Keyboard::Down) {
                        rightpointer.displacement(1);
                } else if (event.key.code == sf::Keyboard::Up) {
                        rightpointer.displacement(-1);
                    
                }
            }
        }

       
        leftpointer.draw(GameWindow);
        rightpointer.draw(GameWindow);

    GameWindow.display();



}
