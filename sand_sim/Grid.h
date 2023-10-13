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
	const float TILESIZE = 25;
	float mapSizeW = 0;
	float mapSizeH = 0;
	std::vector<std::vector<sf::RectangleShape>> gridMap;


public:

	// Constructor / Destructor
	Grid();
	virtual ~Grid();
	
	// Accessor 
	const float getTileSize() const;
	std::vector<std::vector<sf::RectangleShape>> getGridMap();

	// Functions
	void initVars(sf::VideoMode& vm);
	void initGrid();
	void renderGrid(sf::RenderTarget* target);
};
#endif

