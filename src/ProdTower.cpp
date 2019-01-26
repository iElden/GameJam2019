//
// Created by Andgel on 25/01/2019.
//

#include "ProdTower.hpp"

gtd::ProdTower::ProdTower(const gtd::Food::Type &type,
			  const double &speed,
			  const int &value,
			  const unsigned &cost,
			  const sf::SoundBuffer &sBuffer,
			  const gtd::Sprite &sprite,
			  const sf::Vector2u &pos,
			  const double &displayedRange,
			  const std::string &name) :
	gtd::Tower(cost, gtd::Tower::Production, sBuffer, sprite, pos, displayedRange, name),
	_prodType(type),
	_prodSpeed(speed),
	_value(value)
{
}

void	gtd::ProdTower::prod(const float &seconds)
{
	if (this->_buffer <= this->_prodSpeed)
		this->_buffer = 0;
	else
		return;
}

void	gtd::ProdTower::update(const float &timeSpent)
{
	this->_buffer += timeSpent;
}