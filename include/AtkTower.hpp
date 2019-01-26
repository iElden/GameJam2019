//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_ATKTOWER_HPP
#define GRANDMATD_ATKTOWER_HPP


#include "Tower.hpp"
#include "Game.hpp"

namespace gtd {
	class AtkTower : public gtd::Tower {
	protected:
		double	_buffer;
		double	_attackSpeed;
		double	_damages;
		bool	_isAOE;

	public:
		AtkTower(const double &attackSpeed,
			 const double &damages,
			 const unsigned &cost,
			 const sf::SoundBuffer &sBuffer,
			 gtd::Sprite *sprite,
			 const sf::Vector2u &pos,
			 const double &displayedRange,
			 const bool &isAOE,
			 const std::string &name = "Attack Tower");
		void	resetBuffs() override;
		void	buff(const double &as, const double &dmg, const double &range) override;
		void	upgrade(int level) override;
		virtual void fire(std::vector<gtd::Mob *> &allMobs, gtd::Game &game);
		virtual void update() override;
		virtual	void applyEffects(gtd::Mob *mob) = 0;
	};
}


#endif //GRANDMATD_ATKTOWER_HPP
