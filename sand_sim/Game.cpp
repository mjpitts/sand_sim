#include "Game.h"
#include <iostream>

// Initializers
void Game::initVars() 
{
	
	// Init window to null first
	this->window = nullptr;

	// Init menuDisplayed to false;
	this->menuDisplayed = false;

	// Initialize to screen position, updates to window position on first frame after initWindow
	this->windowMouse = sf::Mouse::getPosition();
	this->gridMouse = sf::Vector2u(0, 0);
	this->mouseInbounds = true;

	// Set mouseRect properties, this rectangle will act as a cursor on screen.
	this->mouseRect.setSize(sf::Vector2f(grid.getTileSize(), grid.getTileSize()));
	this->mouseRect.setFillColor(sf::Color::Transparent);
	this->mouseRect.setOutlineThickness(1.f);
	// Alpha set to full to contrast grid
	this->mouseRect.setOutlineColor(sf::Color(0, 255, 0));

}

void Game::initWindow() 
{
	// Window settings
	this->videoMode.height = 650.f;
	this->videoMode.width = 900.f;

	this->window = new sf::RenderWindow(this->videoMode, "Sand Sim", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);

}

// Constructor / Destructor
Game::Game() 
{
	this->initVars();
	this->initWindow();

	this->grid.initVars(this->videoMode);
	this->grid.initGrid();

	this->menu = Menu(this->grid.getTileSize(), this->videoMode.height, this->videoMode.width);

}

Game::~Game() 
{

	delete this->window;

}


// Functions

/*
	-Listen for closing events
	-Calculate delta time and add it to time since refresh
	-Update grid and reset time since refresh if treshold met
	-Check mouse inputs
 
	Called once per cycle to update all the moving parts of the sim.
*/
void Game::update() 
{

	// Listen for events on the top of every update
	this->pollEvents();

	// Calculate delta time and add too time since last update
	this->setDeltaTime();
	this->setTimeSinceRefresh(this->timeSinceRefresh + this->dt);

	// Update mouse elements
	this->updateMouse();
	
	// Refresh once threshold is hit
	if (this->timeSinceRefresh >= this->blockRefreshRate) 
	{

		// Update grid, TODO: optimize
		grid.updateGrid();

		this->setTimeSinceRefresh(0);
	}

	// Spawn elements on left click
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->mouseInbounds) 
	{

		grid.spawnWater(gridMouse);

	}
	// Spawn sand on right mouse for now, will create menu later
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && this->mouseInbounds) 
	{

		grid.spawnSand(gridMouse);

	}
	// Delete element with space button
	else if (sf::Keyboard::isKeyPressed((sf::Keyboard::Space)) && this->mouseInbounds) 
	{

		grid.deleteElement(gridMouse);

	}

}

void Game::updateMouse() 
{
	// Mouse updates
	this->windowMouse = sf::Mouse::getPosition(*this->window);

	// If the mouse is out of bounds, force grid cursor into the top left corner
	if (this->windowMouse.x > 0 && this->windowMouse.y > 0 &&
		this->windowMouse.x < this->videoMode.width &&
		this->windowMouse.y < this->videoMode.height) 
	{

		this->gridMouse = sf::Vector2u(
			static_cast<unsigned>(this->windowMouse.x / grid.getTileSize()),
			static_cast<unsigned>(this->windowMouse.y / grid.getTileSize())
		);

		this->mouseInbounds = true;

	}
	else
	{

		this->gridMouse = sf::Vector2u(0, 0);
		this->mouseInbounds = false;

	}

	// Update gridRect position to (gridmouse position * TILESIZE)
	this->mouseRect.setPosition(this->gridMouse.x * grid.getTileSize(), this->gridMouse.y * grid.getTileSize());

}

void Game::render() 
{
	
	// Clear window first
	this->window->clear();

	// Render grid
	grid.renderGrid(this->window);
	
	// Render mouseRect
	this->window->draw(this->mouseRect);

	// Render menu, if conditions met
	if (this->menuDisplayed) 
	{

		this->menu.renderMenu(this->window);

	}

	// Finally display new window
	this->window->display();

}

void Game::pollEvents() 
{
	// While getting events from window
	while (this->window->pollEvent(this->eventListener)) 
	{
		switch (this->eventListener.type)
		{

			case sf::Event::Closed:

				this->window->close();
				break;

			case sf::Event::KeyPressed:

				if (eventListener.key.code == sf::Keyboard::Escape) 
				{
					this->window->close();
				}
				else if(eventListener.key.code == sf::Keyboard::Enter)
				{
					if (this->menuDisplayed) 
					{
						this->menuDisplayed = false;
					}
					else 
					{
						this->menuDisplayed = true;
					}
				}
				break;
			
		}
	}	

}

// Getters 
const bool Game::isRunning()
{

	return this->window->isOpen();

}

float Game::getTimeSinceRefresh() 
{
	
	return this->timeSinceRefresh;

}

float Game::getDeltaTime() 
{
	
	return this->dt;

}

// Setters
void Game::setDeltaTime() 
{

	this->dt = clock.restart().asMilliseconds();

}

void Game::setTimeSinceRefresh(float time) 
{

	this->timeSinceRefresh = time;

}
