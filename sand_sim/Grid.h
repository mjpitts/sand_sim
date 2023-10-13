#ifndef GRID_H
#define GRID_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>

class Grid
{
private:
	/*
		Number of pixels in heightand width per tile,
		- Tile dim = TILESIZE x TILESIZE.
	*/ 
	const float TILESIZE = 25;

	// Number of tiles in the window, Width then Height.
	float mapSizeW = 0;
	float mapSizeH = 0;

	// All the tiles to be rendered.
	std::vector<std::vector<sf::RectangleShape>> gridMap;


public:

	// Constructor / Destructor
	Grid();
	virtual ~Grid();
	
	// Accessor 
	const float getTileSize() const;
	std::vector<std::vector<sf::RectangleShape>> getGridMap();

	// Init functions
	void initVars(sf::VideoMode& vm);
	void initGrid();

	// Fuunctions
	void renderGrid(sf::RenderTarget* target);
};
#endif

