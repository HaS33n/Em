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
	void updateClock();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Text content;
};

