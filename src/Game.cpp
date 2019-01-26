//
// Created by Elden on 1/26/19.
//

#include "../include/Game.hpp"

unsigned Game::getLive() const
{
    return this->_live;
}

unsigned Game::getMoney() const
{
    return this->_money;
}

unsigned Game::getWave() const
{
    return this->_wave;
}

bool Game::lostLife()
{
    this->_live -= 1;
    return (this->_live > 0);
}

bool Game::pay(unsigned value)
{
    if (this->_money < value)
        return false;
    this->_money -= value;
    return true;
}

void Game::wonMoney(unsigned value)
{
    this->_money += value;
}