#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class TaskbarIcon : public sf::Drawable
{
public:
	TaskbarIcon(std::string name, sf::Texture& tx, sf::Vector2f Position, float scale);
	void display(sf::RenderWindow& tW);
	void onClick(const sf::Event& event);

	std::string name;
	bool openAppPlz;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void startApp();
	sf::RectangleShape sprite;
};

