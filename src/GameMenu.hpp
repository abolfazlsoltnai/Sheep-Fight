#include "header.hpp" 
#include "buttons.hpp"
#include "arrowPointers.hpp"
#include "Player.hpp"



class Game{
    private:
       RenderWindow GameWindow; 
       Sprite backgroung_main;
       Texture background;
       arrowPointer rightpointer;
       arrowPointer leftpointer;


       Player player1;
       Player player2;

       Sheeps blackGoat;
       Sheeps blackPig;
       Sheeps blackSheep;
       Sheeps boar;


       Sheeps cow;
       Sheeps pig;
       Sheeps ram;
       Sheeps whiteSheep;




    public:
        Game():GameWindow(VideoMode(1080, 720), "Sheep fight"),backgroung_main(),rightpointer("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/vectors/arrow_decorative_w_small.png",990),leftpointer("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/vectors/arrow_decorative_e.png",45),
        player1(0,1),player2(1040,2),


        blackGoat("blackgoat",100,100,0.4,2,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/black-goat/stand (1).png"),
        blackPig("blackPig",90,90,0.3,2,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/black-pig/stand (1).png"),
        blackSheep("blackSheep",80,80,0.2,2,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/black-sheep/stand.png"),
        boar("boar",70,70,0.1,2,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/boar/move.png"),



        cow("cow",100,100,0.4,1,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/cow/stand (1).png"),
        pig("pig",90,90,0.3,1,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/pig/stand (1).png"),
        ram("ram",80,80,0.2,1,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/ram/stand (1).png"),
        whiteSheep("whiteSheep",70,70,0.1,1,"/home/abolfazl/Desktop/ramtung/4/src/images/sprites/white-sheep/stand (1).png")

        
        {
            player1.set_type_player(1);
            player1.set_type_player(2);

            background.loadFromFile("/home/abolfazl/Desktop/ramtung/4/src/images/sprites/background/background_main.png");
            backgroung_main.setTexture(background);
            get_image_fit(GameWindow,background,backgroung_main);
            player1.add_sheeps(blackGoat);
            player1.add_sheeps(blackPig);
            player1.add_sheeps(blackSheep);
            player1.add_sheeps(boar);

            player2.add_sheeps(cow);
            player2.add_sheeps(pig);
            player2.add_sheeps(ram);
            player2.add_sheeps(whiteSheep);

            player1.set_list_sheeps();
            player2.set_list_sheeps();

            


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