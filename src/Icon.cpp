#include "..\include\Icon.h"

Icon::Icon(std::string name, sf::Texture& tx, sf::Vector2f Position, float scale) {
    openAppPlz = false;
	this->name = name;
	isBeingDragged = false;
    sprite.setScale(scale,scale);
	sprite.setTexture(tx);
    sprite.setPosition(Position);
    t1 = sf::milliseconds(0);
}

void Icon::dragIcon(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Check if the mouse is over the sprite
        if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            isBeingDragged = true;
            dragOffset = sf::Vector2f(event.mouseButton.x, event.mouseButton.y) - sprite.getPosition();

            // podwojne klikniecie
            if(t1==sf::milliseconds(0))
                t1 = clock.getElapsedTime();

            else {
                sf::Time t2 = clock.getElapsedTime();
                if ((t2 - t1) <= sf::milliseconds(300)) 
                    startApp();
                
                t1 = t2;
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
        isBeingDragged = false;
    }
    else if (event.type == sf::Event::MouseMoved && isBeingDragged)
    {
        // Update the sprite's position while it is being dragged
        sprite.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - dragOffset);
    }
}

void Icon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}

void Icon::display(sf::RenderWindow& tW) {
    tW.draw(sprite);
}

void Icon::startApp() {
    std::cout << "starting app: " << name << std::endl;
    openAppPlz = true;
}