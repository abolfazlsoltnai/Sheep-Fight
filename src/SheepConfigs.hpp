#include "header.hpp"

class Sheeps{
        private:
            Texture image_file;
            Sprite image;
            int player;
            String name;
            int damage;
            int strength;
            float displayProb;     
        public:
            Sheeps(String name,int damage,int strength,float displayProb,int player,String url);
            
    };