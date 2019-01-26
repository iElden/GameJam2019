//
// Created by stan4 on 26/01/2019.
//

#include "Sprite.hpp"
#include "TvGrandMa.hpp"

gtd::TvGrandMa::TvGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos) :
	BuffTower(1.5, 1.75, 1.25, this->cost, sBuffer, sprites["tv"], pos, 3.5, "Tv Grand-ma")
{
}