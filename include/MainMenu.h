#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "ResourceManager.h"
#include "Terminal.h"

class MainMenu //68 wierszy siê miesci w CMD, 1440-30=1410 || 1410/68 = 20.7
{
public:
	MainMenu(sf::RenderWindow& window);
	~MainMenu() { delete MMTerminal; }
	void runMenu();

private:
	void updateWindow();

	sf::Event event;
	ResourceManager RM;
	sf::RenderWindow& m_window;
	sf::Sprite bg;
	sf::Shader blurshader;
	float iS;

	Terminal* MMTerminal;
	
	
};



