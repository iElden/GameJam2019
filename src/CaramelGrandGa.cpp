//
// Created by Zargith on 25/01/2019.
//

#include "Sprite.hpp"
#include "CaramelGrandGa.hpp"

gtd::CaramelGrandMa::CaramelGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos) :
	AtkTower(0.75f, 10, this->cost, sBuffer, sprites["grandma2"], pos, 2.0, true, "Caramel Grand-ma")
{
}

void gtd::CaramelGrandMa::applyEffects(gtd::Mob *mob)
{
	mob->reduceSpeed(0.3);
}