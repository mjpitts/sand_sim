#include "Grid.h"
#include <iostream>

// Init size of window 
Grid::Grid() {

}

Grid::~Grid() {

}

/*
		- Initilizes the vector of rectangle shapes.
*/
void Grid::initGrid(){
	
	for (int x = 0; x < this->mapSizeW; x++) {
		for (int y = 0; y < this->mapSizeH; y++) {
			this->gridMap[x][y].setSize(sf::Vector2f(this->TILESIZE, this->TILESIZE));
			this->gridMap[x][y].setFillColor(sf::Color::Black);
			this->gridMap[x][y].setOutlineThickness(1.f);

			// Grid debugg line, comment out to remove grid lines
			this->gridMap[x][y].setOutlineColor(sf::Color(0, 255, 0, 50));

			this->gridMap[x][y].setPosition(x * this->TILESIZE, y * this->TILESIZE);
		}
	}

}

/*
		- Initilizes number of recangle in the x direction.
		- Initilizes number of recangle in the y direction.
		- Creates a Vector of rectangle mapSizeW long and 
		appends it to the grid map vector.
*/
void Grid::initVars(sf::VideoMode& vm){
	// How many tiles in the vertical and horizontal direction
	this->mapSizeH = vm.height / this->TILESIZE;
	this->mapSizeW = vm.width / this->TILESIZE;

	for (int i = 0; i < this->mapSizeW; i++) {

		std::vector<sf::RectangleShape> gridRow;

		for (int j = 0; j < this->mapSizeH; j++) {

			sf::RectangleShape rect;
			gridRow.push_back(rect);

		}
		this->gridMap.push_back(gridRow);
	}
}

void Grid::renderGrid(sf::RenderTarget* target){
	for (int x = 0; x < this->mapSizeW; x++) {
		for (int y = 0; y < this->mapSizeH; y++) {
			target->draw(gridMap[x][y]);
		}
	}
}
