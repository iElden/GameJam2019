//
// Created by stan4 on 26/01/2019.
//

#include "Sprite.hpp"
#include "CookingGrandMa.hpp"

gtd::CookingGrandMa::CookingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
: ProdTower(0.01, 5, this->cost, sBuffer, sprites["cooking"], pos, 0, "Cooking Grand-ma")
{
}
