#include "..\include\TaskbarIcon.h"

TaskbarIcon::TaskbarIcon(std::string name, sf::Texture& tx, sf::Vector2f Position, float scale) {
    openAppPlz = false;
    this->name = name;
    sprite.setSize(sf::Vector2f(30, 30));
    sprite.setScale(scale, scale);
    sprite.setTexture(&tx);
    sprite.setPosition(Position);
}

void TaskbarIcon::onClick(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            startApp();
        }
    }
}

void TaskbarIcon::display(sf::RenderWindow& tW) {
    tW.draw(sprite);
}

void TaskbarIcon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite);
}

void TaskbarIcon::startApp() {
    std::cout << "starting app from taskbar icon: " << name << std::endl;
    openAppPlz = true;
}

