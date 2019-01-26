#include <SFML/Graphics.hpp>
#include <iostream>
#include "CakeGrandGa.hpp"
#include "TvGrandMa.hpp"
#include "Tower.hpp"
#include "Map.hpp"
#include "Logger.hpp"
#include "CookingGrandMa.hpp"
#include "Screen.hpp"

Logger	logger("./latest.log");

void	game()
{
	gtd::Screen	screen;
	gtd::Map	map("assets/map.png", sf::Vector2u(17 * 32, 15 * 32), "assets/hitboxs.txt");
	std::vector<gtd::Tower *>	towers;
	sf::SoundBuffer	sBuffer;
	int	test = 10;

	srand(time(NULL));
	for (unsigned i = 0; i < 10; i++) {
		for (unsigned j = 0; j < 10; j++) {
			switch (rand() % 3) {
				case 0:
					towers.emplace_back(new gtd::CookingGrandMa(sBuffer, sf::Vector2u(i, j)));
					break;
				case 1:
					towers.emplace_back(new gtd::CakeGrandMa(sBuffer, sf::Vector2u(i, j)));
					break;
				case 2:
					towers.emplace_back(new gtd::TvGrandMa(sBuffer, sf::Vector2u(i, j)));
			}
		}
	}
	towers[test]->select();
	while (screen.isOpen()) {
		screen.clear();
		map.display(screen);
		for (gtd::Tower *tower : towers) {
			tower->update();
			tower->display(screen);
		}
		/*towers[test]->update();
		towers[test]->display(screen);*/
		screen.handleEvents();
		screen.display();
		for (gtd::Tower *tower : towers)
			tower->resetBuffs();
	}
}

int	main()
{
	logger.info("Starting game.");
	game();
	logger.info("Goodbye !");
	return EXIT_SUCCESS;
}