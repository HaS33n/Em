#include "..\include\Terminal.h"
Terminal::Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, bool mom,float scale) : Application(title,size,fnt,scale) { 
	
	menuOperationMode = mom;
	if (mom) {
		//loading dialogueTree
		currentNode = 1;
		std::ifstream file("mm.atrf");
		if (!file.is_open()) {
			std::cout << "Failed to open main menu critical files" << std::endl;
			return;
		}

		//init function map
		//fMap["audio"] = handleAudioSettings;



		std::string line;
		//variables for node
		int nodeId;
		std::string text;
			
		while (std::getline(file, line)) {
			//text.clear();
			if (line.empty()) {
				continue;
			}

			if (line[0] == '#') {  // Comment line
				continue;
			}

			if (line[0] == '@') {  // Node ID line
				nodeId = std::stoi(line.substr(1));

				menuDialogues[nodeId] = DialogueNode();
			}
			else if (line[0] == '>') {  // Text line
				text = line.substr(1);
				menuDialogues[nodeId].text = text;
			}
			else if (line[0] == '!') { //Function Line, implement later
				menuDialogues[nodeId].isFunctionNode = true;
				menuDialogues[nodeId].fName = line.substr(1);
			}
			else {  // Choice line
				
					size_t separatorPos = line.find(':');
					size_t slashPos = line.find('/');

					std::string choiceText = line.substr(0, slashPos);
					std::string choiceCommand = line.substr(slashPos + 1, separatorPos - slashPos - 1); //out of range exception kurwa jego maæ

					unsigned short int targetNodeId = std::stoi(line.substr(separatorPos + 1));

					menuDialogues[nodeId].choicemap[std::make_pair(choiceText, choiceCommand)] = targetNodeId;
								
				
			}
		}

		file.close();
	}
	sf::Text buff("CarrotPie Operating system, Version 2.13.7", font, 16 * scale); //B-52 kappa
	buff.setFillColor(sf::Color::White);
	sf::Drawable* dw = new sf::Text(buff);
	addClickable(dw, false);
	delete dw;
	displayCurrentNode();

}

Terminal::Terminal(std::string title, sf::Vector2f size, sf::Font& fnt, bool mom, float scale, mINI::INIFile* cfg, mINI::INIStructure* dat) : Terminal(title,size,fnt,mom,scale)
{
	settings = cfg;
	data = dat;
}

void Terminal::dragWindow(const sf::Event& event) {
	if (!menuOperationMode) {
		if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// Check if the mouse is over the sprite
			if (window.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
			{
				isBeingDreagged = true;
				dragOffset = sf::Vector2f(event.mouseButton.x, event.mouseButton.y) - window.getPosition();
			}
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			isBeingDreagged = false;
		}
		else if (event.type == sf::Event::MouseMoved && isBeingDreagged)
		{
			// Update the sprites position while it is being dragged
			window.setPosition(sf::Vector2f(event.mouseMove.x, event.mouseMove.y) - dragOffset);
		}
	}
}

void Terminal::handleClickables(sf::Vector2f pos){
	Application::handleClickables(pos);
	if (clickable_output > -1 && clickable_output != currentNode) //zjebane z lekka te warunki
		switchNode(clickable_output);
}

void Terminal::displayCurrentNode()
{
	std::cout << "current node = " << currentNode << std::endl;
	const DialogueNode& displayedNode = menuDialogues.at(currentNode); //tu siê wypierdala jak nie trafisz z kliknieciem 300
	sf::Text buff(displayedNode.text, font, 16 * scale); //B-52 kappa
	buff.setFillColor(sf::Color::White);
	sf::Drawable* dw = new sf::Text(buff);
	if (displayedNode.text.size() > 0)
		addClickable(dw, false);

	delete dw;

	buff.setString("root@UwU: /home/H3n ");
	dw = new sf::Text(buff);
	addClickable(dw, false);
	delete dw;

	buff.setFillColor(sf::Color::Yellow); //tu
	for (auto& it : displayedNode.choicemap) {
		buff.setString(it.first.first);
		sf::Drawable* dw = new sf::Text(buff);
		addClickable(dw, true, it.second); //id entity to tak naprawde adres node na którego wskazuje XD
		delete dw;
	}



}//to jest chyba memory leak XD

void Terminal::switchNode( int id)
{
	const DialogueNode& displayedNode = menuDialogues.at(currentNode);
	Content.pop_back();
	for (int i = 0; i < displayedNode.choicemap.size(); i++)
		Content.pop_back();

	std::string cmmd;


	for (auto& it : displayedNode.choicemap) { //nie widze innej opcji zeby to zrobiæ, wiem, ze wyglada to okropnie (i dzia³a tak samo uhhh)
		if (it.second == id)
			cmmd = it.first.second;
	}

	//wypisaæ komende; w przyszy³oœci jeszcze animacje wpisywania tego chujstwa
	sf::Text buff("root@UwU: /home/H3n# " + cmmd, font, 16 * scale);
	buff.setFillColor(sf::Color::White);
	sf::Drawable* dw = new sf::Text(buff);
	addClickable(dw, false);
	delete dw;

	
	if (displayedNode.isFunctionNode == true) { //switch case
		if (displayedNode.fName == "handleScaleSettings") {
			//settings["Graphical"]["framerateLimit"] = std::to_string(id);
			(*data)["Graphical"]["interfaceScale"] = std::to_string(static_cast<float>(id) /100.f); // XD kurwa
			Content.pop_back();

			buff.setString("root@UwU: /home/H3n# " + cmmd); //+ " " + std::to_string(id));
			sf::Drawable* dw = new sf::Text(buff);
			addClickable(dw, false);
			delete dw;
			
			settings->write(*data);
			currentNode = 31;
			clickable_output = 31;
			
			goto skip;
		}
			
		
	}



	currentNode = id;

	skip:
	displayCurrentNode();


}

void Terminal::handleAudioSettings(const std::string& arg)
{
	std::cout << "nigger";

}
// i tu te¿ XD

//void Terminal::refreshApp() {
	//clearContent();
	//Application::refreshApp();

//}

