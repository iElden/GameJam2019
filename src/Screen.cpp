//
// Created by Gegel85 on 15/01/2019.
//

#include "Logger.hpp"
#include "Screen.hpp"

gtd::Screen::Screen(const std::string &title) :
	sf::RenderWindow(sf::VideoMode(640, 480), title), _title(title)
{
	logger.info("Opening game window \"" + title + "\"");
	this->setFramerateLimit(60);
}

gtd::Screen::Screen(const Screen &other) :
	sf::RenderWindow(sf::VideoMode(other.getSize().x, other.getSize().y), other.getTitle())
{
	logger.info("Opening game window \"" + other.getTitle() + "\"");
	this->_title = other.getTitle();
	this->setFramerateLimit(60);
	this->setSize(other.getSize());
	this->setPosition(other.getPosition());
}

gtd::Screen::~Screen()
{
	logger.info("Destroying game window \"" + this->_title + "\"");
}

const	std::string& gtd::Screen::getTitle() const
{
	return this->_title;
}

void	gtd::Screen::setTitle(const std::string &title)
{
	this->_title = title;
	this->setTitle(title);
}

void	gtd::Screen::handleEvents()
{
	sf::Event	event;

	while (this->pollEvent(event))
		if (event.type == sf::Event::Closed)
			this->close();
}

void	gtd::Screen::displayElement(sf::IntRect rect)
{
	this->_rect.setPosition(sf::Vector2f(rect.left, rect.width));
	this->_rect.setSize(sf::Vector2f(rect.width, rect.height));
	this->draw(this->_rect);
}

void    gtd::Screen::fillColor(const sf::Color &color)
{
	this->_rect.setFillColor(color);
	this->_text.setFillColor(color);
	this->_circle.setFillColor(color);
}

void	gtd::Screen::setFont(const sf::Font &font)
{
	this->_text.setFont(font);
}

void	gtd::Screen::textSize(const size_t &size)
{
	this->_text.setCharacterSize(size);
}

void	gtd::Screen::displayElement(const std::string &str, sf::Vector2f pos)
{
	this->_text.setPosition(pos);
	this->_text.setString(str);
	this->draw(this->_text);
}

void	gtd::Screen::displayElement(sf::Sprite &sprite, sf::Vector2f pos)
{
	sprite.setPosition(pos);
	this->draw(sprite);
}

void	gtd::Screen::displayElement(float radius, sf::Vector2f pos)
{
	this->_circle.setRadius(radius);
	this->_circle.setPosition(pos);
	this->draw(this->_circle);
}