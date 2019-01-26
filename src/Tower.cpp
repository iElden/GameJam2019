//
// Created by Andgel on 25/01/2019.
//

#include <cmath>
#include <iostream>
#include "Logger.hpp"
#include "Tower.hpp"

gtd::Tower::Tower(const unsigned &cost,
		  const Type &type,
		  const sf::SoundBuffer &sBuffer,
		  const gtd::Sprite &sprite,
		  const sf::Vector2u &pos,
		  const double &displayedRange,
		  const std::string &name) :
	_pos(pos),
	_sBuff(sBuffer),
	_type(type),
	_displayedRange(displayedRange),
	_sprite(sprite),
	_name(name),
	_cost(cost)
{
	this->_sound.setBuffer(this->_sBuff);
	logger.info("Added new tower \"" + this->_name + "\"");
}

void	gtd::Tower::display(gtd::Screen &screen)
{
	if (this->_isSelected) {
		screen.fillColor(sf::Color(0, 0, 0, 75));
		screen.displayElement(this->_displayedRange * 32, sf::Vector2f((this->_pos.x - this->_displayedRange + 0.5f) * 32, (this->_pos.y - this->_displayedRange + 0.5f) * 32));
	}
	this->_sprite._sprite.setRotation(this->_angle);
	this->_sprite._sprite.setTextureRect(sf::IntRect(0, 0, this->_sprite.getSize().x, this->_sprite.getSize().y));
	this->_sprite.display(screen, sf::Vector2f(this->_pos.x * 32, this->_pos.y * 32));
}

unsigned	gtd::Tower::getLevel()
{
	return this->_level;
}

unsigned	gtd::Tower::getCost()
{
	return this->_cost;
}

gtd::Tower::Type	gtd::Tower::getType()
{
	return this->_type;
}

std::string	gtd::Tower::getName()
{
	return this->_name;
}

double	gtd::Tower::getDistanceTo(const sf::Vector2f &pt)
{
	return sqrt(pow(pt.x - this->_pos.x, 2) + pow(pt.y - this->_pos.y, 2));
}

sf::Vector2f	gtd::Tower::getPosition()
{
	return (sf::Vector2f(this->_pos.x, this->_pos.y));
}

bool	gtd::Tower::isSelected()
{
	return this->_isSelected;
}

void	gtd::Tower::select()
{
	this->_isSelected = !this->_isSelected;
}