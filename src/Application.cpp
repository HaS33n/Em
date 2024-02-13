 #include "..\include\Application.h"

Application::Application(std::string title, sf::Vector2f size, sf::Font& fnt, float sc) : name(title), font(fnt)
{
	isBeingDreagged = false;
    scale = sc;
    clickable_output = -2; //nic nie ma przy -2; wartoœæ bazowa??

	baseTX.create(size.x* scale,(size.y * scale) + (25*scale));
	baseTX.clear(sf::Color::Black);
	
    /*
	sf::RectangleShape bar(sf::Vector2f(size.x * scale, 25 * scale));
	bar.setFillColor(sf::Color::White);

    sf::Text txt;
    txt.setString(title);
    txt.setCharacterSize(20 * scale);
    txt.setFillColor(sf::Color::Black);
    txt.setFont(fnt);
    txt.setOrigin(sf::Vector2f(txt.getLocalBounds().width / 2, txt.getLocalBounds().height / 2));
    txt.setPosition(sf::Vector2f(size.x * scale / 2, bar.getSize().y));

	baseTX.draw(bar);
    baseTX.draw(txt);
    */

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

void Application::handleClickables(sf::Vector2f pos) {

    short int buffer = -2;
    for (auto& it : Content) {
        buffer = it->isClicked(pos, window.getPosition());
        if (buffer > -1)
            clickable_output = buffer;
        
    }
            

    
}

void Application::refreshApp() {
    baseTX.clear(sf::Color::Black);
    sf::RectangleShape bar(sf::Vector2f(baseTX.getSize().x * scale, 25 * scale));
    bar.setFillColor(sf::Color::White);

    sf::Text txt;
    txt.setString(name);
    txt.setCharacterSize(20 * scale);
    txt.setFillColor(sf::Color::Black);
    txt.setFont(font);
    txt.setOrigin(sf::Vector2f(txt.getLocalBounds().width / 2, txt.getLocalBounds().height / 2));
    txt.setPosition(sf::Vector2f(baseTX.getSize().x / 2, bar.getSize().y / 4 ));

    baseTX.draw(bar);
    //baseTX.draw(txt);
    

    // to wyzej robi obramowke okna
    //to nizej wyswietla reszte szajsu

    for (auto& it : Content) {
        baseTX.draw(*it->getObject());
     }

    baseTX.display();
 }

void Application::addClickable(sf::Drawable* clkb, bool active, int index) {
   int id = index;
   if (index == -1)
       id = 0 - Content.size(); //rzeczy nie wymagaj¹ce indexowania maj¹ ujemne staty, co w sumie ju¿ zwalnia z u¿ywania active ale chuj z tym, niech bedzie

    if (dynamic_cast<sf::Text*>(clkb)) {
       /*
        sf::Text* np = dynamic_cast<sf::Text*>(clkb);
        np->setPosition(sf::Vector2f(0, 30 * scale + Content.size() * 30));
        Content.push_back(std::make_shared<ClickableAppEntity>(active, id, *np));
        */


        sf::Text* np = dynamic_cast<sf::Text*>(clkb);
        float additionalOffset = 0;
        if (!Content.empty()) {
            if (dynamic_cast<sf::Text*>(Content.back()->getObject())) {
                sf::Text* buffptr = dynamic_cast<sf::Text*>(Content.back()->getObject());
                additionalOffset = buffptr->getGlobalBounds().top - 10; //to jest dziwne i nie wiem czemu dzia³a, zrobi³em to przypadkiem
            }

            else if (dynamic_cast<sf::RectangleShape*>(Content.back()->getObject())) {

            }
            
        }
            

        sf::Vector2f newpos(0, (30 * scale) + additionalOffset);
        np->setPosition(newpos);
        Content.push_back(std::make_shared<ClickableAppEntity>(active, id, *np));
    }
        
    
    if (dynamic_cast<sf::RectangleShape*>(clkb)) { //to samo tu co wyzej
        sf::RectangleShape* np = dynamic_cast<sf::RectangleShape*>(clkb);
        std::shared_ptr<ClickableAppEntity> test = std::make_shared<ClickableAppEntity>(active, id, *np);
        Content.push_back(test);
    }
     


}


