#include "Grid.h"
#include <iostream>

// Constructor / Destructor

Grid::Grid() {

}

Grid::~Grid() {

}

// Accessors

/*
	- Returns tile size

	Tile size is the pixel width of every tile in the grid.
*/
const float Grid::getTileSize() const{
	return this->TILESIZE;
}


/*
	- Returns grid map 

	The grid map is a 2d vector containing all the rectangleshapes 
	that make up the grid.
*/
std::vector<std::vector<GridElement>> Grid::getGridMap()
{
	return this->gridMap;
}

// Initializers 

// Init vars comes first, then init grid.

/*
		- Initilizes number of recangle in the x direction.
		- Initilizes number of recangle in the y direction.
		- Creates a Vector of rectangle mapSizeW long and
		appends it to the grid map vector.
*/
void Grid::initVars(sf::VideoMode& vm) {

	// How many tiles in the vertical and horizontal direction
	this->mapSizeH = vm.height / this->TILESIZE;
	this->mapSizeW = vm.width / this->TILESIZE;

	for (int i = 0; i < this->mapSizeW; i++) {

		std::vector<GridElement> gridRow;

		for (int j = 0; j < this->mapSizeH; j++) {

			GridElement elem;
			gridRow.push_back(elem);

		}
		this->gridMap.push_back(gridRow);
	}

}

/*
		- Initilizes the vector of rectangle shapes.
*/
void Grid::initGrid(){
	
	for (int x = 0; x < this->mapSizeW; x++) {
		for (int y = 0; y < this->mapSizeH; y++) {

			this->gridMap[x][y].initGridElement(
				sf::Vector2f(x * this->TILESIZE, y * this->TILESIZE),
				this->TILESIZE,
				sf::Color::Black,
				sf::Color(0, 255, 0, 50)
			);

		}
	}

}

// Functions

/*
	- Loop through grid map and render every rectangle
*/
void Grid::renderGrid(sf::RenderTarget* target){

	for (int x = 0; x < this->mapSizeW; x++) {

		for (int y = 0; y < this->mapSizeH; y++) {

			target->draw(gridMap[x][y].getShape());

		}

	}

}
