#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "ClickableAppEntity.h"
#include <vector>
#include <unordered_map>

using json = nlohmann::json;


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
	virtual void handleClickables(sf::Vector2f pos);
	virtual void refreshApp(); 
	virtual sf::RenderTexture& getBTX() { return baseTX; }
	virtual void addClickable(sf::Drawable* clkb, bool active, int index = -1);
	virtual void removeClickable() {}; //do usuniecia ig?
	virtual inline void clearContent() { Content.clear(); }

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	 int clickable_output;

	float scale;
	sf::RenderTexture baseTX;
	sf::Sprite window;
	std::string name; //check it

	sf::Font& font;
	bool isBeingDreagged;
	sf::Vector2f dragOffset;

	//std::unordered_map<unsigned int, std::shared_ptr<sf::Drawable>> Content;

	std::vector <std::shared_ptr<ClickableAppEntity>> Content;
};

