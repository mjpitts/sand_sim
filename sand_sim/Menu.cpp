#include "Menu.h"

Menu::Menu()
{

	this->tileSize = 0.f;
	this->windowHeight = 0.f;
	this->windowWidth = 0.f;
	this->menuBody.setFillColor(sf::Color::Transparent);

}

Menu::Menu(float tileSize, unsigned winHeight, unsigned winWidth)
{

	this->initVars(tileSize, winHeight, winWidth);
	this->initMenuBody();
	this->initTitleBox();

}

Menu::~Menu()
{

}

void Menu::initMenuBody()
{
	this->menuBody.setSize(sf::Vector2f(this->MENU_WIDTH * this->tileSize, this->MENU_HEIGHT * this->tileSize));
	this->menuBody.setPosition(sf::Vector2f(this->windowWidth - this->MENU_WIDTH * this->tileSize, 0));
	this->menuBody.setFillColor(sf::Color(60, 63, 64));
	this->menuBody.setOutlineThickness(1.5);
	this->menuBody.setOutlineColor(sf::Color(91, 95, 97));

}

void Menu::initTitleBox()
{
	this->titleBox.setSize(sf::Vector2f(this->TITLE_WIDTH * this->tileSize, this->TITLE_HEIGHT * this->tileSize));
	this->titleBox.setPosition(sf::Vector2f((this->windowWidth / 2) - (this->TITLE_WIDTH / 2) * this->tileSize, 0));
	this->titleBox.setFillColor(sf::Color(60, 63, 64));
	this->titleBox.setOutlineThickness(1.5);
	this->titleBox.setOutlineColor(sf::Color(91, 95, 97));

}

void Menu::initVars(float tileSize, unsigned winHeight, unsigned winWidth)
{

	this->tileSize = tileSize;
	this->windowHeight = winHeight;
	this->windowWidth = winWidth;

}



void Menu::renderMenu(sf::RenderTarget* target, sf::Text menuText, sf::Text menuHeader)
{

	// Set menu header position
	menuHeader.setPosition(
		this->menuBody.getPosition().x + 7,
		7
	);

	menuText.setPosition(
		this->menuBody.getPosition().x + 7,
		40
	);

	target->draw(this->menuBody);
	target->draw(menuHeader);
	target->draw(menuText);

}

void Menu::renderTitle(sf::RenderTarget* target, sf::Text title)
{
	// Set title position
	title.setPosition(
		this->titleBox.getPosition().x + 40,
		7
	);

	target->draw(this->titleBox);
	target->draw(title);
}
