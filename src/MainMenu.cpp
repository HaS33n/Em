#include "..\include\MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window) : m_window(window) {
	m_window.setFramerateLimit(300);
	bg.setTexture(RM.loadTexture("mmbg"));
	blurshader.loadFromFile("resources/shaders/blur.frag", sf::Shader::Type::Fragment);
	blurshader.setUniform("blur_radius", 0.008f); //0.008

	MMTerminal = new Terminal("root@UwU: /home/H3n", sf::Vector2f(600 * 16 / 9, 600),RM.loadFont("arial"),true,1.25); //450
	//MMTerminal->getSprite().setOrigin(sf::Vector2f(MMTerminal->getSprite().getLocalBounds().width / 2, MMTerminal->getSprite().getLocalBounds().height / 2));
	//MMTerminal->getSprite().setPosition(sf::VideoMode::getDesktopMode().width / static_cast<float>(2), sf::VideoMode::getDesktopMode().height / static_cast<float>(2));
	MMTerminal->getSprite().setPosition((m_window.getSize().x - MMTerminal->getSprite().getLocalBounds().width) / 2, (m_window.getSize().y - MMTerminal->getSprite().getLocalBounds().height) / 2);

	//std::cout << "enter interface scale: ";
	//std::cin >> iS;
}

void MainMenu::runMenu() {
	while (m_window.isOpen())
	{
		while (m_window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if(event.key.code == sf::Keyboard::Key::C)
					goto closemenu;

				if (event.key.code == sf::Keyboard::Key::D)
					MMTerminal->addClickable();
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << "terminal position: " <<MMTerminal->getSprite().getPosition().x<<","<< MMTerminal->getSprite().getPosition().y << std::endl;
					std::cout << "click position: " << sf::Mouse::getPosition(m_window).x << "," << sf::Mouse::getPosition(m_window).y << std::endl;
					MMTerminal->handleClickables(m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window)));
				}
					
				break;
			default:
				break;
			}

		}
		MMTerminal->dragWindow(event);
		updateWindow();
	}
closemenu:
	return;
}

void MainMenu::updateWindow() {
	MMTerminal->refreshApp();
	m_window.clear(sf::Color::Black);
	m_window.draw(bg,&blurshader);
	MMTerminal->display(m_window);
	m_window.display();
}
