//
// Created by Andgel on 25/01/2019.
//

#include <iostream>
#include <cmath>
#include "Map.hpp"
#include "Mob.hpp"

gtd::Mob::Mob(const double &maxHealth, const double &ms, const sf::Vector2f &pos, gtd::Sprite *sprite) :
	_sprite(sprite),
	_pos(pos),
	_movementSpeed(ms),
	_health(maxHealth),
	_maxHealth(maxHealth)
{
}

void gtd::Mob::display(gtd::Screen &screen)
{
	this->_sprite->_sprite.setOrigin(this->_sprite->_size.x / 2, this->_sprite->_size.y / 2);
	this->_sprite->_sprite.setRotation((this->_dir - gtd::Map::UP) * (90) - 90);
	this->_sprite->display(screen, sf::Vector2f(this->_pos.x * 32 + this->_sprite->_size.x / 2, this->_pos.y * 32 + this->_sprite->_size.y / 2));
	this->_sprite->_sprite.setOrigin(0, 0);
}

bool	gtd::Mob::move(gtd::Map &map)
{
	double	end = this->_movementSpeed / 10;

	for (; end > 0.1; end -= 0.1) {
		this->_dir = map[this->_pos.y + (this->_dir == gtd::Map::UP) * 0.9][this->_pos.x + (this->_dir == gtd::Map::LEFT) * 0.9];
		switch (this->_dir) {
			case gtd::Map::UP:
				this->_pos.y -= 0.1;
				break;
			case gtd::Map::DOWN:
				this->_pos.y += 0.1;
				break;
			case gtd::Map::LEFT:
				this->_pos.x -= 0.1;
				break;
			case gtd::Map::RIGHT:
				this->_pos.x += 0.1;
				break;
			default:
				return false;
		}
	}
	this->_dir = map[this->_pos.y + (this->_dir == gtd::Map::UP) * 0.9][this->_pos.x + (this->_dir == gtd::Map::LEFT) * 0.9];
	switch (this->_dir) {
		case gtd::Map::UP:
			this->_pos.y -= end;
			break;
		case gtd::Map::DOWN:
			this->_pos.y += end;
			break;
		case gtd::Map::LEFT:
			this->_pos.x -= end;
			break;
		case gtd::Map::RIGHT:
			this->_pos.x += end;
			break;
		default:
			return false;
	}
	return true;
}

void	gtd::Mob::takeDamage(const double &dmg)
{
	this->_health -= dmg;
}

bool	gtd::Mob::isFull()
{
	return (this->_health == 0);
}

sf::Vector2f gtd::Mob::getPos()
{
	return  (_pos);
}