#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class ClickableAppEntity : public sf::Drawable
{
public:
	ClickableAppEntity(unsigned short int no,sf::Texture& tx,sf::Vector2f pos);
	ClickableAppEntity(unsigned short int no, sf::RectangleShape rs, sf::Vector2f pos);
	ClickableAppEntity(unsigned short int no, sf::Text& txt, sf::Vector2f pos);
	short int isClicked(sf::Vector2f mousepos);
	void setPos(sf::Vector2f pos) { entity.setPosition(pos); }
	void display(sf::RenderTexture& tT);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::RenderTexture rTX;

	sf::Sprite entity;
	unsigned short int number;
};