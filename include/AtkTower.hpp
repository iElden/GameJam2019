//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_ATKTOWER_HPP
#define GRANDMATD_ATKTOWER_HPP


#include "Tower.hpp"

namespace gtd {
	class AtkTower : public gtd::Tower {
	protected:
		double	_buffer;
		double	_attackSpeed;
		double	_damages;

	public:
		AtkTower(const double &attackSpeed,
			 const double &damages,
			 const unsigned &cost,
			 const sf::SoundBuffer &sBuffer,
			 const gtd::Sprite &sprite,
			 const sf::Vector2u &pos,
			 const double &displayedRange,
			 const std::string &name = "Attack Tower");
		void	resetBuffs() override;
		void	buff(const double &as, const double &dmg, const double &range) override;
		virtual void fire(const std::vector<gtd::Mob *> &allMobs, const float &seconds);
		virtual void update() override;
	};
}


#endif //GRANDMATD_ATKTOWER_HPP
