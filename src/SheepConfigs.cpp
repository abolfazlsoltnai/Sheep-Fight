#include "SheepConfigs.hpp"

Sheeps::Sheeps(String name,int damage,int strength,float displayProb,int player,String url):
image_file(),image(){

    image_file.loadFromFile(url);
    image.setTexture(image_file);
    name = name;
    player = player;
    damage = damage;
    strength = strength;
    displayProb = displayProb;
    // image.setScale(10,10);
    // image.setPosition(200,200);
}
Sprite Sheeps::get_sprite(){
    return image;
}
void Sheeps::set_sprite_position(float x,float y){
    image.setPosition(x,y);
}