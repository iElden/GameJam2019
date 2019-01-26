//
// Created by Andgel on 25/01/2019.
//

#include "BuffTower.hpp"

gtd::BuffTower::BuffTower(const double &asM,
                          const double &dmgM,
                          const double &rangeM,
                          const unsigned &cost,
                          const sf::SoundBuffer &sBuffer,
                          gtd::Sprite *sprite,
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
        (void)as;
        (void)dmg;
        (void)range;
}

void	gtd::BuffTower::upgrade(int level)
{
        if (level > 0) {
                this->_asMultiplier *= (1 - level * 15. / 100);
                this->_dmgMultiplier *= (1 - level * 10. / 100);
        } else {
                this->_asMultiplier /= (1 - level * 15. / 100);
                this->_dmgMultiplier /= (1 - level * 10. / 100);
        }
        this->_displayedRange += 0.5 * level;
        this->_level += level;
}

void gtd::BuffTower::update()
{

}