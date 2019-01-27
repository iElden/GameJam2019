//
// Created by Zargith on 25/01/2019.
//

#include "Sprite.hpp"
#include "CakeGrandMa.hpp"

gtd::CakeGrandMa::CakeGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
:	AtkTower(3, 30, this->cost, sBuffer, sprites["grandma1"], pos, 3.0, false, "Cake Grand-ma")
{
}

void gtd::CakeGrandMa::applyEffects(gtd::Mob *mob)
{
	(void)mob;
}
