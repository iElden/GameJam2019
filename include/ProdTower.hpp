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
	};
}


#endif //GRANDMATD_PRODTOWER_HPP
