#include "..\include\GameManager.h"
GameManager::GameManager(sf::RenderWindow& window) : m_window(window), settings("settings.ini") {
	settings.read(data);

	m_window.setFramerateLimit(stoi(data["Graphical"]["framerateLimit"])); //invalid argument
	SM.setFont(RM.loadFont("arial"));
	iS = stof(data["Graphical"]["interfaceScale"]);
	SM.setScale(iS);
	float sx, sy;
	sx = float(sf::VideoMode::getDesktopMode().width) / float(3840);
	sy = float(sf::VideoMode::getDesktopMode().height) / float(2160);
	bg.setScale(sx, sy); 

	taskbar.setSize(sf::Vector2f(sf::VideoMode::getDesktopMode().width, 40 * iS));
	taskbar.setFillColor(sf::Color::White);
	taskbar.setPosition(sf::Vector2f(0, sf::VideoMode::getDesktopMode().height - (40 * iS)));

	starticon.setSize(sf::Vector2f(40 * iS, 40 * iS));
	starticon.setTexture(&RM.loadTexture("starticon"));
	starticon.setPosition(sf::Vector2f(0, sf::VideoMode::getDesktopMode().height - (40 * iS)));

	RM.loadTexture("background");
	bg.setTexture(RM.loadTexture("background")); //true
	
	SM.addIcon("Messenger", RM.loadTexture("Messenger"), sf::Vector2f(50,50),iS,false);
	SM.addIcon("Terminal", RM.loadTexture("Terminal"), sf::Vector2f(80, 80),iS,false);

	clk.Init(RM.loadFont("arial"), iS);

	ss.create(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
}

sf::RenderWindow& GameManager::GetWindow() {
	return m_window;
}

void GameManager::runGame() {
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				ss.update(m_window);
				ss.copyToImage().saveToFile("mmbg.png");
				m_window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
					handleMouse(sf::Mouse::getPosition(m_window));
				break;
			case sf::Event::KeyPressed:
				handleKeyboard(event.key.code);
				break;
			default:
				break;
			}
			updateSM();

		}
		clk.updateClock();
		updateWindow();
	}
}

void GameManager::handleMouse(sf::Vector2i mousepos) {
	std::cout << mousepos.x << " " << mousepos.y << std::endl;

	SM.handleMouse(m_window.mapPixelToCoords(mousepos));
		
}

void GameManager::handleKeyboard(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Escape) {
		ss.update(m_window);
		ss.copyToImage().saveToFile("mmbg.png");
		std::cout << "ss'ed the screen" << std::endl;
		m_window.close();
	}
		
	else if (key == sf::Keyboard::Key::RAlt)
		SM.addApp("Terminal");
	else if (key == sf::Keyboard::RShift)
		SM.killApp("Terminal");
	else if (key == sf::Keyboard::T) {
		if (SM.slctd != nullptr) {
			SM.addIcon(SM.slctd->getName(), RM.loadTexture(SM.slctd->getName()), sf::Vector2f(0, 0), iS, true);
		}
	}
	else if (key == sf::Keyboard::D) {
		//if (SM.slctd != nullptr)
			//SM.slctd->addClickable();
	}
		

	std::cout << key << std::endl;
}

void GameManager::updateWindow() {
	m_window.clear(sf::Color::White);
	m_window.draw(bg);
	
	for (auto& it : SM.icons) {
		it.second->display(m_window);
	}

	for (auto& it : SM.apps) {
		it.second->refreshApp();
		it.second->display(m_window);
	}

	m_window.draw(taskbar);

	for (auto& it : SM.taskbaricons) {
		it.second->display(m_window);
	}

	m_window.draw(starticon);
	m_window.draw(clk);
	m_window.display();
	
}

void GameManager::updateSM() {
	SM.testIcons();
	for (auto& it : SM.apps) {
		it.second->dragWindow(event);
	}
	for (auto& it : SM.icons) {
		it.second->dragIcon(event);
	}
	for (auto& it : SM.taskbaricons) {
		it.second->onClick(event);
	}
}