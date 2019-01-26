//
// Created by stan4 on 26/01/2019.
//

#include "TvGrandMa.hpp"

gtd::TvGrandMa::TvGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos)
: BuffTower(1.5, 1.75, 1.25, 25, sBuffer, *new gtd::Sprite("assets/tv.png", sf::Vector2u(32, 32)), pos, 3.5, "Tv Grand-ma")
{
}