//
// Created by Andgel on 25/01/2019.
//

#include <Logger.hpp>
#include "Tower.hpp"

gtd::Tower::Tower(const sf::SoundBuffer &sBuffer, const gtd::Sprite &sprite, const sf::Vector2u &pos, const double &displayedRange, const std::string &name) :
	_displayedRange(displayedRange),
	_sprite(sprite),
	_sBuff(sBuffer),
	_pos(pos),
	_name(name)
{
	this->_sound.setBuffer(this->_sBuff);
	logger.info("Added new tower \"" + this->_name + "\"");
}

void gtd::Tower::display(gtd::Screen &screen)
{
	//TODO Pad pos
	//TODO Change anim
	//this->_sprite.setIntRect(sf::Vector2u(0, 0));
	this->_sprite.display(screen, sf::Vector2f(this->_pos.x, this->_pos.y));
}

unsigned gtd::Tower::getLevel()
{
	return this->_level;
}

unsigned gtd::Tower::getCost()
{
	return this->_cost;
}

gtd::Tower::Type gtd::Tower::getType()
{
	return this->_type;
}

std::string gtd::Tower::getName()
{
	return this->_name;
}