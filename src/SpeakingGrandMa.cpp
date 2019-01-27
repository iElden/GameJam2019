//
// Created by Zargith on 25/01/2019.
//

#include "Sprite.hpp"
#include "SpeakingGrandMa.hpp"

gtd::SpeakingGrandMa::SpeakingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
:	AtkTower(10, 0, this->cost, sBuffer, sprites["grandma3"], pos, 3.0, true, "Cake Grand-ma")
{
}

void gtd::SpeakingGrandMa::applyEffects(gtd::Mob *mob)
{
	mob->getBlocked(); //faut aussi lui faire afficher un message
}
