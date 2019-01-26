//
// Created by Andgel on 25/01/2019.
//

#include "ProdTower.hpp"

gtd::ProdTower::ProdTower(const gtd::Food::Type &type,
			  const double &speed,
			  const int &value,
			  const unsigned &cost,
			  const sf::SoundBuffer &sBuffer,
			  gtd::Sprite *sprite,
			  const sf::Vector2u &pos,
			  const double &displayedRange,
			  const std::string &name) :
	gtd::Tower(cost, gtd::Tower::Production, sBuffer, sprite, pos, displayedRange, name),
	_prodType(type),
	_prodSpeed(speed),
	_value(value)
{
}

void	gtd::ProdTower::prod(gtd::Food &stock)
{
	if (this->_buffer >= 60. / this->_prodSpeed)
		this->_buffer = 0;
	else
		return;
	stock.stock[this->_prodType] += this->_value;
}

void	gtd::ProdTower::update()
{
	this->_buffer += 1;
}

void	gtd::ProdTower::resetBuffs()
{
	this->_prodSpeed	/= this->_asBuff;
	this->_value		/= this->_dmgBuff;
	this->_asBuff	= 1;
	this->_dmgBuff	= 1;
}

void	gtd::ProdTower::buff(const double &as, const double &dmg, const double &range)
{
	(void)range;
	this->_prodSpeed	*= as;
	this->_asBuff		*= as;
	this->_value		*= dmg;
	this->_dmgBuff		*= dmg;
}

void	gtd::ProdTower::upgrade(int level)
{
	this->_value += 0.5 * level;
	if (level > 0)
		this->_prodSpeed *= (1 + level * 20. / 100);
	else
		this->_prodSpeed /= (1 + level * 20. / 100);
	this->_level += level;
}