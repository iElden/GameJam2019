#include <iostream>
#include <SFML/Graphics.hpp>
#include "CookingGrandMa.hpp"
#include "CakeGrandGa.hpp"
#include "TvGrandMa.hpp"
#include "AtkTower.hpp"
#include "Logger.hpp"
#include "Screen.hpp"
#include "Tower.hpp"
#include "game.hpp"
#include "Map.hpp"

Logger					logger("./latest.log");
std::map<std::string, gtd::Sprite *>	sprites;
gtd::Game				*game;
gtd::Map				*map;
std::vector<gtd::Tower *>		*towers;
int					selected = -1;

void	handleClick(sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Right)
			selected = -1;
		else if (event.mouseButton.x < 544 && (*map)[event.mouseButton.y / 32][event.mouseButton.x / 32] == gtd::Map::NOTHING)
			;
	}
}

void	spawnMobs(std::vector<gtd::Mob *> &mobs, const sf::Vector2u &start)
{
	mobs.emplace_back(new gtd::Mob(rand() % 30000, rand() % 300 / 200., sf::Vector2f(start.x, start.y), sprites["boi"]));
}

void	displayHUD(gtd::Screen &screen, gtd::Map &map, std::vector<gtd::Tower *> &towers)
{
	screen.fillColor(sf::Color(255, 255, 0));
	screen.displayElement(sf::IntRect(544, 0, 32 * 3, 480));
	screen.textSize(15);
	sprites["life"]->display(screen, sf::Vector2f(550, 4));
	screen.fillColor(sf::Color(0, 0, 0));
	screen.displayElement(std::to_string(game->getLive()), sf::Vector2f(570, 4));
	sprites["money"]->display(screen, sf::Vector2f(550, 22));
	screen.fillColor(sf::Color(0, 0, 0));
	screen.displayElement(std::to_string(game->getMoney()), sf::Vector2f(570, 22));
	for (int i = 0; i < game->stock.stock.size(); i++) {
		sprites["stock"]->display(screen, sf::Vector2f(550, 40 + i * 18));
		screen.fillColor(sf::Color(0, 0, 0));
		screen.displayElement(std::to_string(static_cast<int>(game->stock.stock[i])), sf::Vector2f(570, 40 + i * 18));
	}
	screen.displayElement("Wave " + std::to_string(game->getWave()), sf::Vector2f(550, 450));
}

void	game_fct()
{
	gtd::Screen			screen;
	gtd::Map			_map("assets/map.png", sf::Vector2u(17 * 32, 15 * 32), "assets/hitboxs.txt");
	std::vector<gtd::Tower *>	_towers;
	std::vector<gtd::Mob *>		mobs;
	sf::SoundBuffer			sBuffer;
	sf::Clock			clock;
	gtd::Game			_game;
	sf::Font			font;

	map = &_map;
	towers = &_towers;
	game = &_game;
	for (int i = 0; i < gtd::Food::NbOfTypes; i++)
		game->stock.stock.emplace_back(500);
	font.loadFromFile("assets/arial.ttf");
	screen.setFont(font);
	srand(time(NULL));
	for (unsigned i = 0; i < 17; i++) {
		for (unsigned j = 0; j < 15; j++) {
			if (_map[j].size() <= i)
				throw std::out_of_range(std::to_string(i) + " is out of ranges");
			if (_map[j][i] == gtd::Map::NOTHING) {
				switch (rand() % 3) {
				case 0:
					towers->emplace_back(new gtd::CookingGrandMa(sBuffer, sf::Vector2u(i, j)));
					break;
				case 1:
					towers->emplace_back(new gtd::CakeGrandMa(sBuffer, sf::Vector2u(i, j)));
					break;
				case 2:
					towers->emplace_back(new gtd::TvGrandMa(sBuffer, sf::Vector2u(i, j)));
				}
			}
		}
	}
	while (screen.isOpen()) {
		if (clock.getElapsedTime().asSeconds() >= 2) {
			clock.restart();
			spawnMobs(mobs, map->getStart());
		}
		screen.clear();
		_map.display(screen);
		for (gtd::Tower *tower : _towers) {
			tower->update();
			tower->display(screen);
			switch (tower->getType()) {
			case gtd::Tower::Attack:
				(reinterpret_cast<gtd::AtkTower *>(tower))->fire(mobs, _game);
				break;
			case gtd::Tower::Production:
				(reinterpret_cast<gtd::ProdTower *>(tower))->prod(game->stock);
				break;
			case gtd::Tower::Buff:
				(reinterpret_cast<gtd::BuffTower *>(tower))->buffTowers(_towers);
			}
		}
		for (int i = 0; i < mobs.size(); i++) {
			gtd::Mob *mob = mobs[i];

			if (!mob->move(_map)) {
				delete mob;
				mobs.erase(mobs.begin() + i);
				i--;
				if (!game->lostLife())
					return;
			} else if (mob->isFull()) {
				delete mob;
				mobs.erase(mobs.begin() + i);
				i--;
				game->wonMoney(10);
			} else
				mob->display(screen);
		}
		displayHUD(screen, _map, _towers);
		screen.handleEvents(handleClick);
		screen.display();
		for (gtd::Tower *tower : _towers)
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
	sprites["life"]		= new gtd::Sprite("assets/life.png", sf::Vector2u(16, 16));
	sprites["money"]	= new gtd::Sprite("assets/money.png", sf::Vector2u(16, 16));
	sprites["stock"]	= new gtd::Sprite("assets/stock.png", sf::Vector2u(16, 16));
	logger.info("Starting game->");
	game_fct();
	logger.info("Deleting ressources.");
	for (const std::pair<const std::string, gtd::Sprite *> &sprite : sprites)
		delete sprite.second;
	logger.info("Goodbye !");
	return EXIT_SUCCESS;
}