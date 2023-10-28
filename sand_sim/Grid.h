#ifndef GRID_H
#define GRID_H

#include <vector>
#include <cmath>
#include "GridElement.h"
#include"LogicCenter.h"

class Grid
{
private:
	/*
		Number of pixels in heightand width per tile,
		- Tile dim = TILESIZE x TILESIZE.

		// NOTE: if this is changed it has to be changed in Menu.h as well
	*/ 
	const float TILESIZE = 10.f;

	// Number of tiles in the window, Width then Height.
	float mapSizeW = 0;
	float mapSizeH = 0;

	// All the tiles to be rendered.
	std::vector<std::vector<GridElement>> gridMap;

	LogicCenter elementMovement;


public:

	// Constructor / Destructor
	Grid();
	~Grid();
	
	// Accessor 
	const float getTileSize() const;
	std::vector<std::vector<GridElement>> getGridMap();

	// Init functions
	void initVars(sf::VideoMode& vm);
	void initGrid();

	// Functions
	void renderGrid(sf::RenderTarget* target);

	void updateGrid();

	// Spawning / Delete handelers
	void spawnWater(sf::Vector2u spawnPos);

	void spawnSand(sf::Vector2u spawnPos);

	void spawnWood(sf::Vector2u spawnPos, sf::Vector2u prevPos);

	void deleteElement(sf::Vector2u spawnPos);

};

#endif

