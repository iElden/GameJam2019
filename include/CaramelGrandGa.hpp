//
// Created by Zargith on 25/01/2019.
//

#ifndef GRANDMATD_CARAMEL_GRAND_MA_HPP
#define GRANDMATD_CARAMEL_GRAND_MA_HPP

#include "AtkTower.hpp"

namespace gtd {
	class CaramelGrandMa : public AtkTower {
	public:
		CaramelGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos);
		void applyEffects(gtd::Mob *mob) override;
		static const int cost = 615;
	};
}

#endif //GRANDMATD_CAKE_GRAND_MA_HPP
