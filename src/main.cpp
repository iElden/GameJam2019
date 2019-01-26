#include <iostream>
#include <SFML/Graphics.hpp>
#include "CookingGrandMa.hpp"
#include "CakeGrandGa.hpp"
#include "TvGrandMa.hpp"
#include "AtkTower.hpp"
#include "Logger.hpp"
#include "Screen.hpp"
#include "Tower.hpp"
#include "Map.hpp"

Logger					logger("./latest.log");
std::map<std::string, gtd::Sprite *>	sprites;

void	spawnMobs(std::vector<gtd::Mob *> &mobs, const sf::Vector2u &start)
{
	mobs.emplace_back(new gtd::Mob(100, 0.5, sf::Vector2f(start.x, start.y), sprites["boi"]));
}

void	game()
{
	gtd::Screen			screen;
	gtd::Map			map("assets/map.png", sf::Vector2u(17 * 32, 15 * 32), "assets/hitboxs.txt");
	std::vector<gtd::Tower *>	towers;
	std::vector<gtd::Mob *>		mobs;
	sf::SoundBuffer			sBuffer;

	spawnMobs(mobs, map.getStart());
	spawnMobs(mobs, map.getStart());
	spawnMobs(mobs, map.getStart());
	srand(time(NULL));
	for (unsigned i = 0; i < 17; i++) {
		for (unsigned j = 0; j < 15; j++) {
			if (map[j].size() <= i)
				throw std::out_of_range(std::to_string(i) + " is out of ranges");
			if (map[j][i] == gtd::Map::NOTHING) {
				switch (rand() % 3) {
				case 0:
					towers.emplace_back(new gtd::CookingGrandMa(sBuffer, sf::Vector2u(i, j)));
					break;
				case 1:
					towers.emplace_back(new gtd::CakeGrandMa(sBuffer, sf::Vector2u(i, j)));
						towers[towers.size() - 1]->select();
					break;
				case 2:
					towers.emplace_back(new gtd::TvGrandMa(sBuffer, sf::Vector2u(i, j)));
				}
			}
		}
	}
	while (screen.isOpen()) {
		screen.clear();
		map.display(screen);
		for (gtd::Tower *tower : towers) {
			tower->update();
			tower->display(screen);
			switch (tower->getType()) {
			case gtd::Tower::Attack:
				(reinterpret_cast<gtd::AtkTower *>(tower))->fire(mobs);
			}
		}
		for (gtd::Mob *mob : mobs) {
			mob->move(map);
			mob->display(screen);
		}
		screen.handleEvents();
		screen.display();
		for (gtd::Tower *tower : towers)
			tower->resetBuffs();
	}
}

int	main()
{
	logger.info("Loading assets.");
	sprites["cooking"]	= new gtd::Sprite("assets/cooking.png", sf::Vector2u(32, 32));
	sprites["tv"]		= new gtd::Sprite("assets/tv.png", sf::Vector2u(32, 32));
	sprites["grandma1"]	= new gtd::Sprite("assets/grandma1.png", sf::Vector2u(32, 32));
	sprites["boi"]		= new gtd::Sprite("assets/boi.png", sf::Vector2u(32, 32));
	sprites["big_boi"]	= new gtd::Sprite("assets/BIGboi.png", sf::Vector2u(32, 32));
	logger.info("Starting game.");
	game();
	logger.info("Deleting ressources.");
	for (const std::pair<const std::string, gtd::Sprite *> &sprite : sprites)
		delete sprite.second;
	logger.info("Goodbye !");
	return EXIT_SUCCESS;
}