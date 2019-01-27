//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_RESOURCES_HPP
#define GRANDMATD_RESOURCES_HPP


#include <vector>

namespace gtd {
	struct Food {
		enum Type {
			Any,
			GlutenFree = 0,
			Vegan = 0,
			Carnivore = 0,
			NbOfTypes
		};

		std::vector<double>	stock;
	};
}

#endif //GRANDMATD_RESOURCES_HPP
