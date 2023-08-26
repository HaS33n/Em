#include "..\include\MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& window) : m_window(window){
	
	startSequence = false;
	m_window.setVerticalSyncEnabled(true);
	iS = 1.25;
	t1 = sf::milliseconds(0);


	//toppanel
	toppanel.setPrimitiveType(sf::Quads);
	sf::Vertex v1, v2, v3, v4;
	
	v1.color=sf::Color(75, 73, 67);
	v2.color = sf::Color(75, 73, 67);
	v3.color = sf::Color(75, 73, 67);
	v4.color = sf::Color(75, 73, 67);

	v1.position = sf::Vector2f(sf::VideoMode::getDesktopMode().width / 4, 0);
	v2.position = sf::Vector2f(v1.position.x+(30*iS),25*iS);
	v3.position = sf::Vector2f(sf::VideoMode::getDesktopMode().width * 0.75 - (30 * iS), 25 * iS);
	v4.position = sf::Vector2f(sf::VideoMode::getDesktopMode().width * 0.75, 0);

	toppanel.append(v1);
	toppanel.append(v2);
	toppanel.append(v3);
	toppanel.append(v4);
	//zegar
	clk.Init(RM.loadFont("arial"), iS, sf::Vector2f(v2.position.x, 0), 20, sf::Color::White);
	clk.setPos(sf::Vector2f((sf::VideoMode::getDesktopMode().width / 2) - (clk.getBounds().width / 2), 0));
	//ikony na toppanelu
	pwrbttn.setSize(sf::Vector2f(21, 21));
	pwrbttn.setScale(iS, iS);
	pwrbttn.setPosition(sf::Vector2f(v3.position.x - pwrbttn.getGlobalBounds().width,3));
	pwrbttn.setTexture(&RM.loadTexture("poweroff"));

	sttngs.setSize(sf::Vector2f(21, 21));
	sttngs.setScale(iS, iS);
	sttngs.setPosition(sf::Vector2f(pwrbttn.getGlobalBounds().left - sttngs.getSize().x - (30 * iS), 3));
	sttngs.setTexture(&RM.loadTexture("settings"));

	speaker.setSize(sf::Vector2f(21, 21));
	speaker.setScale(iS, iS);
	speaker.setPosition(sf::Vector2f(sttngs.getGlobalBounds().left - speaker.getSize().x - (30 * iS), 3));
	speaker.setTexture(&RM.loadTexture("speaker3"));

	conn.setSize(sf::Vector2f(21, 21));
	conn.setScale(iS, iS);
	conn.setPosition(sf::Vector2f(speaker.getGlobalBounds().left - conn.getSize().x - (30 * iS), 3));
	conn.setTexture(&RM.loadTexture("wifi"));

	batt.setSize(sf::Vector2f(21, 21));
	batt.setScale(iS, iS);
	batt.setPosition(sf::Vector2f(conn.getGlobalBounds().left - batt.getSize().x - (30 * iS), 3));
	batt.setTexture(&RM.loadTexture("battery"));

	//ekran logowania
	pswdbox.setFillColor(sf::Color::White);
	pswdbox.setOutlineColor(sf::Color(255, 140, 0));
	pswdbox.setOutlineThickness(3);
	pswdbox.setSize(sf::Vector2f(326,49));
	pswdbox.setScale(iS,iS);
	pswdbox.setOrigin(float(pswdbox.getGlobalBounds().width * 0.4f), float(pswdbox.getGlobalBounds().height *0.5f));
	pswdbox.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width * 0.5f, sf::VideoMode::getDesktopMode().height*0.6f));

	avtr.setRadius(40/0.625);
	avtr.setScale(iS, iS);
	avtr.setOrigin(float(avtr.getGlobalBounds().width * 0.4), float(avtr.getGlobalBounds().height *0.5));
	avtr.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width*0.5f, sf::VideoMode::getDesktopMode().height * 0.45f));
	avtr.setTexture(&RM.loadTexture("tux"));

	usrname.setFillColor(sf::Color::White);
	usrname.setString("Tuxie");
	usrname.setFont(RM.loadFont("arial"));
	usrname.setCharacterSize(35*iS);
	usrname.setOrigin(float(usrname.getGlobalBounds().width *0.5f), float(usrname.getGlobalBounds().height *0.5f));
	usrname.setPosition(sf::Vector2f(sf::VideoMode::getDesktopMode().width * 0.5f, sf::VideoMode::getDesktopMode().height * 0.52f));

	pbttn.setOutlineColor(sf::Color(255, 140, 0));
	pbttn.setOutlineThickness(3);
	pbttn.setFillColor(sf::Color(255, 140, 0));
	pbttn.setSize(pswdbox.getSize());
	pbttn.setScale(iS, iS);
	pbttn.setOrigin(float(pbttn.getGlobalBounds().width * 0.4f), float(pbttn.getGlobalBounds().height * 0.5f));
	pbttn.setPosition(pswdbox.getPosition());

	ptxt.setFillColor(sf::Color::White);
	ptxt.setString("Start");
	ptxt.setFont(RM.loadFont("arial"));
	ptxt.setCharacterSize(30 * iS);
	ptxt.setOrigin(float(ptxt.getGlobalBounds().width * 0.5f), float(ptxt.getGlobalBounds().height * 1.3f));
	ptxt.setPosition(pbttn.getPosition());

	psswd.setLetterSpacing(3);
	psswd.setFillColor(sf::Color::Black);
	psswd.setFont(RM.loadFont("arial"));
	psswd.setCharacterSize(40 * iS);
	psswd.setStyle(sf::Text::Bold);
	psswd.setPosition(pswdbox.getGlobalBounds().left+30, pswdbox.getGlobalBounds().top+10);


	
	bg.setTexture(RM.loadTexture("mmbg"));
	blurshader.loadFromFile("resources/shaders/blur.frag", sf::Shader::Type::Fragment);
	blurshader.setUniform("blur_radius", 0.008f); //0.008f
	
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
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if(pbttn.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
						startSequence=true;
				}
					
				break;
			default:
				break;
			}

		}
		clk.updateClock();
		updateWindow();

		
		
		if (startSequence) {
			t1 += timer.restart();;
			if (t1 > sf::milliseconds(30)) {
				psswd.setString(psswd.getString() + "*");
				t1 = sf::milliseconds(0);
			}
		}
		
		if (psswd.getString() == "*************")
			goto closemenu;



	}
closemenu:
	return;
}

void MainMenu::updateWindow() {
	m_window.clear(sf::Color::Black);
	m_window.draw(bg,&blurshader);
	//toppanel
	m_window.draw(toppanel);
	m_window.draw(clk);
	m_window.draw(speaker);
	m_window.draw(pwrbttn);
	m_window.draw(sttngs);
	m_window.draw(conn);
	m_window.draw(batt);
	//reszta
	m_window.draw(pswdbox);
	if (!startSequence) {
		m_window.draw(pbttn);
		m_window.draw(ptxt);
	}
	m_window.draw(avtr);
	m_window.draw(usrname);
	m_window.draw(psswd);
	m_window.display();
}
