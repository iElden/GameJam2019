//
// Created by Andgel on 25/01/2019.
//

#include "AtkTower.hpp"

gtd::AtkTower::AtkTower(const double &attackSpeed, const double &damages, const unsigned &cost, const sf::SoundBuffer &sBuffer, const gtd::Sprite &sprite, const sf::Vector2u &pos, const double &displayedRange, const std::string &name)
: Tower(cost, Attack, sBuffer, sprite, pos, displayedRange, name)
{
	_attackSpeed = attackSpeed;
	_damages = damages;
}

void gtd::AtkTower::update()
{
	_buffer += 1;
}

void gtd::AtkTower::fire(const std::vector<gtd::Mob *> &allMobs, const float &seconds)
{
	gtd::Mob *tmp = allMobs.front();
	int i = 0;

	if (_buffer > _attackSpeed) {
		for (; i != allMobs.size(); i++) {
			if (allMobs[i]->getPos().x < _pos.x + _displayedRange && allMobs[i]->getPos().y < _pos.y + _displayedRange)
				tmp = allMobs[i];
			else if (allMobs[i]->getPos().x == tmp->getPos().x && allMobs[i]->getPos().y < _pos.y + _displayedRange)
				tmp = allMobs[i];
			else if (allMobs[i]->getPos().x == tmp->getPos().y && allMobs[i]->getPos().x < _pos.x + _displayedRange)
				tmp = allMobs[i];
		}
		allMobs[i]->takeDamage(_damages);
		_buffer = 0;
	}
}

void	gtd::AtkTower::resetBuffs()
{
	_displayedRange /= _rangeBuff;
	_attackSpeed /= _asBuff;
	_damages /= _dmgBuff;
	_asBuff = 1;
	_dmgBuff = 1;
	_rangeBuff = 1;

}

void	gtd::AtkTower::buff(const double &as, const double &dmg, const double &range)
{
	_displayedRange *= range;
	_rangeBuff	*= range;
	_attackSpeed	*= as;
	_asBuff		*= as;
	_damages	*= dmg;
	_dmgBuff	*= dmg;
}
