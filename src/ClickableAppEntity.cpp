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

ClickableAppEntity::ClickableAppEntity(unsigned short int no, sf::Text txt, sf::Vector2f pos) {
	number = no;
	rTX.create(txt.getLocalBounds().width, txt.getLocalBounds().height);
	rTX.clear();
	rTX.draw(txt);
	rTX.display();
	entity.setTexture(rTX.getTexture());
	entity.setPosition(pos);
}

unsigned short int ClickableAppEntity::isClicked(sf::Vector2i mousepos, sf::RenderTexture& trt) {
	if (entity.getGlobalBounds().contains(trt.mapPixelToCoords(mousepos))) {
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