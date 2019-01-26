//
// Created by Andgel on 25/01/2019.
//

#include "Mob.hpp"

gtd::Mob::Mob(const double &maxHealth, const double &ms, const sf::Vector2f &pos) :
	_pos(pos),
	_movementSpeed(ms),
	_health(maxHealth),
	_maxHealth(maxHealth)
{
}

void	gtd::Mob::move(const float &time)
{
}

void	gtd::Mob::takeDamage(const double &dmg)
{
	this->_health -= dmg;
}

bool	gtd::Mob::isFull()
{
	return (this->_health == 0);
}