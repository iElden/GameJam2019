//
// Created by Andgel on 25/01/2019.
//

#include <Logger.hpp>
#include "Tower.hpp"

gtd::Tower::Tower(const gtd::Sprite &sprite, const sf::Vector2u &pos, const double &displayedRange, const std::string &name) :
	_displayedRange(displayedRange),
	_sprite(sprite),
	_pos(pos),
	_name(name)
{
	logger.info("Added new tower \"" + this->_name + "\"");
}

void gtd::Tower::display(gtd::Screen &screen)
{
	//this->_sprite.setIntRect(sf::Vector2u(0, 0));
	this->_sprite.display(screen, sf::Vector2f(this->_pos.x, this->_pos.y));
}