#pragma once
#include "ShitManager.h"
#include "ResourceManager.h"
#include "Clock.h"
#include "ini.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

class GameManager
{
public:
    GameManager(sf::RenderWindow& window);
    sf::RenderWindow& GetWindow();
    void runGame();

private:
    ShitManager SM;
    ResourceManager RM;

    void updateWindow();
    void updateSM();
    void handleMouse(sf::Vector2i mousepos);
    void handleKeyboard(sf::Keyboard::Key key);

    float iS; //skala interface'u
    Clock clk;
    sf::RenderWindow& m_window;
    sf::Event event;
    sf::Sprite bg;
};