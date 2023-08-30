#pragma once
#include "Application.h"
#include "DialogueNode.h"
#include "ini.h"



class Terminal :
    public Application
{
public:
    

    Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, float scale);
    virtual void dragWindow(const sf::Event& event) override;
    virtual void handleClickables(sf::Vector2f pos) override;
    void displayCurrentNode();
    void switchNode( int id);

private:
    //tylko dla mom
     int currentNode;

    std::map<unsigned short int, DialogueNode> menuDialogues;

};

