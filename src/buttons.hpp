#include "header.hpp"
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;


class Button {
private:
    RectangleShape shape;
    Text text;
    Font font;
public:
    Button(float x, float y, float width, float height, const std::string& label) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color(22, 160, 133));

        font.loadFromFile("/home/abolfazl/Desktop/ramtung/4/src/fonts/MononokiNerdFont-BoldItalic.ttf");
       

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);

        sf::FloatRect textBounds = text.getLocalBounds();
        text.setPosition(
            x + (width - textBounds.width) / 2.f - textBounds.left,
            y + (height - textBounds.height) / 2.f - textBounds.top
        );
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
        window.draw(text);
    }

    bool isClicked(const sf::Vector2i& mousePos) const {
        return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    void handleHover(const sf::Vector2i& mousePos,RenderWindow &window) {
        sf::Cursor arrowCursor;
        sf::Cursor handCursor;

        arrowCursor.loadFromSystem(sf::Cursor::Arrow);
        handCursor.loadFromSystem(sf::Cursor::Hand);
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            shape.setFillColor(sf::Color::Green);
            window.setMouseCursor(handCursor);

        } else {
            shape.setFillColor(sf::Color(22, 160, 133)); 
            window.setMouseCursor(arrowCursor);   

        }
    }
};

