//
// Created by Andgel on 25/01/2019.
//

#include <iostream>
#include "Logger.hpp"
#include "Sprite.hpp"

gtd::Sprite::Sprite(const std::string &path, const sf::Vector2u &size) :
	_texture(),
	_size(size),
	_isLoaded(false)
{
	this->_isLoaded = this->_texture.loadFromFile(path);
	if (this->_isLoaded)
		this->_sprite.setTexture(this->_texture);
	else
		logger.error("Cannot load file " + path);
}

void	gtd::Sprite::display(gtd::Screen &screen, const sf::Vector2f &pos)
{
	if (this->_isLoaded) {
		screen.displayElement(this->_sprite, pos);
	} else {
		screen.fillColor(sf::Color(255, 0, 255));
		screen.displayElement(sf::IntRect(pos.x, pos.y, this->_size.x, this->_size.y));
	}
}

sf::Vector2u	gtd::Sprite::getSize() const
{
	return this->_size;
}

gtd::Sprite::~Sprite()
{
	std::cout << "Deleted Sprite !" << std::endl;
}