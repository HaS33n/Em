#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "ClickableAppEntity.h"
#include <vector>

using json = nlohmann::json;

/*
todo:

renderujemy wszystko na RenderTexture, któr¹ nak³adamy potem na Spirte "window". Mo¿na u¿yæ jakieœ unorderedmap zawieraj¹cej
wskazniki na klasy dziedziczace po sf::Drawable i wtedy metoda Display() nie bêdzie musia³a byæ przys³aniana.
*/


//30px bar
class Application : public sf::Drawable
{
public:
	Application(std::string title, sf::Vector2f size, sf::Font& fnt, float sc);
	virtual ~Application(){}
	virtual void display(sf::RenderWindow& tW);
	virtual sf::Sprite& getSprite();
	virtual sf::RenderTexture& getSpriteTexture();
	virtual void dragWindow(const sf::Event& event);
	virtual std::string getName();
	virtual void handleClickables(sf::Vector2i pixel);
	virtual void refreshApp(); 
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	float scale;
	sf::RenderTexture baseTX;
	sf::Sprite window;
	std::string name; //check it

	sf::Font& font;
	bool isBeingDreagged;
	sf::Vector2f dragOffset;

	std::vector <std::shared_ptr<ClickableAppEntity>> clickables;
};

