//
// Created by Zargith on 25/01/2019.
//

#ifndef GRANDMATD_SPEAKING_GRAND_MA_HPP
#define GRANDMATD_SPEAKING_GRAND_MA_HPP

#include "AtkTower.hpp"

namespace gtd {
	class SpeakingGrandMa : public AtkTower {
	public:
		SpeakingGrandMa(const sf::SoundBuffer &sBuffer, const sf::Vector2u &pos, const sf::SoundBuffer &spawn);
		void applyEffects(gtd::Mob *mob) override;
		static const int cost = 500;
	};
}
#endif //GRANDMATD_SPEAKING_GRAND_MA_HPP
