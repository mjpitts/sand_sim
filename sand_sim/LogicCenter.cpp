#include "LogicCenter.h"

// Setters
void LogicCenter::setMapSizeW(float mapSizeW) {
	this->mapSizeW = mapSizeW;
}

void LogicCenter::setMapSizeH(float mapSizeH) {
	this->mapSizeH = mapSizeH;
}

// Functions
void LogicCenter::moveWater(std::vector<std::vector<GridElement>>& gridMap, int x, int y) {

	// Elements that water can pass through.
	std::vector<elementTypes> passThrough = { elementTypes::EMPTY };

	// As long as element isn't at the bottom, move water down. 
	if (this->moveDown(gridMap, x, y, passThrough));

	else if (y + 1 < this->mapSizeH &&
		x > 0 &&
		x + 1 < this->mapSizeW &&
		!gridMap[x][y].getSeen()) {

		// Check right diagonal
		if (gridMap[x + 1][y + 1].getType() == elementTypes::EMPTY) {

			gridMap[x + 1][y + 1].setType(elementTypes::WATER);
			gridMap[x][y].setType(elementTypes::EMPTY);

			gridMap[x + 1][y + 1].setSeen(true);

		}
		// Check left diagonal
		else if (gridMap[x - 1][y + 1].getType() == elementTypes::EMPTY) {

			gridMap[x - 1][y + 1].setType(elementTypes::WATER);
			gridMap[x][y].setType(elementTypes::EMPTY);

			gridMap[x - 1][y + 1].setSeen(true);
		}
		// Check spread
		else if (x - 1  > 0 && x + 1 < mapSizeW) {

			int dir = rand() % 2;

			if(x - 2 > 0 && x + 2 < mapSizeW){

				if (gridMap[x + 1][y].getType() == elementTypes::EMPTY &&
					gridMap[x + 2][y].getType() == elementTypes::EMPTY &&
					dir == 0) {
					gridMap[x + 2][y].setType(elementTypes::WATER);
					gridMap[x][y].setType(elementTypes::EMPTY);

					gridMap[x + 2][y].setSeen(true);
				}
				else if (gridMap[x - 1][y].getType() == elementTypes::EMPTY &&
					gridMap[x - 2][y].getType() == elementTypes::EMPTY &&
					dir == 1) {
					gridMap[x - 2][y].setType(elementTypes::WATER);
					gridMap[x][y].setType(elementTypes::EMPTY);

					gridMap[x - 2][y].setSeen(true);
				}

			}
			
			else if (gridMap[x + 1][y].getType() == elementTypes::EMPTY && dir == 0) {
				gridMap[x + 1][y].setType(elementTypes::WATER);
				gridMap[x][y].setType(elementTypes::EMPTY);

				gridMap[x + 1][y].setSeen(true);
			}

			else if (gridMap[x - 1][y].getType() == elementTypes::EMPTY && dir == 1) {
				gridMap[x - 1][y].setType(elementTypes::WATER);
				gridMap[x][y].setType(elementTypes::EMPTY);

				gridMap[x - 1][y].setSeen(true);
			}

		}	
		else if (x + 1 < this->mapSizeW) {

			if (x + 2 < this->mapSizeW) {

				if (gridMap[x + 1][y].getType() == elementTypes::EMPTY &&
					gridMap[x + 2][y].getType() == elementTypes::EMPTY) {
					gridMap[x + 2][y].setType(elementTypes::WATER);
					gridMap[x][y].setType(elementTypes::EMPTY);

					gridMap[x + 2][y].setSeen(true);
				}
				
			}

			else if (gridMap[x + 1][y].getType() == elementTypes::EMPTY) {
				gridMap[x + 1][y].setType(elementTypes::WATER);
				gridMap[x][y].setType(elementTypes::EMPTY);

				gridMap[x + 1][y].setSeen(true);
			}

		}
		else if (x - 1 < 0) {

			if (x - 2 < 0) {

				if (gridMap[x - 1][y].getType() == elementTypes::EMPTY &&
					gridMap[x - 2][y].getType() == elementTypes::EMPTY) {
					gridMap[x - 2][y].setType(elementTypes::WATER);
					gridMap[x][y].setType(elementTypes::EMPTY);

					gridMap[x - 2][y].setSeen(true);
				}

			}

			else if (gridMap[x - 1][y].getType() == elementTypes::EMPTY) {
				gridMap[x - 1][y].setType(elementTypes::WATER);
				gridMap[x][y].setType(elementTypes::EMPTY);

				gridMap[x - 1][y].setSeen(true);
			}

		}
	}

}

void LogicCenter::moveSand(std::vector<std::vector<GridElement>>& gridMap, int x, int y) {

	// Elements that sand can pass through.
	std::vector<elementTypes> passThrough = { elementTypes::EMPTY, elementTypes::WATER};

	// As long as element isn't at the bottom or above water, move sand down. 
	if (this->moveDown(gridMap, x, y, passThrough));

	// Try rand first, if it fails then tile is on the edge and the opposing choice will be made later
	else if (spreadRand(gridMap, x, y, passThrough));

	else if (spreadRight(gridMap, x, y, passThrough));

	else if (spreadLeft(gridMap, x, y, passThrough));
}

bool LogicCenter::moveDown(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) {

	bool moved = false;

	if (y + 1 < this->mapSizeH && !gridMap[x][y].getSeen()) {

		for (int i = 0; i < moveThrough.size(); i++) {

			if (moveThrough[i] == gridMap[x][y + 1].getType()) {
				moved = true;
			}

		}
		if (moved) {

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

	if (y + 1 < this->mapSizeH && x + 1 < this->mapSizeW && !gridMap[x][y].getSeen()) {

		for (int i = 0; i < moveThrough.size(); i++) {

			if (moveThrough[i] == gridMap[x + 1][y + 1].getType()) {
				moved = true;
			}

		}

		if (moved) {

			elementTypes bottomType = gridMap[x + 1][y + 1].getType();
			elementTypes topType = gridMap[x][y].getType();

			gridMap[x + 1][y + 1].setType(topType);
			gridMap[x][y].setType(bottomType);

			gridMap[x + 1][y + 1].setSeen(true);

		}
	}

	return moved;
}

bool LogicCenter::spreadLeft(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) {

	bool moved = false;

	if (y + 1 < this->mapSizeH && x - 1 > 0 && !gridMap[x][y].getSeen()) {

		for (int i = 0; i < moveThrough.size(); i++) {

			if (moveThrough[i] == gridMap[x - 1][y + 1].getType()) {
				moved = true;
			}

		}

		if (moved) {

			elementTypes bottomType = gridMap[x - 1][y + 1].getType();
			elementTypes topType = gridMap[x][y].getType();

			gridMap[x - 1][y + 1].setType(topType);
			gridMap[x][y].setType(bottomType);

			gridMap[x - 1][y + 1].setSeen(true);

		}
	}

	return moved;
}

bool LogicCenter::spreadRand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) {
	
	bool moved = false;
	int dir = rand() % 2;

	if (dir == 0) {
		moved = this->spreadLeft(gridMap, x, y, moveThrough);
	}
	else {
		moved = this->spreadRight(gridMap, x, y, moveThrough);
	}

	return moved;
}

bool LogicCenter::moveLeft(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) {

	return false;
}

bool LogicCenter::moveRight(std::vector<std::vector<GridElement>>& gridMap, int x, int y, std::vector<elementTypes> moveThrough) {

	return false;
}
