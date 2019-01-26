//
// Created by Andgel on 25/01/2019.
//

#ifndef GRANDMATD_RESOURCES_HPP
#define GRANDMATD_RESOURCES_HPP


namespace gtd {
	struct Food {
		enum Type {
			Any,
			GlutenFree,
			Vegan,
			Carnivore,
			NbOfTypes
		};

		std::vector<unsigned>	stock;
	};
}

#endif //GRANDMATD_RESOURCES_HPP
