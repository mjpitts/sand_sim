#ifndef MENU_H
#define MENU_H

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

	// Heigh and width measured in tiles
	unsigned MENU_WIDTH = 15;
	unsigned MENU_HEIGHT = 30;

	sf::RectangleShape menuBody;

public:
	// Constructor & Destructor
	Menu();

	Menu(float tileSize, unsigned winHeight, unsigned winWidth);

	~Menu();

	// Initilize the styling and position of the menuBody
	void initMenuBody();

	// Init all the vars that come from game
	void initVars(float tileSize, unsigned winHeight, unsigned winWidth);

	// Render menue to screen, takes window as param
	void renderMenu(sf::RenderTarget* target);

	unsigned getWindowWidth();
};

#endif
