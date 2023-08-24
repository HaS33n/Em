#pragma once
#include "Application.h"
#include "DialogueNode.h"
#include "ini.h"



class Terminal :
    public Application
{
public:
    

    Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, bool mom, float scale);
    Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, bool mom, float scale, mINI::INIFile* cfg, mINI::INIStructure* dat);
    virtual void dragWindow(const sf::Event& event) override;
    virtual void handleClickables(sf::Vector2f pos) override;
   // virtual void refreshApp() override;
    void displayCurrentNode();
    void switchNode( int id);


   
    void handleAudioSettings(const std::string& arg);

    //mINI::INIStructure& gtfocomp() { mINI::INIStructure* ptr = new mINI::INIStructure; return *ptr; } //XDDDDDDDDD


private:
    bool menuOperationMode;
    //tylko dla mom
     int currentNode;

    std::map<unsigned short int, DialogueNode> menuDialogues;
    //std::map<std::string, FPtr> fMap;

    mINI::INIFile* settings;
    mINI::INIStructure* data;

    

};

