#include "Player.hpp"
#include <cstdlib>
#include <ctime>



void Player::add_sheeps(Sheeps sheep){
    sheeps.push_back(sheep);


}

void Player::update_list_sheeps(){
    int randomNumber = rand() % 10 + 1 ;
    if (randomNumber > 0 && randomNumber <= 4 )
    {
        sheeps_ready_to_attack.erase(sheeps_ready_to_attack.begin());
        sheeps_ready_to_attack.push_back(sheeps[3]);
    }else if (randomNumber > 4 && randomNumber <= 7 )
    {
        sheeps_ready_to_attack.erase(sheeps_ready_to_attack.begin());
        sheeps_ready_to_attack.push_back(sheeps[2]);
    }else if (randomNumber > 7 && randomNumber <= 9 )
    {
        sheeps_ready_to_attack.erase(sheeps_ready_to_attack.begin());
        sheeps_ready_to_attack.push_back(sheeps[1]);
    }else if (randomNumber > 9 && randomNumber <= 10 )
    {
        sheeps_ready_to_attack.erase(sheeps_ready_to_attack.begin());
        sheeps_ready_to_attack.push_back(sheeps[0]);
    }
    
    if (type_player == 1)
    {
        sheeps_ready_to_attack[2].set_sprite_position(950,50);
        sheeps_ready_to_attack[1].set_sprite_position(850,50);
        sheeps_ready_to_attack[0].set_sprite_position(750,50);
        
    }else if(type_player == 2){
        sheeps_ready_to_attack[2].set_sprite_position(50,50);
        sheeps_ready_to_attack[1].set_sprite_position(150,50);
        sheeps_ready_to_attack[0].set_sprite_position(250,50);

    }
    

}

void Player::draw(RenderWindow &window){
    window.draw(sheeps_ready_to_attack[2].get_sprite());
    window.draw(sheeps_ready_to_attack[1].get_sprite());
    window.draw(sheeps_ready_to_attack[0].get_sprite());
    my_live.draw(window);
}

void Player::set_type_player(int x){
    type_player = x;
}

void Player::set_list_sheeps(){
    srand(std::time(0)); 
    int randomNumber = rand() % 4 ;
    sheeps_ready_to_attack.push_back(sheeps[randomNumber]);
    randomNumber = rand() % 4 ;
    sheeps_ready_to_attack.push_back(sheeps[randomNumber]);
    randomNumber = rand() % 4 ;
    sheeps_ready_to_attack.push_back(sheeps[randomNumber]);

    update_list_sheeps();

}


Player::Player(float x, int color):my_live(x,color){

}
