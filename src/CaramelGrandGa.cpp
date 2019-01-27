//
// Created by Zargith on 25/01/2019.
//

#include "Sprite.hpp"
#include "CaramelGrandGa.hpp"

gtd::CaramelGrandMa::CaramelGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos) :
	AtkTower(2, 20, this->cost, sBuffer, sprites["grandma2"], pos, 3.0, false, "Caramel Grand-ma")
{
}

void gtd::CaramelGrandMa::applyEffects(gtd::Mob *mob)
{
	mob->reduceSpeed(1 + 0.30 * this->getLevel());
}
