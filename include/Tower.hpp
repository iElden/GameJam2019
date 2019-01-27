//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_TOWER_HPP
#define GRANDMATD_TOWER_HPP


#include <string>
#include <SFML/Audio.hpp>
#include "Screen.hpp"
#include "Sprite.hpp"
#include "Mob.hpp"

namespace gtd {
	class Tower {
	public:
		enum Type {
			Attack,
			Production,
			Buff,
		};

		Tower(const unsigned &cost,
		      const Type &type,
		      const sf::SoundBuffer &sBuffer,
		      gtd::Sprite *sprite,
		      const sf::Vector2u &pos,
		      const double &displayedRange,
		      const std::string &name = "Tower");
		void		display(gtd::Screen &screen);
		unsigned	getLevel();
		unsigned	getCost();
		Type		getType();
		std::string	getName();
		bool		isSelected();
		void		select();
		sf::Vector2f	getPosition();
		double		getRefund();
		double		getDistanceTo(const sf::Vector2f &pt);
		double		getDistanceTo(const sf::Vector2f &pt, const sf::Vector2u &size);
		virtual void	resetBuffs() = 0;
		virtual	void	upgrade(int level) = 0;
		virtual	void	update() = 0;
		virtual	void	buff(const double &as, const double &dmg, const double &range) = 0;
		double		getUpgradePrice() const;

	protected:
		double		_displayedRange;
		int		_animation = 0;
		unsigned	_level = 0;
		sf::Vector2u	_pos;
		double		_angle = 90;
		double		_asBuff = 1;
		double		_dmgBuff = 1;
		double		_rangeBuff = 1;
		gtd::Sprite	*_sprite;

	private:
		sf::SoundBuffer	_sBuff;
		sf::Sound	_sound;
		Type		_type;
		std::string	_name;
		bool		_isSelected = false;
		unsigned	_cost;
	};
}


#endif //GRANDMATD_TOWER_HPP
