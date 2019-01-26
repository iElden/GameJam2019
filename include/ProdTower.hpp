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
		gtd::Food::Type	_prodType;
		double		_prodSpeed;
		int		_value;

	public:
		ProdTower(const gtd::Food::Type &type, const double &speed, const int &value);
		virtual	void	prod(const float &seconds);
	};
}


#endif //GRANDMATD_PRODTOWER_HPP
