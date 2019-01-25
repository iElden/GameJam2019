//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_SPRITE_HPP
#define GRANDMATD_SPRITE_HPP


#include <SFML/Graphics.hpp>
#include "Screen.hpp"

namespace gtd {
	class Sprite {
	private:
		sf::Sprite	_sprite;
		sf::Texture	_texture;
		sf::Vector2u	_size;
		bool		_isLoaded;

	public:
		Sprite(const std::string &path, const sf::Vector2u &size);
		void	display(gtd::Screen &screen, const sf::Vector2f &pos);
	};
}


#endif //GRANDMATD_SPRITE_HPP
