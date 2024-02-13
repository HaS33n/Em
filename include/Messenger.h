#pragma once
#include "Application.h"
class Messenger :
    public Application
{
public:
    Messenger(std::string title, sf::Vector2f size, sf::Font& fnt, float scale, ResourceManager& RMRF);
    //virtual void handleClickables(sf::Vector2f pos) override;
    //void displayCurrentNode();
    //void switchNode(int id);
    void refreshApp() override;
private:
    std::vector <std::shared_ptr<ClickableAppEntity>> avatars;

    unsigned short int current_page;
};

