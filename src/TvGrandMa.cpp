//
// Created by stan4 on 26/01/2019.
//

#include "Sprite.hpp"
#include "TvGrandMa.hpp"

gtd::TvGrandMa::TvGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos) :
	BuffTower(1.05, 1.075, 1.05, this->cost, sBuffer, sprites["tv"], pos, 2, "Tv Grand-ma")
{
}