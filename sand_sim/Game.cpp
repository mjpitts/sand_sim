#include "Game.h"


// Initializers
void Game::initVars() {
	this->window = nullptr;
}

void Game::initWindow() {
	// Window settings
	this->videoMode.height = 900;
	this->videoMode.width = 1200;

	this->window = new sf::RenderWindow(this->videoMode, "Sand Sim", sf::Style::Titlebar | sf::Style::Close);
}

// Constructor / Destructor
Game::Game() {
	this->initVars();
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}


// Functions
void Game::update() {
	// Listen for events on the top of every update
	this->pollEvents();
}

void Game::render() {
	this->window->clear();

	this->window->display();
}

void Game::pollEvents() {
	// While getting events from window
	while (this->window->pollEvent(this->eventListener)) {
		switch (this->eventListener.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (eventListener.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
			break;
		}
	}	
}

const bool Game::isRunning(){
	return this->window->isOpen();
}
