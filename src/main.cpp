#include <iostream>
#include <SFML/Graphics.hpp>
#include "CookingGrandMa.hpp"
#include "CaramelGrandGa.hpp"
#include "CakeGrandGa.hpp"
#include "TvGrandMa.hpp"
#include "AtkTower.hpp"
#include "Logger.hpp"
#include "Screen.hpp"
#include "Tower.hpp"
#include "Game.hpp"
#include "Map.hpp"

Logger					logger("./latest.log");
std::map<std::string, gtd::Sprite *>	sprites;
gtd::Game				*game;
gtd::Map				*map;
std::vector<gtd::Tower *>		*towers;
int					selected = -1;
sf::Vector2u				selectedBox(0, 0);
sf::SoundBuffer				sBuffer;

int	getTowerAtPos(int x, int y)
{
	for (int i = 0; i < static_cast<int>(towers->size()); i++)
		if (static_cast<int>((*towers)[i]->getPosition().x) == x && static_cast<int>((*towers)[i]->getPosition().y) == y)
			return i;
	throw std::exception();
}

void	handleClick(gtd::Screen &screen, sf::Event &event)
{
	sf::Vector2f	position;

	if (event.type == sf::Event::MouseButtonPressed) {
		position = screen.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
		if (event.mouseButton.button == sf::Mouse::Right) {
			if (selected >= 0)
				(*towers)[selected]->select();
			selected = -1;
		} else if (position.x < 544 && (*map)[position.y / 32][position.x / 32] == gtd::Map::NOTHING) {
			try {
				if (selected >= 0)
					(*towers)[selected]->select();
				selected = getTowerAtPos(position.x / 32, position.y / 32);
				(*towers)[selected]->select();
			} catch (std::exception &e) {
				selected = -2;
			}
			selectedBox = sf::Vector2u(position.x / 32, position.y / 32);
		} else if (position.x > 544 && position.y >= 418 && position.y <= 448 && selected >= 0) {
			game->wonMoney((*towers)[selected]->getRefund());
			delete (*towers)[selected];
			(*towers).erase((*towers).begin() + selected);
			selected = -1;
		} else if (selected == -2 && position.x >= 546) {
			if (position.y >= 114 && position.y < 164) {
				if (position.x < 600 && game->pay(gtd::CookingGrandMa::cost)) {
					towers->emplace_back(new gtd::CookingGrandMa(sBuffer, selectedBox));
					selected = -1;
				} else if (position.x >= 600 && game->pay(gtd::TvGrandMa::cost)) {
					towers->emplace_back(new gtd::TvGrandMa(sBuffer, selectedBox));
					selected = -1;
				}
			} else if (position.y >= 164 && position.y < 214) {
				if (position.x < 600 && game->pay(gtd::CakeGrandMa::cost)) {
					towers->emplace_back(new gtd::CakeGrandMa(sBuffer, selectedBox));
					selected = -1;
				} else if (position.x >= 600 && game->pay(gtd::CaramelGrandMa::cost)) {
					towers->emplace_back(new gtd::CaramelGrandMa(sBuffer, selectedBox));
					selected = -1;
				}
			}
		} else {
			if (selected >= 0)
				(*towers)[selected]->select();
			selected = -1;
		}
	}
}

void	spawnMobs(std::vector<gtd::Mob *> &mobs, const sf::Vector2u &start, double life, double speed, gtd::Sprite *sprite)
{
	mobs.emplace_back(new gtd::Mob(life, speed, sf::Vector2f(start.x, start.y), sprite));
}

