#pragma once
#include "Application.h"
#include "Icon.h"
#include "Messenger.h"
#include "Terminal.h"
#include "TaskbarIcon.h"
#include <unordered_map>
#include <iostream>
enum class appType{mess,terminal};
class ShitManager
{
public:
	friend class GameManager;
	ShitManager();
	void setFont(sf::Font& fnt) { mainfont = fnt; }
	void setScale(float s) { iS = s; }
	void addApp(std::string name);
	void killApp(std::string name);
	void handleMouse(sf::Vector2f mousepos, sf::Vector2i pixelmousepos);
	void testIcons();
	void addIcon(std::string iname, sf::Texture& itx, sf::Vector2f iPosition, float scale, bool isTaskbar);
private:
	float iS;

	sf::Font mainfont;

	std::unordered_map<std::string, std::shared_ptr<Application>> apps;
	std::unordered_map<std::string, std::shared_ptr<Icon>> icons;
	std::unordered_map<std::string, std::shared_ptr<TaskbarIcon>> taskbaricons;
	std::shared_ptr<Application> slctd;

};

