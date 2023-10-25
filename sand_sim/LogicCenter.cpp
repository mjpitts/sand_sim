#include "LogicCenter.h"

// Setters
void LogicCenter::setMapSizeW(float mapSizeW) 
{

	this->mapSizeW = mapSizeW;

}

void LogicCenter::setMapSizeH(float mapSizeH) 
{

	this->mapSizeH = mapSizeH;

}

// Functions
void LogicCenter::moveWater(std::vector<std::vector<GridElement>>& gridMap, int x, int y) 
{

	

	// As long as element isn't at the bottom, move water down. 
	if (this->moveDown(gridMap, x, y, this->waterMoveThrough));

	else if (!gridMap[x][y].getSeen()) 
	{

		// Try rand first, if it fails then tile is on the edge and the opposing choice will be made later
		if (spreadRand(gridMap, x, y, this->waterMoveThrough));

		else if (spreadRight(gridMap, x, y, this->waterMoveThrough));

		else if (spreadLeft(gridMap, x, y, this->waterMoveThrough));

		else if (moveRand(gridMap, x, y, this->waterMoveThrough, 4));
	}

}

void LogicCenter::moveSand(std::vector<std::vector<GridElement>>& gridMap, int x, int y) 
{

	// As long as element isn't at the bottom or above water, move sand down. 
	if (this->moveDown(gridMap, x, y, this->sandMoveThrough));

	// Try rand first, if it fails then tile is on the edge and the opposing choice will be made later
	else if (spreadRand(gridMap, x, y, this->sandMoveThrough));

	else if (spreadRight(gridMap, x, y, this->sandMoveThrough));

	else if (spreadLeft(gridMap, x, y, this->sandMoveThrough));

}

bool LogicCenter::moveDown(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) 
{

	bool moved = false;

	if (y + 1 < this->mapSizeH && !gridMap[x][y].getSeen()) 
	{

		for (int i = 0; i < moveThrough.size(); i++) 
		{

			if (moveThrough[i] == gridMap[x][y + 1].getType()) 
			{
				moved = true;
			}

		}
		if (moved) 
		{

			elementTypes bottomType = gridMap[x][y + 1].getType();
			elementTypes topType = gridMap[x][y].getType();
	
			gridMap[x][y + 1].setType(topType);
			gridMap[x][y].setType(bottomType);

			gridMap[x][y + 1].setSeen(true);

		}
		

	}


	return moved;

}

bool LogicCenter::spreadRight(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) {
	
	bool moved = false; 

	if (y + 1 < this->mapSizeH && x + 1 < this->mapSizeW && !gridMap[x][y].getSeen()) 
	{

		for (int i = 0; i < moveThrough.size(); i++) 
		{

			if (moveThrough[i] == gridMap[x + 1][y + 1].getType()) 
			{
				moved = true;
			}

		}

		if (moved) 
		{

			elementTypes bottomType = gridMap[x + 1][y + 1].getType();
			elementTypes topType = gridMap[x][y].getType();

			gridMap[x + 1][y + 1].setType(topType);
			gridMap[x][y].setType(bottomType);

			gridMap[x + 1][y + 1].setSeen(true);

		}
	}

	return moved;

}

bool LogicCenter::spreadLeft(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) 
{

	bool moved = false;

	if (y + 1 < this->mapSizeH && x - 1 > 0 && !gridMap[x][y].getSeen()) 
	{

		for (int i = 0; i < moveThrough.size(); i++) 
		{

			if (moveThrough[i] == gridMap[x - 1][y + 1].getType()) 
			{
				moved = true;
			}

		}

		if (moved) 
		{

			elementTypes bottomType = gridMap[x - 1][y + 1].getType();
			elementTypes topType = gridMap[x][y].getType();

			gridMap[x - 1][y + 1].setType(topType);
			gridMap[x][y].setType(bottomType);

			gridMap[x - 1][y + 1].setSeen(true);

		}
	}

	return moved;

}

bool LogicCenter::spreadRand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) 
{
	
	bool moved = false;
	int dir = rand() % 2;

	if (dir == 0) 
	{
		moved = this->spreadLeft(gridMap, x, y, moveThrough);
	}
	else 
	{
		moved = this->spreadRight(gridMap, x, y, moveThrough);
	}

	return moved;

}

bool LogicCenter::moveRand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough, int viscosity) 
{
	bool moved = false;
	int dir = rand() % 2;

	if (dir == 0) 
	{
		moved = this->moveRight(gridMap, x, y, moveThrough, viscosity);
	}else
	{
		moved = this->moveLeft(gridMap, x, y, moveThrough, viscosity);
	}

	return moved;

}

bool LogicCenter::moveRight(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough, int viscosity)
{

	bool moved = false;

	for (int i = 1; i <= viscosity; i++)
	{
		if (x + i < this->mapSizeW && gridMap[x + i][y].getType() == elementTypes::EMPTY && i < viscosity)
		{
			continue;
		}
		else if (i != 1)
		{
			
			int newX = x + i - 1;
			if (x + i - 1 >= this->mapSizeW)
			{
				newX = this->mapSizeW - 1;
			}

			if (gridMap[newX][y].getType() == elementTypes::EMPTY) 
			{
				elementTypes swapType = gridMap[newX][y].getType();
				elementTypes originType = gridMap[x][y].getType();

				gridMap[newX][y].setType(originType);
				gridMap[x][y].setType(swapType);

				gridMap[newX][y].setSeen(true);

				moved = true;
			}

		}
		else 
		{
			break;
		}
	}

	return moved;

}

bool LogicCenter::moveLeft(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough, int viscosity) 
{

	bool moved = false;

	for (int i = 1; i <= viscosity; i++)
	{

		if (x - i > 0 && gridMap[x - i][y].getType() == elementTypes::EMPTY && i < viscosity)
		{
			continue;
		}
		else if (i != 1)
		{
			int newX = x - i + 1;
			if (x - i + 1 < 0) 
			{
				newX = 0;
			}

			if (gridMap[newX][y].getType() == elementTypes::EMPTY) 
			{
				elementTypes swapType = gridMap[newX][y].getType();
				elementTypes originType = gridMap[x][y].getType();

				gridMap[newX][y].setType(originType);
				gridMap[x][y].setType(swapType);

				gridMap[newX][y].setSeen(true);

				moved = true;
			}

		}
		else 
		{
			break;
		}
	}	



	return moved;

}

