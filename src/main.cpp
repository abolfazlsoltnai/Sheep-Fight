#include "header.hpp"
#include <iostream>
#include "GameMenu.hpp"
using namespace sf;


enum GameState
{
  StateMenu = 1,
  StateInGame,
  StatePuased,
  StateFinished
};

enum GameState gamestate = StateMenu;



int main(){
    Game *GameWindow = new Game();
    
    while (GameWindow->getWindow()->isOpen())
    {
        if (gamestate == StateMenu)
        {
          if (GameWindow->do_state_1())
          {
            
            GameWindow->clean();
            gamestate = StateInGame;          
          }
          
        }


        if (gamestate == StateInGame)
        {
          GameWindow->InGame();
        }
        





        
    }
    
    

}