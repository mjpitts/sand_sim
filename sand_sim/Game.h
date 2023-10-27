#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Menu.h"
#include <iostream>
#include <sstream>
#include <string>

class Game
{
private:
	// Variables:
	Grid grid;
	sf::RectangleShape mouseRect;

	// Menu variables
	Menu menu;
	bool menuDisplayed;

	// Fonts and Text
	sf::Font font;

	sf::Text title;

	sf::Text menuHeader;
	sf::Text menuText;

	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event eventListener;

	// Mouse 
	sf::Vector2i windowMouse;
	sf::Vector2u gridMouse;
	bool mouseInbounds;

	// Current element tracker
	elementTypes selectedElement;

	// Initilizers
	void initVars();

	void initWindow();

	// Init title text object
	void initTitle();

	//Init menu text
	void initMenuText();

	void initFont();

	// Clock / Delta time
	sf::Clock clock;
	float dt;

	// How fast blocks move
	float blockRefreshRate = 50.f;
	float timeSinceRefresh = 0.f;

public:
	// Contructor / Destructor
	Game();
	~Game();

	// Core functions
	void update();
	
	void updateMouse();

	void render();
	
	void pollEvents();

	const bool isRunning();

	// Getters
	float getTimeSinceRefresh();

	float getDeltaTime();

	// Setter
	void setDeltaTime();

	void setTimeSinceRefresh(float time);
};

#endif
