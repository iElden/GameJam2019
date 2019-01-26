//
// Created by Andgel on 25/01/2019.
//

#include "AtkTower.hpp"

gtd::AtkTower::AtkTower(const double &attackSpeed,
			const double &damages,
			const unsigned &cost,
			const sf::SoundBuffer &sBuffer,
			const gtd::Sprite &sprite,
			const sf::Vector2u &pos,
			const double &displayedRange,
			const bool &isAOE,
			const std::string &name)
: Tower(cost, Attack, sBuffer, sprite, pos, displayedRange, name)
{
	this->_attackSpeed = attackSpeed;
	this->_damages = damages;
	this->_isAOE = isAOE;
}

void gtd::AtkTower::update()
{
	this->_buffer += 1;
}

void gtd::AtkTower::fire(std::vector<gtd::Mob *> &allMobs, const float &seconds)
{
	gtd::Mob	*best;
	double		bestDist;

	if (this->_buffer > this->_attackSpeed && !allMobs.empty()) {
		if (!this->_isAOE) {
			best = allMobs[0];
			bestDist = this->getDistanceTo(best->getPos());
			for (gtd::Mob *mob : allMobs) {
				if (this->getDistanceTo(mob->getPos()) <= bestDist) {
					bestDist = this->getDistanceTo(mob->getPos());
					best = mob;
				}
			}
			if (bestDist <= this->_displayedRange) {
				best->takeDamage(_damages);
				this->applyEffects(best);
			}
		} else {
			for (gtd::Mob *mob : allMobs) {
				if (this->getDistanceTo(mob->getPos()) <= this->_displayedRange) {
					mob->takeDamage(this->_damages);
					this->applyEffects(mob);
				}
			}
		}
		this->_buffer = 0;
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
