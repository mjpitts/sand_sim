#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	// Variables:

	// Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event eventListener;


	// Initilizers
	void initVars();
	void initWindow();

public:
	// Boiler Plate
	Game();
	virtual ~Game();

	// Core functions
	void update();
	void render();
	void pollEvents();
	const bool isRunning();
};

#endif
