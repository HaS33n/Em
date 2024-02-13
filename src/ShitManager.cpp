#include "..\include\ShitManager.h"

ShitManager::ShitManager(float scale, ResourceManager& RMR) : RMRF(RMR) {
	iS = scale; //1 ????
}

void ShitManager::addApp(std::string name) {
	std::shared_ptr<Application> appptr; {
		if (name == "Messenger")
			appptr = std::make_shared<Messenger>(name,sf::Vector2f(800*iS,480*iS),mainfont,iS,RMRF);

		else if (name == "Terminal")
			appptr = std::make_shared<Terminal>(name, sf::Vector2f(440*iS, 280*iS),mainfont,iS);

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
