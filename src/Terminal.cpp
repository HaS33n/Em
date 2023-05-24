#include "..\include\Terminal.h"
Terminal::Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, bool mom,float scale) : Application(title,size,fnt,scale){
	if (mom) {
		sf::RectangleShape aBar(sf::Vector2f(size.x * scale, 15 * scale));
		aBar.setFillColor(sf::Color::Green);
		aBar.setPosition(sf::Vector2f(0, 30 * scale));
		baseTX.draw(aBar);
		
		baseTX.display();
	}
		
	menuOperationMode = mom;
	row_coutner = 0;
}

void Terminal::addClickable() {
	
	sf::RectangleShape rs;
	rs.setFillColor(sf::Color::Red);
	rs.setSize(sf::Vector2f(50, 50));
	clickables.push_back(std::make_shared<ClickableAppEntity>(clickables.size(), rs, sf::Vector2f(0, 30 * scale + clickables.size() * 50)));
	clickables[clickables.size() - 1]->display(baseTX);
	
	/*
	sf::Text txt;
	txt.setString("Nigger OS!");
	txt.setCharacterSize(15 * scale);
	txt.setFillColor(sf::Color::White);
	txt.setFont(font);
	clickables.push_back(std::make_shared<ClickableAppEntity>(clickables.size(), txt, sf::Vector2f(0, 30*scale + clickables.size()*20*scale)));
	*/

}

void Terminal::dragWindow(const sf::Event& event) {
	if (!menuOperationMode) {
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

	/*else
		if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2f p = baseTX.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
			if (event.mouseButton.x <= window.getGlobalBounds().width / 2 && event.mouseButton.y >= 20 * scale && event.mouseButton.y <= (35 * scale)) //kliknieto w buttona
				std::cout << "clicked button no. " << static_cast<int>(event.mouseButton.x / (window.getLocalBounds().width * scale / 12)) << std::endl;

		}
	*/
}

