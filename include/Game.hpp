//
// Created by Elden on 1/26/19.
//

#ifndef GAMEJAM2019_GAME_HPP
#define GAMEJAM2019_GAME_HPP

namespace  gtd {
	class Game {
	public:
		unsigned getLive() const;
		unsigned getMoney() const;
		unsigned getWave() const;
		bool pay(unsigned value);
		void wonMoney(unsigned value);
		bool lostLife();

	private:
		unsigned _live;
		unsigned _money;
		unsigned _wave;
	};
}
#endif