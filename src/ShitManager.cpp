#include "..\include\ShitManager.h"

ShitManager::ShitManager() {
	iS = 1.25; //1 ????
}

void ShitManager::addApp(std::string name) {
	std::shared_ptr<Application> appptr; {
		if (name == "Messenger")
			appptr = std::make_shared<Messenger>(name,sf::Vector2f(550,350),mainfont,iS);

		else if (name == "Terminal")
			appptr = std::make_shared<Terminal>(name, sf::Vector2f(550, 350),mainfont,false,iS);

		if (appptr != nullptr) {
			apps[name] = appptr;
			slctd = appptr;
			std::cout << "App created: "<< name << std::endl;
		}
			
	}

}

void ShitManager::killApp(std::string name) {
	auto f = apps.find(name);
	if (f != apps.end()) {
		apps.erase(f);
		std::cout << "App destroyed: "<< name << std::endl;
		slctd = nullptr;
	}
		
	
}

void ShitManager::handleMouse(sf::Vector2f mousepos) {
	//wybieranie okna
	for (auto& it : apps) {
		sf::FloatRect bounds = it.second->getSprite().getGlobalBounds();
		if (bounds.contains(mousepos)) {
			slctd = it.second;
			std::cout << "selected: " << it.first << std::endl;

			it.second->handleClickables(mousepos);
			goto end;
		}
	}
end:
	return;
}

void ShitManager::testIcons() {
	for (auto& it : icons) {
		if (it.second->openAppPlz) {
			addApp(it.second->name);
			it.second->openAppPlz = false;
		}
	}

	for (auto& it : taskbaricons) {
		if (it.second->openAppPlz) {
			addApp(it.second->name);
			it.second->openAppPlz = false;
		}
	}
}

void ShitManager::addIcon(std::string iname, sf::Texture& itx, sf::Vector2f iPosition, float scale, bool isTaskbar) {
	if (!isTaskbar) {
		std::shared_ptr<Icon> ic = std::make_shared<Icon>(iname, itx, iPosition, scale);
		icons[iname] = ic;
		return;
	}
	float position = (taskbaricons.size()+1) * 40 * scale;
	sf::Vector2f v2fpos(position, sf::VideoMode::getDesktopMode().height - (40 * scale));
	std::shared_ptr<TaskbarIcon> tic = std::make_shared<TaskbarIcon>(iname, itx, v2fpos, scale);
	taskbaricons[iname] = tic;
}