bool manageWave(int wave, std::vector<gtd::Mob *> &mobs, gtd::Map &map, bool reset = false)
{
	double apparition;
	double base_life = (wave * 20 + 50);
	double speed_boys;
	static int nb_Mobs = (wave / 2) + 6;
	static int count = 0;
	static int next = 0;

	if (reset) {
		return (nb_Mobs = (wave / 2) + 6), count = 0, true;
	}
	if (count++ < next)
		return (true);
	else
		count = 0;
	next = rand() % 50;
	if (nb_Mobs <= 0)
		return false;
	apparition = rand() % 100000 / 100000.0;
	if (wave > 14 && apparition < - 1.0 * ( 1.0 / (0.001 * wave + 1.0)) + 1.0) {
		spawnMobs(mobs, map.getStart(), base_life * 6, 0.3, sprites["big_boi"]);
		nb_Mobs--;
	} else if (wave > 9 && apparition < - 1.0 * ( 1.0 / (0.005 * wave + 1.0)) + 1.0) {
		speed_boys = 0.6 + wave / 100.0;
		if (speed_boys > 1.5) {
			spawnMobs(mobs, map.getStart(), 250 + (speed_boys - 1.5) * 1000.0, 1.5, rand() % 2 ? (rand() % 2 ? sprites["blondboi"] : sprites["redboi"]) : (rand() % 2 ? sprites["blondgirl"] : sprites["redgirl"]));
		} else {
			spawnMobs(mobs, map.getStart(), 250, speed_boys, rand() % 2 ? (rand() % 2 ? sprites["blondboi"] : sprites["redboi"]) : (rand() % 2 ? sprites["blondgirl"] : sprites["redgirl"]));
		}
		nb_Mobs--;
	} else {
		spawnMobs(mobs, map.getStart(), base_life, 0.6, rand() % 2 ? sprites["boi"] : sprites["girl"]);
		nb_Mobs--;
	}
	return (nb_Mobs > 0);
}

void	displayHUD(gtd::Screen &screen, gtd::Map &map, std::vector<gtd::Tower *> &towers)
{
    (void) map;
	screen.fillColor(sf::Color(255, 255, 0));
	screen.displayElement(sf::IntRect(544, 0, 32 * 3, 480));
	screen.textSize(15);
	sprites["life"]->display(screen, sf::Vector2f(550, 4));
	screen.fillColor(sf::Color(0, 0, 0));
	screen.displayElement(std::to_string(game->getLive()), sf::Vector2f(570, 4));
	sprites["money"]->display(screen, sf::Vector2f(550, 22));
	screen.fillColor(sf::Color(0, 0, 0));
	screen.displayElement(std::to_string(game->getMoney()), sf::Vector2f(570, 22));
	for (unsigned i = 0; i < game->stock.stock.size(); i++) {
		sprites["stock"]->display(screen, sf::Vector2f(550, 40 + i * 18));
		screen.fillColor(sf::Color(0, 0, 0));
		screen.displayElement(std::to_string(static_cast<int>(game->stock.stock[i])), sf::Vector2f(570, 40 + i * 18));
	}
	if (selected >= 0) {
		screen.fillColor(sf::Color(255, 0, 0));
		screen.displayElement(sf::IntRect(544, 418, 100, 30));
		screen.fillColor(sf::Color(0, 0, 0));
		screen.displayElement("Sell for", sf::Vector2f(572, 418));
		screen.displayElement(std::to_string(static_cast<int>(towers[selected]->getRefund())) + "$", sf::Vector2f(580, 430));
	}
	if (selected == -2) {
		screen.fillColor(sf::Color(0, 255, 0, 120));
		screen.displayElement(sf::IntRect(selectedBox.x * 32, selectedBox.y * 32, 32, 32));
		screen.fillColor(sf::Color(120, 120, 120));
		screen.displayElement(sf::IntRect(546, 115, 800, 150));

		screen.fillColor(gtd::CookingGrandMa::cost <= game->getMoney() ? sf::Color(0, 0, 0) : sf::Color(255, 0, 0));
		sprites["cooking"]->_sprite.setRotation(90);
		screen.displayElement(sprites["cooking"]->_sprite, sf::Vector2f(590, 120));
		screen.displayElement(std::to_string(gtd::CookingGrandMa::cost) + "$", sf::Vector2f(564, 150));

		screen.fillColor(gtd::TvGrandMa::cost <= game->getMoney() ? sf::Color(0, 0, 0) : sf::Color(255, 0, 0));
		sprites["tv"]->_sprite.setRotation(90);
		screen.displayElement(sprites["tv"]->_sprite, sf::Vector2f(630, 120));
		screen.displayElement(std::to_string(gtd::TvGrandMa::cost) + "$", sf::Vector2f(604, 150));

		screen.fillColor(gtd::CakeGrandMa::cost <= game->getMoney() ? sf::Color(0, 0, 0) : sf::Color(255, 0, 0));
		sprites["grandma1"]->_sprite.setRotation(90);
		screen.displayElement(sprites["grandma1"]->_sprite, sf::Vector2f(590, 170));
		screen.displayElement(std::to_string(gtd::CakeGrandMa::cost) + "$", sf::Vector2f(564, 200));

		screen.fillColor(gtd::CakeGrandMa::cost <= game->getMoney() ? sf::Color(0, 0, 0) : sf::Color(255, 0, 0));
		sprites["grandma2"]->_sprite.setRotation(90);
		screen.displayElement(sprites["grandma2"]->_sprite, sf::Vector2f(630, 170));
		screen.displayElement(std::to_string(gtd::CaramelGrandMa::cost) + "$", sf::Vector2f(604, 200));
	}
	screen.fillColor(sf::Color(0, 0, 0));
	screen.displayElement("Wave " + std::to_string(game->getWave()), sf::Vector2f(550, 450));
}

