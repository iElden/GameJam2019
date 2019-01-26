//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_MOB_HPP
#define GRANDMATD_MOB_HPP


#include <SFML/Graphics.hpp>

namespace gtd {
	class Mob {
	public:
		Mob(const double &maxHealth, const double &ms, const sf::Vector2f &pos);
		void	move(const float &time);
		void	takeDamage(const double &);
		bool	isFull();
		double	getBarPercentage();

	protected:
		sf::Vector2f	_pos;
		double		_movementSpeed;
		double		_health;
		double		_maxHealth;
	};
}


#endif //GRANDMATD_MOB_HPP
