//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_ATKTOWER_HPP
#define GRANDMATD_ATKTOWER_HPP


#include "Tower.hpp"

namespace gtd {
	class AtkTower : public gtd::Tower {
	protected:
		double	_attackSpeed;
		double	_damages;

	public:
		AtkTower(const double &attackSpeed, const double &damages);
		virtual void	fire(const std::vector<gtd::Mob *> &allMobs);
		void		resetBuffs() override;
		void		buff(const double &as, const double &dmg, const double &range) override;
	};
}


#endif //GRANDMATD_ATKTOWER_HPP