void	game_fct()
{
	gtd::Screen			screen;
	gtd::Map			_map("assets/map.png", sf::Vector2u(17 * 32, 15 * 32), "assets/hitboxs.txt");
	std::vector<gtd::Tower *>	_towers;
	std::vector<gtd::Mob *>		mobs;
	sf::Clock			clock;
	gtd::Game			_game;
	sf::Font			font;

	map = &_map;
	towers = &_towers;
	game = &_game;
	for (int i = 0; i < gtd::Food::NbOfTypes; i++)
		game->stock.stock.emplace_back(100);
	font.loadFromFile("assets/arial.ttf");
	screen.setFont(font);
	srand(time(NULL));
	while (screen.isOpen()) {
		if (!manageWave(game->getWave(), mobs, _map) && mobs.empty()) {
			game->nextWave();
			manageWave(game->getWave(), mobs, _map, true);
			game->wonMoney(150 + game->getWave() * 10);
		}
		screen.clear();
		_map.display(screen);
		for (gtd::Tower *tower : _towers)
			tower->resetBuffs();
		for (gtd::Tower *tower : _towers)
			if (tower->getType() ==  gtd::Tower::Buff)
				(reinterpret_cast<gtd::BuffTower *>(tower))->buffTowers(_towers);
		for (gtd::Tower *tower : _towers) {
			tower->update();
			tower->display(screen);
			switch (tower->getType()) {
			case gtd::Tower::Attack:
				(reinterpret_cast<gtd::AtkTower *>(tower))->fire(mobs, _game);
				break;
			case gtd::Tower::Production:
				(reinterpret_cast<gtd::ProdTower *>(tower))->prod(game->stock);
			}
		}
		for (int i = 0; i < static_cast<int>(mobs.size()); i++) {
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
	}
}

int	main()
{
	sf::Music	music;

	logger.info("Loading assets.");
	sprites["cooking"]	= new gtd::Sprite("assets/cooking.png", sf::Vector2u(32, 32));
	sprites["tv"]		= new gtd::Sprite("assets/tv.png", sf::Vector2u(32, 32));
	sprites["grandma1"]	= new gtd::Sprite("assets/grandma1.png", sf::Vector2u(32, 32));
	sprites["grandma2"]	= new gtd::Sprite("assets/grandma2.png", sf::Vector2u(32, 32));
	sprites["boi"]		= new gtd::Sprite("assets/boi.png", sf::Vector2u(32, 32));
	sprites["girl"]		= new gtd::Sprite("assets/girl.png", sf::Vector2u(32, 32));
	sprites["blondboi"]	= new gtd::Sprite("assets/fastblondboi.png", sf::Vector2u(32, 32));
	sprites["blondgirl"]	= new gtd::Sprite("assets/fastblondgirl.png", sf::Vector2u(32, 32));
	sprites["redboi"]	= new gtd::Sprite("assets/fastredboi.png", sf::Vector2u(32, 32));
	sprites["redgirl"]	= new gtd::Sprite("assets/fastredgirl.png", sf::Vector2u(32, 32));
	sprites["big_boi"]	= new gtd::Sprite("assets/bigboi.png", sf::Vector2u(32, 32));
	sprites["life"]		= new gtd::Sprite("assets/life.png", sf::Vector2u(16, 16));
	sprites["money"]	= new gtd::Sprite("assets/money.png", sf::Vector2u(16, 16));
	sprites["stock"]	= new gtd::Sprite("assets/stock.png", sf::Vector2u(16, 16));
	music.openFromFile("assets/music.ogg");
	logger.info("Starting game.");
	music.setLoop(true);
	music.play();
	game_fct();
	logger.info("Deleting ressources.");
	for (const std::pair<const std::string, gtd::Sprite *> &sprite : sprites)
		delete sprite.second;
	logger.info("Goodbye !");
	return EXIT_SUCCESS;
}