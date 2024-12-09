#include "header.hpp"
#include <vector>




class arrowPointer{
    public:
        arrowPointer(String url,float x):image_file(),image(){
            image_file.loadFromFile(url);
            image.setTexture(image_file);
            current_x = x;
            current_y = y_param[0];


        }
        void draw(RenderWindow &window){
            image.setPosition(current_x,current_y);
            window.draw(image);
        }

        void displacement(int up){
                if(up == 1){
                    if(z != 4){
                        z++;
                        current_y = y_param[z];
                    }
                }else if (up == -1) {
                    if (z != 0)
                    {
                        z--;
                        current_y = y_param[z];
                    }
                    
                }
        }

    private:
        Texture image_file;
        Sprite  image;
        float current_x = 0;
        float current_y = 0;
        int z = 0;
        std::vector<int> y_param = {231, 325, 419, 515, 611};
        
};