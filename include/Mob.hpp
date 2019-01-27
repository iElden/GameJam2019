//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_MOB_HPP
#define GRANDMATD_MOB_HPP


#include <SFML/Graphics.hpp>
#include "Map.hpp"

namespace gtd {
	class Mob {
	public:
		Mob(const double &maxHealth, const double &ms, const sf::Vector2f &pos, gtd::Sprite *sprite);
		bool	move(gtd::Map &map);
		void	takeDamage(const double &);
		bool	isFull();
        void update_animation();
		double	getBarPercentage();
		void	display(gtd::Screen &screen);
		sf::Vector2f getPos();
		sf::Vector2u getSize();
		void reduceSpeed(const double &slow);
		void getBlocked();
		void getUnblocked();

	protected:
		gtd::Map::Blocks _dir;
		gtd::Sprite	*_sprite;
		sf::Vector2f	_pos;
		int		_animation = 0;
        sf::Time _animation1FrameStartTime{ sf::Time::Zero };
        sf::Time _animation1FrameDuration{ sf::seconds(1.f / 4.f) }; // 12 frames per second
		double		_animationSpeed = 250;
		double		_movementSpeed;
		double		_saveMovementSpeed;
		double		_health;
		double		_maxHealth;
		bool		_slowDown;
		bool 		_blocked;
	};
}


#endif //GRANDMATD_MOB_HPP
