//
// Created by Elden on 1/26/19.
//

#ifndef GAMEJAM2019_GAME_HPP
#define GAMEJAM2019_GAME_HPP


#include "Resources.hpp"

namespace  gtd {
	class Game {
	public:
		unsigned getLive() const;
		unsigned getMoney() const;
		unsigned getWave() const;
		bool pay(unsigned value);
		void wonMoney(unsigned value);
		bool lostLife();
		gtd::Food	stock;

	private:
		unsigned _live = 100;
		unsigned _money = 1000;
		unsigned _wave = 0;
	};
}
#endif