#include "Menu.h"

Menu::Menu()
{

	this -> tileSize = 0.f;
	this->windowHeight = 0.f;
	this->windowWidth = 0.f;
	this->menuBody.setFillColor(sf::Color::Transparent);

}

Menu::Menu(float tileSize, unsigned winHeight, unsigned winWidth)
{
	this->initVars(tileSize, winHeight, winWidth);
	this->initMenuBody();
}

Menu::~Menu()
{

}

void Menu::initMenuBody()
{
	this->menuBody.setSize(sf::Vector2f(this->MENU_WIDTH * this->tileSize, this->MENU_HEIGHT * this->tileSize));
	this->menuBody.setPosition(sf::Vector2f(this->windowWidth - this->MENU_WIDTH * this->tileSize, 0));


}

void Menu::initVars(float tileSize, unsigned winHeight, unsigned winWidth)
{

	this->tileSize = tileSize;
	this->windowHeight = winHeight;
	this->windowWidth = winWidth;
	this->menuBody.setFillColor(sf::Color(125, 164, 173));

}

void Menu::renderMenu(sf::RenderTarget* target)
{

	target->draw(this->menuBody);

}

unsigned Menu::getWindowWidth()
{
	return this->windowWidth;
}
