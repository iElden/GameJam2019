//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_TOWER_HPP
#define GRANDMATD_TOWER_HPP


#include <string>
#include <Screen.hpp>
#include <Sprite.hpp>

namespace gtd {
	class Tower {
	protected:
		double		_displayedRange;
		gtd::Sprite	_sprite;
		sf::Vector2u	_pos;
		std::string	_name;
		int		_animation;
		double		_angle;
		unsigned	_cost;
		unsigned	_level;

	public:
		Tower(const gtd::Sprite &sprite, const sf::Vector2u &pos, const double &displayedRange, const std::string &name = "Tower");
		void	display(gtd::Screen &screen);
		virtual	void	update(const float &timeSpent) = 0;
		virtual	void	upgrade() = 0;
	};
}


#endif //GRANDMATD_TOWER_HPP
