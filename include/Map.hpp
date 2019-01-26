//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_MAP_HPP
#define GRANDMATD_MAP_HPP


#include "Sprite.hpp"

namespace gtd {
	class Map {
	public:
		enum Blocks {
			NOTHING,
			BLOCKED,
			UP,
			RIGHT,
			DOWN,
			LEFT
		};
		Map(const std::string &spritePath, const sf::Vector2u &spriteSize, const std::string &mapHitbox);
		std::vector<Blocks>	operator[](const unsigned &index);
		sf::Vector2u		getSize();
		void			display(Screen &screen, const float &seconds);

	private:
		sf::Vector2u				_start;
		gtd::Sprite				_sprite;
		std::vector<std::vector<Blocks>>	_hitboxs;
	};
}


#endif //GRANDMATD_MAP_HPP
