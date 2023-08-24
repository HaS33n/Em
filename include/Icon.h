#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Icon : public sf::Drawable
{
public:
	Icon(std::string name, sf::Texture& tx, sf::Vector2f Position, float scale);
	void dragIcon(const sf::Event& event); //te¿ bêdzie podwójnym klikniêciem
	void display(sf::RenderWindow& tW);

	std::string name;
	bool openAppPlz;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void startApp();


	sf::Clock clock;
	sf::Time t1;

	
	sf::Sprite sprite;

	bool isBeingDragged;
	sf::Vector2f dragOffset;

	
	
};

