//
// Created by Zargith on 25/01/2019.
//

#include "Sprite.hpp"
#include "CaramelGrandMa.hpp"

gtd::CaramelGrandMa::CaramelGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos, const sf::SoundBuffer &spawn) :
	AtkTower(0.75f, 10, this->cost, spawn, sBuffer, sprites["grandma2"], pos, 2.0, true, "Caramel Grand-ma")
{
}

void gtd::CaramelGrandMa::applyEffects(gtd::Mob *mob)
{
	mob->reduceSpeed(0.30 * 1 / (this->getLevel() + 1), 2 + this->getLevel() * 0.25);
}
