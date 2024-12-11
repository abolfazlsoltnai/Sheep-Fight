#include "header.hpp"
using namespace sf;

void get_image_fit(RenderWindow &window,Texture &backgroundTexture,Sprite &backgroundSprite){
    Vector2u textureSize = backgroundTexture.getSize();
    Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    float scale = std::min(scaleX, scaleY);
    backgroundSprite.setScale(scale, scale);
    sf::FloatRect spriteBounds = backgroundSprite.getGlobalBounds();
    backgroundSprite.setPosition(
        (windowSize.x - spriteBounds.width) / 2.f,
        (windowSize.y - spriteBounds.height) / 2.f
    );


}
