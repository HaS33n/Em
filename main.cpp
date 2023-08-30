#include <SFML/Graphics.hpp>
#include "include\GameManager.h"
#include "include\MainMenu.h"
#include <iostream>

int main() 
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Marocaust", sf::Style::Fullscreen);
	MainMenu* MM = new MainMenu(window);
	MM->runMenu();
	delete MM;
	if (!window.isOpen())
		return 0;
	GameManager GM(window);
	GM.runGame();

	return 0;
}