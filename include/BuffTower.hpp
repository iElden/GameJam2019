//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_BUFFTOWER_HPP
#define GRANDMATD_BUFFTOWER_HPP


#include "Tower.hpp"

namespace gtd {
	class BuffTower : public gtd::Tower {
	private:
		int _asMultiplier;
		int _dmgMultiplier;
		int _rangeMultiplier;

	public:
		virtual void buff(const std::vector<gtd::Tower *> &allTowers) = 0;
	};
}


#endif //GRANDMATD_BUFFTOWER_HPP
