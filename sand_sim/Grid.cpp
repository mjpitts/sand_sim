#include "Grid.h"
#include <iostream>

// Constructor / Destructor
Grid::Grid() 
{
	
}

Grid::~Grid() 
{

}

// Accessors
/*
	- Returns tile size

	Tile size is the pixel width of every tile in the grid.
*/
const float Grid::getTileSize() const
{
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
void Grid::initVars(sf::VideoMode& vm) 
{

	// How many tiles in the vertical and horizontal direction
	this->mapSizeH = vm.height / this->TILESIZE;
	this->mapSizeW = vm.width / this->TILESIZE;

	for (int i = 0; i < this->mapSizeW; i++) 
	{

		std::vector<GridElement> gridRow;

		for (int j = 0; j < this->mapSizeH; j++) 
		{

			GridElement elem;
			gridRow.push_back(elem);

		}
		this->gridMap.push_back(gridRow);
	}

	this->elementMovement.setMapSizeH(this->mapSizeH);
	this->elementMovement.setMapSizeW(this->mapSizeW);

}

/*
		- Initilizes the vector of rectangle shapes.
*/
void Grid::initGrid()
{
	
	for (int x = 0; x < this->mapSizeW; x++) 
	{
		for (int y = 0; y < this->mapSizeH; y++) 
		{

			// Set starting grid attributes
			this->gridMap[x][y].initGridElement(
				sf::Vector2f(x * this->TILESIZE, y * this->TILESIZE),
				this->TILESIZE,
				elementTypes::EMPTY
			);

		}
	}

}

// Functions

/*
	- Loop through grid map and render every rectangle
*/
void Grid::renderGrid(sf::RenderTarget* target)
{

	for (int x = 0; x < this->mapSizeW; x++) 
	{

		for (int y = 0; y < this->mapSizeH; y++) 
		{

			// Reset seen flags after update
			this->gridMap[x][y].setSeen(false);

			// Make sure switched elements switch
			this->gridMap[x][y].updateElement();

			// Render element
			target->draw(this->gridMap[x][y].getShape());

		}

	}

}

void Grid::updateGrid() {
	for (int x = 0; x < this->mapSizeW; x++) 
	{
		for (int y = 0; y < this->mapSizeH; y++) 
		{
			
			// Movement control if element is water
			if (this->gridMap[x][y].getType() == elementTypes::WATER) 
			{
		
				this->elementMovement.moveWater(this->gridMap, x, y);

			}
			else if (this->gridMap[x][y].getType() == elementTypes::SAND) 
			{

				this->elementMovement.moveSand(this->gridMap, x, y);

			}
		}
	}
}

void Grid::spawnWater(sf::Vector2u spawnPos) 
{

	this->gridMap[spawnPos.x][spawnPos.y].setType(elementTypes::WATER);

}

void Grid::spawnSand(sf::Vector2u spawnPos) 
{

	this->gridMap[spawnPos.x][spawnPos.y].setType(elementTypes::SAND);

}

/*
	-Calculate deltas
	-Calculate slope
	-Fill in calculated line with wood tiles
	-Fill final destination tile
 

	Takes the line between the last updated gridmouse position and 
	newest gridmouse position and fills in the tiles that intersect with the 
	line with wood tiles. 
*/
void Grid::spawnWood(sf::Vector2u spawnPos, sf::Vector2u prevPos)
{

	double deltaY = static_cast<int>(spawnPos.y) - static_cast<int>(prevPos.y);
	double deltaX = static_cast<int>(spawnPos.x) - static_cast<int>(prevPos.x);

	if (deltaX != 0) 
	{

		double slope = deltaY / deltaX;

		// Mouse moved left to right
		if (prevPos.x < spawnPos.x) 
		{
			for (int i = 1; i < deltaX; i++) 
			{
				if((slope * i) + prevPos.y > 0 && (slope * i) + prevPos.y < this->mapSizeH)
				{
				
					this->gridMap[prevPos.x + i][ceil((slope * i) + prevPos.y)].setType(elementTypes::WOOD);
					this->gridMap[prevPos.x + i][floor((slope * i) + prevPos.y)].setType(elementTypes::WOOD);
				
				}

			}
		}
		// Mouse moved right to left
		else 
		{
			for (int i = 1; i < abs(deltaX); i++)
			{

				if ((slope * i) + prevPos.y > 0 && (slope * i) + prevPos.y < this->mapSizeH)
				{

					this->gridMap[spawnPos.x + i][floor((slope * i) + spawnPos.y)].setType(elementTypes::WOOD);
					this->gridMap[spawnPos.x + i][ceil((slope * i) + spawnPos.y)].setType(elementTypes::WOOD);

				}

			}
		}
	}
	// Vertical mouse movement
	else 
	{
		if (prevPos.y < spawnPos.y)
		{
			for (int i = prevPos.y; i <= spawnPos.y; i++)
			{

				this->gridMap[spawnPos.x][i].setType(elementTypes::WOOD);

			}
		}
		else
		{
			for (int i = spawnPos.y; i <= prevPos.y; i++)
			{

				this->gridMap[spawnPos.x][i].setType(elementTypes::WOOD);

			}
		}
	}

	// Set destination tile
	this->gridMap[spawnPos.x][spawnPos.y].setType(elementTypes::WOOD);

}

void Grid::deleteElement(sf::Vector2u spawnPos) 
{

	this->gridMap[spawnPos.x][spawnPos.y].setType(elementTypes::EMPTY);

}


