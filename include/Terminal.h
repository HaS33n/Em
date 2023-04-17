#pragma once
#include "Application.h"


class Terminal :
    public Application
{
public:
    Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, bool mom, float scale);
    sf::Sprite& getSprite() { return window; }
    void addClickable();
    virtual void dragWindow(const sf::Event& event) override;

private:
    bool menuOperationMode;
    unsigned int row_coutner;
};

