#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.hpp"
#include "Logger.hpp"
#include "Screen.hpp"

Logger	logger("./latest.log");

void	game()
{
	gtd::Screen	screen;
	gtd::Map	map("assets/map.png", sf::Vector2u(17 * 32, 15 * 32), "assets/hitboxs.txt");

	while (screen.isOpen()) {
		screen.clear();
		map.display(screen);
		screen.handleEvents();
		screen.display();
	}
}

int	main()
{
	logger.info("Starting game.");
	game();
	logger.info("Goodbye !");
	return EXIT_SUCCESS;
}