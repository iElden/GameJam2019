//
// Created by Andgel on 25/01/2019.
//

#include <cmath>
#include <iostream>
#include "AtkTower.hpp"
#include "Game.hpp"

extern gtd::Game *game;

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
	this->_buffer = 60. / this->_attackSpeed;
	this->_damages = damages;
	this->_isAOE = isAOE;
}

void gtd::AtkTower::update()
{
	this->_animation1FrameDuration = sf::Time(
		sf::seconds(
			float(
				1 / (
					this->_attackSpeed * (
						float(this->_sprite->_texture.getSize().x) / this->_sprite->getSize().x
					)
				)
			)
		)
	);
	this->_buffer += 1;
	if (this->_isAttacking) {
		this->update_animation();
	} else {
		_animation1FrameStartTime = game->clock.getElapsedTime();
		this->_animation = 0;
	}
}

void gtd::AtkTower::fire(std::vector<gtd::Mob *> &allMobs, gtd::Game &game)
{
	gtd::Mob	*best;
	double		bestDist;

	if (this->_buffer > 60. / this->_attackSpeed)
		this->_isAttacking = false;
	if (this->_buffer > 60. / this->_attackSpeed && !allMobs.empty()) {
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

				if (game.stock.stock[gtd::Food::Any] >= 1.)
					game.stock.stock[gtd::Food::Any] -= 1;
				else if (game.stock.stock[gtd::Food::GlutenFree] >= 1.)
					game.stock.stock[gtd::Food::GlutenFree] -= 1.;
				else if (game.stock.stock[gtd::Food::Vegan] >= 1.)
					game.stock.stock[gtd::Food::Vegan] -= 1.;
				else if (game.stock.stock[gtd::Food::Carnivore] >= 1.)
					game.stock.stock[gtd::Food::Carnivore] -= 1.;
				else
					return;
				this->_isAttacking = true;
				this->_angle = atan2(vec2.y, vec2.x) * 180 / M_PI;
				best->takeDamage(_damages);
				this->applyEffects(best);
			}
		} else {
			if (game.stock.stock[gtd::Food::Any] < 1 && game.stock.stock[gtd::Food::GlutenFree] < 1 && game.stock.stock[gtd::Food::Vegan] < 1 && game.stock.stock[gtd::Food::Carnivore])
				return;
			for (gtd::Mob *mob : allMobs) {
				if (this->getDistanceTo(mob->getPos()) <= this->_displayedRange) {
					sf::Vector2f	point1 = sf::Vector2f(this->_pos.x, this->_pos.y);
					sf::Vector2f	point2 = mob->getPos();
					double          distance = sqrt(pow(point2.x - point1.x, 2) + pow(point2.y - point1.y, 2));
					sf::Vector2f    vec2((point2.x - point1.x) / distance, (point2.y - point1.y) / distance);

					this->_angle = atan2(vec2.y, vec2.x) * 180 / M_PI;
					mob->takeDamage(this->_damages);
					this->applyEffects(mob);
					this->_isAttacking = true;
				}
			}
			if (this->_isAttacking) {
				if (game.stock.stock[gtd::Food::Any] >= 1.)
					game.stock.stock[gtd::Food::Any] -= 1;
				else if (game.stock.stock[gtd::Food::GlutenFree] >= 1.)
					game.stock.stock[gtd::Food::GlutenFree] -= 1.;
				else if (game.stock.stock[gtd::Food::Vegan] >= 1.)
					game.stock.stock[gtd::Food::Vegan] -= 1.;
				else if (game.stock.stock[gtd::Food::Carnivore] >= 1.)
					game.stock.stock[gtd::Food::Carnivore] -= 1.;
				else
					return;
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
		this->_upgradePrice = (1 + this->_level) * this->getCost() / 10;
	this->_level += level;
}

void gtd::AtkTower::update_animation()
{
	sf::Time currentTime = game->clock.getElapsedTime();
	if (currentTime - _animation1FrameStartTime >= _animation1FrameDuration) {
		this->_animation += 1;
		this->_animation %= (this->_sprite->_texture.getSize().x /
							 this->_sprite->getSize().x) ?: 1;
		_animation1FrameStartTime = currentTime;
	}
}