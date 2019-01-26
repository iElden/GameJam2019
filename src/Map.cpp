//
// Created by Andgel on 25/01/2019.
//

#include <fstream>
#include "Map.hpp"

gtd::Map::Map(const std::string &spritePath, const sf::Vector2u &spriteSize, const std::string &mapHitbox) :
	_start(),
	_sprite(spritePath, spriteSize),
	_hitboxs()
{
	std::ifstream			stream;
	std::string			line;
	std::vector<gtd::Map::Blocks>	blocks;
	sf::Vector2u			pos;

	while (std::getline(stream, line)) {
		for (char c : line) {
			if (!isdigit(c))
				throw std::invalid_argument(std::string("Invalid character '") + c + "'");
			if (c > '5') {
				blocks.emplace_back(static_cast<gtd::Map::Blocks>(c - '5'));
				this->_start = pos;
			} else
				blocks.emplace_back(static_cast<gtd::Map::Blocks>(c - '0'));
			pos.x += 1;
		}
		this->_hitboxs.emplace_back(blocks);
		blocks.erase(blocks.begin(), blocks.end());
		pos.x = 0;
		pos.y += 1;
	}
}

void	gtd::Map::display(gtd::Screen &screen)
{
	this->_sprite.display(screen, sf::Vector2f(0, 0));
}

sf::Vector2u	gtd::Map::getSize()
{
	return this->_sprite.getSize();
}

const std::vector<gtd::Map::Blocks>	&gtd::Map::operator[](const unsigned &index)
{
	return	this->_hitboxs[index];
}