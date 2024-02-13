#include "..\include\ClickableAppEntity.h"

 int ClickableAppEntity::isClicked(sf::Vector2f mousepos, sf::Vector2f winpos) {
    if (!isActive)
        return -1;

    if (dynamic_cast<sf::Shape*>(cnt)) {
        sf::FloatRect bounds = dynamic_cast<sf::Shape*>(cnt)->getGlobalBounds();
        if (bounds.contains(mousepos - winpos)) {
            std::cout << "clicked entity: " << number << std::endl;
            return number;
        }
    }

    if (dynamic_cast<sf::Text*>(cnt)) {
        sf::FloatRect bounds = dynamic_cast<sf::Text*>(cnt)->getGlobalBounds();
        if (bounds.contains(mousepos - winpos)) {
            std::cout << "clicked entity: " << number << std::endl;
            return number;
        }
    }

    /*
    sf::FloatRect bounds = dynamic_cast<sf::Shape&>(*cnt).getGlobalBounds();
    if (bounds.contains(mousepos - winpos)) {
        std::cout << "clicked entity: " << number << std::endl;
        return number;
    }
    */

	return -1;
}