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
		      const gtd::Sprite &sprite,
		      const sf::Vector2u &pos,
		      const double &displayedRange,
		      const std::string &name = "Tower");
		void		display(gtd::Screen &screen);
		unsigned	getLevel();
		unsigned	getCost();
		Type		getType();
		std::string	getName();
		virtual	void	update(const float &timeSpent) = 0;
		virtual	void	upgrade(int level) = 0;

	protected:
		int		_animation;
		unsigned	_level;
		sf::Vector2u	_pos;

	private:
		sf::SoundBuffer	_sBuff;
		sf::Sound	_sound;
		Type		_type;
		double		_displayedRange;
		gtd::Sprite	_sprite;
		std::string	_name;
		double		_angle;
		unsigned	_cost;
	};
}


#endif //GRANDMATD_TOWER_HPP
