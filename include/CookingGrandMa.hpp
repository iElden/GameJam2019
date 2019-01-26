//
// Created by stan4 on 26/01/2019.
//

#ifndef GRANDMATD_COOKINGGRANDMA_HPP
#define GRANDMATD_COOKINGGRANDMA_HPP

#include "ProdTower.hpp"

namespace gtd {
	class CookingGrandMa : public ProdTower {
	public:
		CookingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos);
		static const int cost = 250;
	};
}

#endif //GRANDMATD_COOKINGGRANDMA_HPP
