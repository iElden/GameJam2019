//
// Created by Andgel on 25/01/2019.
//

#include <iostream>
#include <cmath>
#include "Map.hpp"
#include "Mob.hpp"
#include "Game.hpp"

extern gtd::Game *game;


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
	this->update_animation();
	this->_sprite->_sprite.setOrigin(this->_sprite->_size.x / 2, this->_sprite->_size.y / 2);
	this->_sprite->_sprite.setRotation((this->_dir - gtd::Map::UP) * (90) - 90);
	this->_sprite->_sprite.setTextureRect(
			sf::IntRect(this->_sprite->getSize().x * this->_animation, 0,
						this->_sprite->getSize().x,
						this->_sprite->getSize().y));
	this->_sprite->display(screen, sf::Vector2f(this->_pos.x * 32 + this->_sprite->_size.x / 2, this->_pos.y * 32 + this->_sprite->_size.y / 2));
	this->_sprite->_sprite.setOrigin(0, 0);
	if (this->getBarPercentage() >= 75)
		screen.fillColor(sf::Color(0, 255, 0, 255));
	else if (this->getBarPercentage() >= 50)
		screen.fillColor(sf::Color(200, 255, 0, 255));
	else if (this->getBarPercentage() >= 20)
		screen.fillColor(sf::Color(255, 125, 0, 255));
	else
		screen.fillColor(sf::Color(255, 0, 0, 255));
	screen.displayElement(sf::IntRect(this->_pos.x * 32, this->_pos.y * 32, this->getBarPercentage() * 32 / 100, 5));
}

bool	gtd::Mob::move(gtd::Map &map)
{
	double	end = this->_movementSpeed * this->_speedMultpilier / 10;

	if (game->clock.getElapsedTime().asSeconds() > this->_slowStart.asSeconds() + this->_slowDuration)
		this->_speedMultpilier = 1;
	for (; end > 0.1; end -= 0.1) {
		if (this->_pos.x > map.getSize().x / 32 || this->_pos.x < 0 ||
		    this->_pos.y > map.getSize().y / 32 || this->_pos.y < 0)
			return false;
		this->_dir = map[this->_pos.y + (this->_dir == gtd::Map::UP) * 0.9][this->_pos.x +
										    (this->_dir ==
										     gtd::Map::LEFT) * 0.9];
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
	if (this->_pos.x > map.getSize().x/32 || this->_pos.x < 0 || this->_pos.y > map.getSize().y/32 || this->_pos.y < 0)
		return false;
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
	return (this->_health <= 0);
}

sf::Vector2f gtd::Mob::getPos()
{
	return  (this->_pos);
}

double gtd::Mob::getBarPercentage()
{
	if (this->_maxHealth <= 0)
		throw std::invalid_argument("Max health can be equal or less than 0.");
	return (this->_health * 100 / this->_maxHealth);
}

sf::Vector2u gtd::Mob::getSize()
{
	return  (this->_sprite->_size);
}

void gtd::Mob::update_animation() {
    sf::Time currentTime = game->clock.getElapsedTime();
    if (currentTime - _animation1FrameStartTime >= _animation1FrameDuration) {
        this->_animation += 1;
        this->_animation %= (this->_sprite->_texture.getSize().x / this->_sprite->getSize().x) ?: 1;
        _animation1FrameStartTime = currentTime;
    }
}

void gtd::Mob::reduceSpeed(const double &slow, const double &duration)
{
	if (this->_speedMultpilier > slow)
		this->_speedMultpilier = slow;
	this->_slowDuration = duration;
	this->_slowStart = game->clock.getElapsedTime();
}
