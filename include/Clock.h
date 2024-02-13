#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class Clock : public sf::Drawable
{
public:
	void Init(sf::Font& fnt, float scale);
	void Init(sf::Font& fnt, float scale, sf::Vector2f pos, float size, sf::Color clr);
	void updateClock();
	sf::FloatRect getBounds() { return content.getLocalBounds(); }
	void setPos(sf::Vector2f pos) { content.setPosition(pos); }
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Text content;
};

