#ifndef GAME_H
#define GAME_H

#include "Grid.h"

class Game
{
private:
	// Variables:
	Grid grid;
	sf::RectangleShape mouseRect;

	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event eventListener;

	// Mouse 
	sf::Vector2i windowMouse;
	sf::Vector2u gridMouse;

	// Initilizers
	void initVars();
	void initWindow();

public:
	// Contructor / Destructor
	Game();
	virtual ~Game();

	// Core functions
	void update();
	void render();
	void pollEvents();
	const bool isRunning();
};
#endif
