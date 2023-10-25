#ifndef LOGICCENTER_H
#define LOGICCENTER_H

#include <iostream>
#include <vector>
#include "GridElement.h"

class LogicCenter
{
private:

	// Elements that water can pass through.
	std::vector<elementTypes> waterMoveThrough = { elementTypes::EMPTY };

	// Elements that sand can pass through.
	std::vector<elementTypes> sandMoveThrough = { elementTypes::EMPTY, elementTypes::WATER };

	float mapSizeW;
	float mapSizeH;

	const float refreshTime = 50.f;

public:

	// Setters
	void setMapSizeW(float mapSizeW);

	void setMapSizeH(float mapSizeH);

	/*
		Element wise movements:

		Element wise movements are called once per update and define how that element
		will move on the screen and interact with other elements.

	*/

	// Controls the movement of water 
	void moveWater(std::vector<std::vector<GridElement>>& gridMap, int x, int y);

	// Controls the movement of sand
	void moveSand(std::vector<std::vector<GridElement>>& gridMap, int x, int y);

	/*
		Movement blocks:

		Movement blocks are building blocks for elementwise movement. Each block models a common movement and interaction.
	*/

	// Move elements downwards based on what elements they can pass through
	bool moveDown(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough);

	// Try to spread to right bottom if possible
	bool spreadRight(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough);
	
	// Try to spread to left bottom if possible
	bool spreadLeft(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough);
	
	// Equally likely to spread left or right
	bool spreadRand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough);

	// Try to move right a set number of blocks, settle for less if possible 
	bool moveRight(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough, int viscosity);

	// Try to move left a set number of blocks, settle for less if possible 
	bool moveLeft(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough, int viscosity);
	
	// Equally likely to moveRight or moveLeft
	bool moveRand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough, int viscosity);
	
};

#endif

