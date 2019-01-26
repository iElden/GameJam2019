//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_BUFFTOWER_HPP
#define GRANDMATD_BUFFTOWER_HPP


#include "Tower.hpp"

namespace gtd {
	class BuffTower : public gtd::Tower {
	private:
		double	_asMultiplier;
		double	_dmgMultiplier;
		double	_rangeMultiplier;

	public:
		BuffTower(const double &asM, const double &dmgM, const double &rangeM);
		virtual void buff(const std::vector<gtd::Tower *> &allTowers, const float &seconds);
	};
}


#endif //GRANDMATD_BUFFTOWER_HPP
