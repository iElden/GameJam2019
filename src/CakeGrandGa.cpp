//
// Created by Zargith on 25/01/2019.
//

#include "Sprite.hpp"
#include "CakeGrandGa.hpp"

gtd::CakeGrandMa::CakeGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos) :
	AtkTower(2, 10, 15, sBuffer, sprites["grandma1"], pos, 2.0, true, "Cake Grand-ma")
{
}

void gtd::CakeGrandMa::applyEffects(gtd::Mob *mob)
{
	(void)mob;
}
