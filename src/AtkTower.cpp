//
// Created by Andgel on 25/01/2019.
//

#include <cmath>
#include <iostream>
#include "AtkTower.hpp"

gtd::AtkTower::AtkTower(const double &attackSpeed,
			const double &damages,
			const unsigned &cost,
			const sf::SoundBuffer &sBuffer,
			gtd::Sprite *sprite,
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

void gtd::AtkTower::fire(std::vector<gtd::Mob *> &allMobs)
{
	gtd::Mob	*best;
	double		bestDist;

	if (this->_buffer > this->_attackSpeed && !allMobs.empty()) {
		if (!this->_isAOE) {
			best = allMobs[0];
			bestDist = this->getDistanceTo(best->getPos());
			for (gtd::Mob *mob : allMobs) {
				if (this->getDistanceTo(mob->getPos(), mob->getSize()) <= bestDist) {
					bestDist = this->getDistanceTo(mob->getPos(), mob->getSize());
					best = mob;
				}
			}
			if (bestDist <= this->_displayedRange) {
				sf::Vector2f	point1 = sf::Vector2f(this->_pos.x, this->_pos.y);
				sf::Vector2f	point2 = best->getPos();
				double          distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
				sf::Vector2f    vec2((point2.x - point1.x) / distance, (point2.y - point1.y) / distance);

				this->_angle = atan2(vec2.y, vec2.x) * 180 / M_PI;
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
	this->_displayedRange	/= this->_rangeBuff;
	this->_attackSpeed	/= this->_asBuff;
	this->_damages		/= this->_dmgBuff;
	this->_asBuff		= 1;
	this->_dmgBuff		= 1;
	this->_rangeBuff	= 1;

}

void	gtd::AtkTower::buff(const double &as, const double &dmg, const double &range)
{
	this->_displayedRange	*= range;
	this->_rangeBuff	*= range;
	this->_attackSpeed	*= as;
	this->_asBuff		*= as;
	this->_damages		*= dmg;
	this->_dmgBuff		*= dmg;
}

void	gtd::AtkTower::upgrade(int level)
{
	if (level > 0) {
		this->_damages *= (1 + 0.15 * level);
		this->_attackSpeed *= (1 + 0.20 * level);
	} else {
		this->_damages /= (1 + 0.15 * level);
		this->_attackSpeed /= (1 + 0.20 * level);
	}
	this->_level += level;
}
