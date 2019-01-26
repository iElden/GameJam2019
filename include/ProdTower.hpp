//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_PRODTOWER_HPP
#define GRANDMATD_PRODTOWER_HPP


#include "Tower.hpp"
#include "Resources.hpp"

namespace gtd {
	class ProdTower : public gtd::Tower {
	protected:
		double		_buffer;
		gtd::Food::Type	_prodType;
		double		_prodSpeed;
		int		_value;

	public:
		ProdTower(const gtd::Food::Type &type,
			  const double &speed,
			  const int &value,
			  const unsigned &cost,
			  const sf::SoundBuffer &sBuffer,
			  const gtd::Sprite &sprite,
			  const sf::Vector2u &pos,
			  const double &displayedRange,
			  const std::string &name = "Tower");
		void		resetBuffs() override;
		void		buff(const double &as, const double &dmg, const double &range) override;
		virtual void	update(const float &timeSpent) override;
		virtual	void	prod(const float &seconds);
	};
}


#endif //GRANDMATD_PRODTOWER_HPP
