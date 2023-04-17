#include "..\include\Application.h"

Application::Application(std::string title, sf::Vector2f size, sf::Font& fnt, float sc) : name(title), font(fnt)
{
	isBeingDreagged = false;
    scale = sc;

	baseTX.create(size.x* scale,size.y * scale);
	baseTX.clear(sf::Color::Black);
	

	sf::RectangleShape bar(sf::Vector2f(size.x * scale, 30 * scale));
	bar.setFillColor(sf::Color::White);

    sf::Text txt;
    txt.setString(title);
    txt.setCharacterSize(20 * scale);
    txt.setFillColor(sf::Color::Black);
    txt.setFont(fnt);
    txt.setOrigin(sf::Vector2f(txt.getLocalBounds().width / 2, txt.getLocalBounds().height / 2));
    txt.setPosition(sf::Vector2f(size.x * scale / 2, bar.getSize().y / 2));

	baseTX.draw(bar);
    baseTX.draw(txt);
	baseTX.display();
	window.setTexture(baseTX.getTexture());
}

void Application::display(sf::RenderWindow& tW) {
	tW.draw(window);
}

sf::Sprite& Application::getSprite() {
	return window;
}

sf::RenderTexture& Application::getSpriteTexture() {
	return baseTX;
}

void Application::dragWindow(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // Check if the mouse is over the sprite
        if (window.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
        {
            isBeingDreagged = true;
            dragOffset = sf::Vector2f(event.mouseButton.x, event.mouseButton.y) - window.getPosition();
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
       isBeingDreagged = false;
    }
    else if (event.type == sf::Event::MouseMoved && isBeingDreagged)
    {
        // Update the sprites position while it is being dragged
        window.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - dragOffset);
    }
 }

void Application::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(window);
}

std::string Application::getName(){
    return name;
}

void Application::handleClickables(sf::Vector2i pixel) {
    for (auto& it : clickables) {
        std::cout<<it->isClicked(pixel, this->baseTX);
    }
}

void Application::refreshApp() {
    baseTX.clear(sf::Color::Black);
    sf::RectangleShape bar(sf::Vector2f(baseTX.getSize().x * scale, 30 * scale));
    bar.setFillColor(sf::Color::White);

    sf::Text txt;
    txt.setString(name);
    txt.setCharacterSize(20 * scale);
    txt.setFillColor(sf::Color::Black);
    txt.setFont(font);
    txt.setOrigin(sf::Vector2f(txt.getLocalBounds().width / 2, txt.getLocalBounds().height / 2));
    txt.setPosition(sf::Vector2f(baseTX.getSize().x * scale / 2, bar.getSize().y / 2));

    baseTX.draw(bar);
    baseTX.draw(txt);
    

    // to wyzej robi obramowke okna
    //to nizej wyswietla reszte szajsu

    for (auto& it : clickables) {
        it->display(baseTX);
     }

    baseTX.display();
 }


