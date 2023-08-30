#include "..\include\GameManager.h"
GameManager::GameManager(sf::RenderWindow& window) : m_window(window){
	
	SM.setFont(RM.loadFont("arial"));
	iS = 1.25;
	SM.setScale(iS);
	float sx, sy;
	sx = float(sf::VideoMode::getDesktopMode().width) / float(3840);
	sy = float(sf::VideoMode::getDesktopMode().height) / float(2160);
	bg.setScale(sx, sy); 
	bg.setTexture(RM.loadTexture("background")); //true

	clk.Init(RM.loadFont("arial"), iS);
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
	if (key == sf::Keyboard::Escape) 
		m_window.close();
		
	else if (key == sf::Keyboard::Key::RAlt)
		SM.addApp("Terminal");
	else if (key == sf::Keyboard::RShift)
		SM.killApp("Terminal");

	std::cout << key << std::endl;
}

void GameManager::updateWindow() {
	m_window.clear(sf::Color::White);
	m_window.draw(bg);
	
	for (auto& it : SM.apps) {
		it.second->refreshApp();
		it.second->display(m_window);
	}

	m_window.draw(clk);
	m_window.display();
	
}

void GameManager::updateSM() {
	for (auto& it : SM.apps) {
		it.second->dragWindow(event);
	}
}