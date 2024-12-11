#include "live.hpp"


live::live(float x,int color):liveDegree(Vector2f(40.f, -500.f)){
    if(color==1)
    liveDegree.setFillColor(Color::Red);

    if(color==2)
    liveDegree.setFillColor(Color::Blue);

    liveDegree.setPosition(x,720);



}

void live::draw(RenderWindow &window){
    window.draw(liveDegree);
}