//
// Created by stan4 on 26/01/2019.
//

#include "CookingGrandMa.hpp"

gtd::CookingGrandMa::CookingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
: ProdTower(Food::Vegan, 3.5, 20, 20, sBuffer, gtd::Sprite("", sf::Vector2u(32, 32)), pos, 25, "Cooking Grand-ma")
{
}