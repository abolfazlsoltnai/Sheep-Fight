#include "header.hpp" 
#include "buttons.hpp"
#include "arrowPointers.hpp"



class Game{
    private:
       RenderWindow GameWindow; 
       Sprite backgroung_main;
       Texture background;
       arrowPointer rightpointer;
       arrowPointer leftpointer;
    public:
        Game():GameWindow(VideoMode(1080, 720), "Sheep fight"),backgroung_main(),rightpointer("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/vectors/arrow_decorative_w_small.png",1000),leftpointer("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/vectors/arrow_decorative_e.png",40){

            background.loadFromFile("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/background/background_main.png");
            backgroung_main.setTexture(background);
            get_image_fit(GameWindow,background,backgroung_main);

        }

         RenderWindow* getWindow(){
            return &GameWindow;
        }
        
        bool do_state_1(){
            return state_1();
            
        }
        void clean(){
            GameWindow.clear();

        };

        bool state_1(){
            Texture background;
            background.loadFromFile("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/background/background_start.png");
            Sprite background_sprite;
            background_sprite.setTexture(background);
            get_image_fit(GameWindow,background,background_sprite);
            Vector2u position_of_window = GameWindow.getSize();

            Button BTN(position_of_window.x/2-100,position_of_window.y/2-100,300,100,"START THE GAME");
           return state_1_run(BTN,background_sprite);
        }
        bool state_1_run(Button BTN,Sprite background_sprite){
            bool clicked = 0;

        sf::Vector2i mousePos = sf::Mouse::getPosition(GameWindow);


        Event event;
        while (GameWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                GameWindow.close();

        }

        if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(GameWindow);
                    if (BTN.isClicked(mousePos))
                    {
                        clicked = 1;
                    }
                    
        }}
        






        BTN.handleHover(mousePos,GameWindow);
        GameWindow.clear();
        GameWindow.draw(background_sprite);
        BTN.draw(GameWindow);

        GameWindow.display();
        sf::Vector2i mousePos2 = sf::Mouse::getPosition(GameWindow);      
        
        if (clicked == 1)
        {
           return 1;
        }else{
            return 0;
        }
        
    
    }


    Sprite InGameInitialize();
    void InGame();
   
    

};