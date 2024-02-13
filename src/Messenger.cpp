#include "..\include\Messenger.h"

Messenger::Messenger(std::string title, sf::Vector2f size, sf::Font& fnt, float scale, ResourceManager& RMRF) : Application(title,size,fnt,scale) {
    current_page = 0;
    
    //wyœwietla avatary
    sf::CircleShape av(32);
    av.setFillColor(sf::Color::White);
    av.setOrigin(av.getLocalBounds().width / 2, av.getLocalBounds().height / 2);


    for (int i = 0; i < 5; i++) {
        av.setTexture(&RMRF.loadTexture("av" + std::to_string(i+1)));
        av.setPosition(baseTX.getSize().x * 0.05, (baseTX.getSize().y - (25 * scale)) * (0.15 + 0.2*i));
        //avatars.push_back(av);
        avatars.push_back(std::make_shared<ClickableAppEntity>(true,i+1,av));

    }


}

void Messenger::refreshApp() { //czesciowa kopia z bazowej
	/*
	Application::refreshApp();
	sf::RectangleShape bg(sf::Vector2f(baseTX.getSize().x, baseTX.getSize().y - (25*scale)));
	bg.setFillColor(sf::Color(127, 127, 127));
	bg.setPosition(0, 25 * scale);
	*/

    baseTX.clear(sf::Color(127,127,127));
    sf::RectangleShape bar(sf::Vector2f(baseTX.getSize().x * scale, 25 * scale));
    bar.setFillColor(sf::Color::White);
    baseTX.draw(bar);

    sf::RectangleShape leftBar(sf::Vector2f(baseTX.getSize().x *0.1, baseTX.getSize().y - (25 * scale)));
    leftBar.setFillColor(sf::Color(40, 40, 40));
    leftBar.setPosition(0, 25 * scale);
    baseTX.draw(leftBar);

   
    //baseTX.draw(av1);

    for (auto it : avatars) {
        baseTX.draw(*it->getObject());
    }

    // to wyzej robi obramowke okna
    //to nizej wyswietla reszte szajsu

    for (auto& it : Content) {
        baseTX.draw(*it->getObject());
    }

    baseTX.display();
}
