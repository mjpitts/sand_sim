#include "Game.h"
#include <iostream>

// Initializers
void Game::initVars() {

	// Init window to null first
	this->window = nullptr;

	// Initialize to screen position, updates to window position on first frame after initWindow
	this->windowMouse = sf::Mouse::getPosition();
	this->gridMouse = sf::Vector2u(0, 0);

	// Set mouseRect properties, this rectangle will act as a cursor on screen.
	this->mouseRect.setSize(sf::Vector2f(grid.getTileSize(), grid.getTileSize()));
	this->mouseRect.setFillColor(sf::Color::Black);
	this->mouseRect.setOutlineThickness(1.f);
	// Alpha set to full to contrast grid
	this->mouseRect.setOutlineColor(sf::Color(0, 255, 0));
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

	this->grid.initVars(this->videoMode);
	this->grid.initGrid();
}

Game::~Game() {
	delete this->window;
}


// Functions
void Game::update() {

	// Listen for events on the top of every update
	this->pollEvents();

	// Mouse updates
	this->windowMouse = sf::Mouse::getPosition(*this->window);
	this->gridMouse = sf::Vector2u(
		static_cast<unsigned>(this->windowMouse.x / grid.getTileSize()),
		static_cast<unsigned>(this->windowMouse.y / grid.getTileSize())
	);

	std::cout << "grid mouse: " << this->gridMouse.x << " " << this->gridMouse.y << "\n";

	// Update gridRect position to (gridmouse position * TILESIZE)
	this->mouseRect.setPosition(this->gridMouse.x * grid.getTileSize(), this->gridMouse.y * grid.getTileSize());
}

void Game::render() {
	
	// Clear window first
	this->window->clear();

	// Render grid
	grid.renderGrid(this->window);
	// Render mouseRect
	this->window->draw(this->mouseRect);

	// Finally display new window
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
