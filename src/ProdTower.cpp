//
// Created by Andgel on 25/01/2019.
//

#include "Game.hpp"
#include "ProdTower.hpp"

extern gtd::Game	*game;
extern sf::Sound				sound;
extern std::map<std::string, sf::SoundBuffer>	sBuffers;

gtd::ProdTower::ProdTower(const double &speed,
			  const int &value,
			  const unsigned &cost,
			  const sf::SoundBuffer &spawn,
			  const sf::SoundBuffer &sBuffer,
			  gtd::Sprite *sprite,
			  const sf::Vector2u &pos,
			  const double &displayedRange,
			  const std::string &name) :
	gtd::Tower(cost, gtd::Tower::Production, spawn, sBuffer, sprite, pos, displayedRange, name),
	_prodSpeed(speed),
	_value(value)
{
	int typeFood = rand() % 4;
	switch (typeFood) {
		case 0:
			_prodType = gtd::Food::Any;
			break;
		case 1:
			_prodType = gtd::Food::GlutenFree;
			break;
		case 2:
			_prodType = gtd::Food::Vegan;
			break;
		case 3:
			_prodType = gtd::Food::Carnivore;
			break;
	}
}

void	gtd::ProdTower::prod(gtd::Food &stock)
{
	if (this->_buffer >= 90. / this->_prodSpeed)
		this->_buffer = 0;
	else
		return;
	stock.stock[this->_prodType] += this->_value;
}

void	gtd::ProdTower::update()
{
	this->_buffer += 1;
	this->update_animation();
}

void	gtd::ProdTower::resetBuffs()
{
	this->_prodSpeed	/= this->_asBuff;
	this->_value		/= this->_dmgBuff;
	this->_asBuff	= 1;
	this->_dmgBuff	= 1;
}

void	gtd::ProdTower::buff(const double &as, const double &dmg, const double &range)
{
	(void)range;
	this->_prodSpeed	*= as;
	this->_asBuff		*= as;
	this->_value		*= dmg;
	this->_dmgBuff		*= dmg;
}

void	gtd::ProdTower::upgrade(int level)
{
	this->_value += 0.5 * level;
	if (level > 0)
		this->_prodSpeed *= (1 + level * 20. / 100);
	else
		this->_prodSpeed /= (1 + level * 20. / 100);
	this->_level += level;
	sound.setBuffer(sBuffers["upgrade"]);
	sound.play();
}

void gtd::ProdTower::update_animation()
{
	sf::Time currentTime = game->clock.getElapsedTime();
	if (currentTime - _animation1FrameStartTime >= _animation1FrameDuration) {
		this->_animation += 1;
		this->_animation %= (this->_sprite->_texture.getSize().x /
				     this->_sprite->getSize().x) ?: 1;
		_animation1FrameStartTime = currentTime;
	}
}