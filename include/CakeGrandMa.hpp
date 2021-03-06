//
// Created by Zargith on 25/01/2019.
//

#ifndef GRANDMATD_CAKE_GRAND_MA_HPP
#define GRANDMATD_CAKE_GRAND_MA_HPP

#include "AtkTower.hpp"
namespace gtd {
	class CakeGrandMa : public AtkTower {
	public:
		CakeGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos, const sf::SoundBuffer &spawn);
		void applyEffects(gtd::Mob *mob) override;
		static const int cost = 450;
	};
}
#endif //GRANDMATD_CAKE_GRAND_MA_HPP
