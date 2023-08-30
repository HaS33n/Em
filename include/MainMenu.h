#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "ResourceManager.h"
#include "Terminal.h"
#include "Clock.h"


class MainMenu //68 wierszy siê miesci w CMD, 1440-30=1410 || 1410/68 = 20.7
{
public:
	MainMenu(sf::RenderWindow& window);
	void runMenu();

private: 
	void updateWindow();

	Clock clk;

	sf::RectangleShape pswdbox, pbttn, speaker, pwrbttn, sttngs, conn, batt; //toppanel;
	sf::CircleShape avtr;
	sf::Text usrname, ptxt, psswd;
	sf::VertexArray toppanel;

	sf::Event event;
	ResourceManager RM;
	sf::RenderWindow& m_window;
	sf::Sprite bg;
	sf::Shader blurshader;
	float iS;


	sf::Clock timer;
	sf::Time t1;
	bool startSequence;
	bool changeScreens, fc;
	sf::RectangleShape BBB;
};




