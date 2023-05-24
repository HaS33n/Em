#include "..\include\ClickableAppEntity.h"

ClickableAppEntity::ClickableAppEntity(unsigned short int no, sf::Texture& tx, sf::Vector2f pos) {
	number = no;
	entity.setTexture(tx);
	entity.setPosition(pos);
}

ClickableAppEntity::ClickableAppEntity(unsigned short int no, sf::RectangleShape rs, sf::Vector2f pos) {
	number = no;
	rTX.create(rs.getSize().x, rs.getSize().y);
	rTX.clear();
	rTX.draw(rs);
	rTX.display();
	entity.setTexture(rTX.getTexture());
	entity.setPosition(pos);
}

ClickableAppEntity::ClickableAppEntity(unsigned short int no, sf::Text& txt, sf::Vector2f pos) {
	number = no;
	rTX.create(txt.getLocalBounds().width, txt.getLocalBounds().height * 1.5);
	rTX.clear(sf::Color::Black);
	rTX.draw(txt);
	rTX.display();
	entity.setTexture(rTX.getTexture());
	entity.setPosition(pos);
}

short int ClickableAppEntity::isClicked(sf::Vector2f mousepos) {
	sf::FloatRect bounds = entity.getGlobalBounds();

	//std::cout << "bounds: " << bounds.left << "," << bounds.top << std::endl;
	//std::cout << "mousepos: " << mousepos.x << "," << mousepos.y << std::endl;

	if (bounds.contains(mousepos)) {
		std::cout<<"clicked entity no: "<<number<<std::endl;
		return number;
	}

	return -1;
}

void ClickableAppEntity::display(sf::RenderTexture& tT) {
	tT.draw(entity);
}

void ClickableAppEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(entity);
}