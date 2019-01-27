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
			GlutenFree = 1,
			Vegan = 1,
			Carnivore = 1,
			NbOfTypes = 1
		};

		std::vector<double>	stock;
	};
}

#endif //GRANDMATD_RESOURCES_HPP
