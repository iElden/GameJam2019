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
		BuffTower(const double &asM,
			  const double &dmgM,
			  const double &rangeM,
			  const unsigned &cost,
			  const sf::SoundBuffer &spawn,
			  const sf::SoundBuffer &sBuffer,
			  gtd::Sprite *sprite,
			  const sf::Vector2u &pos,
			  const double &displayedRange,
			  const std::string &name);
			sf::Time _animation1FrameStartTime{ sf::Time::Zero };
			sf::Time _animation1FrameDuration{ sf::seconds(1.f / 2.f) }; // 1 frames per second
		void update_animation();
		virtual void	buffTowers(std::vector<gtd::Tower *> &allTowers);
		void		resetBuffs() override;
		void		upgrade(int level) override;
		void		update() override;
		void		buff(const double &as, const double &dmg, const double &range) override;
	};
}


#endif //GRANDMATD_BUFFTOWER_HPP
