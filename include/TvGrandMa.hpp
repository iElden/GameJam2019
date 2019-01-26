//
// Created by stan4 on 26/01/2019.
//

#ifndef GRANDMATD_TV_GRAND_MA_HPP
#define GRANDMATD_TV_GRAND_MA_HPP

#include "BuffTower.hpp"

namespace gtd {
	class TvGrandMa : public BuffTower {
	public:
		TvGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos);
		static const int cost = 25;
	};
}

#endif //GRANDMATD_TV_GRAND_MA_HPP
