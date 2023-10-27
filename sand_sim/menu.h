#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Menu
{

private:

	// Height and width of tiles on the grid
	// NOTE: if this is changed it has to be changed in Grid.h as well
	float tileSize;

	unsigned windowHeight;
	unsigned windowWidth;

	// Height and width measured in tiles
	unsigned MENU_WIDTH = 15;
	unsigned MENU_HEIGHT = 30;

	// Height and width measured in tiles
	unsigned TITLE_WIDTH = 30;
	unsigned TITLE_HEIGHT = 8;

	// Element menu
	sf::RectangleShape menuBody;

	// Text vars
	sf::Text title;

	

	// Boxing containing title text
	sf::RectangleShape titleBox;

public:
	// Constructor & Destructor
	Menu();

	Menu(float tileSize, unsigned winHeight, unsigned winWidth);

	~Menu();

	// Init the styling and position of the menuBody
	void initMenuBody();

	// Init the box containing the title
	void initTitleBox();

	// Init title text object
	void initTitle(sf::Font font);

	// Init all the vars that come from game
	void initVars(float tileSize, unsigned winHeight, unsigned winWidth);

	// Render menu to screen, takes window as param
	void renderMenu(sf::RenderTarget* target, sf::Text menuText, sf::Text menuHeader);

	// Render title to screen, takes window as param
	void renderTitle(sf::RenderTarget* target, sf::Text title);

	// Getters
	sf::Text getTitle();
};

#endif
