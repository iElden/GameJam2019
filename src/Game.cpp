//
// Created by Elden on 1/26/19.
//

#include "Game.hpp"

unsigned gtd::Game::getLive() const
{
    return this->_live;
}

unsigned gtd::Game::getMoney() const
{
    return this->_money;
}

unsigned gtd::Game::getWave() const
{
    return this->_wave;
}

bool gtd::Game::lostLife()
{
    this->_live -= 1;
    return (this->_live > 0);
}

bool gtd::Game::pay(unsigned value)
{
    if (this->_money < value)
        return false;
    this->_money -= value;
    return true;
}

void gtd::Game::wonMoney(unsigned value)
{
    this->_money += value;
}