//
// Created by Andgel on 25/01/2019.
//

#include "BuffTower.hpp"

gtd::BuffTower::BuffTower(const double &asM,
                          const double &dmgM,
                          const double &rangeM,
                          const unsigned &cost,
                          const sf::SoundBuffer &sBuffer,
                          const gtd::Sprite &sprite,
                          const sf::Vector2u &pos,
                          const double &displayedRange,
                          const std::string &name) :
        Tower(cost, gtd::Tower::Buff, sBuffer , sprite, pos, displayedRange, name),
        _asMultiplier(asM),
        _dmgMultiplier(dmgM),
        _rangeMultiplier(rangeM)
{
}

void gtd::BuffTower::buffTowers(std::vector<gtd::Tower *> &allTowers)
{
        for (gtd::Tower *tower : allTowers) {
                if (this->getDistanceTo(tower->getPosition()) <= this->_displayedRange)
                        tower->buff(this->_asMultiplier, this->_dmgMultiplier, this->_rangeMultiplier);
        }
}

void gtd::BuffTower::resetBuffs()
{

}

void gtd::BuffTower::buff(const double &as, const double &dmg, const double &range)
{

}