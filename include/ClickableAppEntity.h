#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ClickableAppEntity 
{
public:
	ClickableAppEntity(bool actv,  int no, sf::Text txt) { isActive = actv; cnt = new sf::Text(txt); number = no; }
	ClickableAppEntity(bool actv,  int no, sf::RectangleShape shp) { isActive = actv; cnt = new sf::RectangleShape(shp); number = no; }
	ClickableAppEntity(bool actv, int no, sf::CircleShape cshp) { isActive = actv; cnt = new sf::CircleShape(cshp); number = no; }
	~ClickableAppEntity() { delete cnt; }
	int isClicked(sf::Vector2f mousepos, sf::Vector2f winpos);
	void setPos(sf::Vector2f pos);
	sf::Drawable* getObject() { return cnt; }
private:
	sf::Drawable* cnt;
	int number;
	bool isActive;
};

