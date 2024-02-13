#pragma once
#include "Application.h"
#include "Messenger.h"
#include "Terminal.h"
#include <unordered_map>
#include <iostream>
enum class appType{mess,terminal};
class ShitManager
{
public:
	friend class GameManager;
	ShitManager(float scale, ResourceManager &RMR);
	void setFont(sf::Font& fnt) { mainfont = fnt; }
	void setScale(float s) { iS = s; }
	void addApp(std::string name);
	void killApp(std::string name);
	void handleMouse(sf::Vector2f mousepos);
private:
	float iS;

	sf::Font mainfont;
	ResourceManager& RMRF;
	std::unordered_map<std::string, std::shared_ptr<Application>> apps;
	std::shared_ptr<Application> slctd;

};

