//
// Created by stan4 on 26/01/2019.
//

#include "Sprite.hpp"
#include "CookingGrandMa.hpp"

gtd::CookingGrandMa::CookingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
: ProdTower(Food::Vegan, 2, 20, this->cost, sBuffer, sprites["cooking"], pos, 25, "Cooking Grand-ma")
{
}
