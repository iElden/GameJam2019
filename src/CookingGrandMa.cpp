//
// Created by stan4 on 26/01/2019.
//

#include "Sprite.hpp"
#include "CookingGrandMa.hpp"

gtd::CookingGrandMa::CookingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
: ProdTower(Food::Vegan, 3.5, 20, 20, sBuffer, sprites["cooking"], pos, 25, "Cooking Grand-ma")
{
}
