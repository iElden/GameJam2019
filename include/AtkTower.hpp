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
		double	_damage;

	public:
		virtual void fire(const std::vector<gtd::Mob *> &allMobs) = 0;
	};
}


#endif //GRANDMATD_ATKTOWER_HPP
