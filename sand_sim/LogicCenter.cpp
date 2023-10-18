#include "LogicCenter.h"

void LogicCenter::moveWater(std::vector<std::vector<GridElement>>& gridMap, int x, int y, float mapSizeW, float mapSizeH, float time) {
	// As long as element isn't at the bottom, move water down. 
	if (y + 1 < mapSizeH && time >= this->refreshTime &&
		!gridMap[x][y].getSeen() &&
		gridMap[x][y + 1].getType() == elementTypes::EMPTY) {

		gridMap[x][y + 1].setType(elementTypes::WATER);
		gridMap[x][y].setType(elementTypes::EMPTY);

		gridMap[x][y + 1].setSeen(true);

	}
	else if (y + 1 < mapSizeH && time >= this->refreshTime &&
		x > 0 &&
		x + 1 < mapSizeW &&
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
	}
}

void LogicCenter::moveSand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, float mapSizeW, float mapSizeH, float time) {
	// As long as element isn't at the bottom, move water down. 
	if (y + 1 < mapSizeH && time >= this->refreshTime &&
		!gridMap[x][y].getSeen() &&
		(gridMap[x][y + 1].getType() == elementTypes::EMPTY ||gridMap[x][y + 1].getType() == elementTypes::WATER)
		) {

		// FIX!!! send water straigh to the bottom, need to remove dependance on framerate
		gridMap[x][y].setType(gridMap[x][y + 1].getType());
		gridMap[x][y + 1].setType(elementTypes::SAND);
		

		gridMap[x][y + 1].setSeen(true);

	}
	else if (y + 1 < mapSizeH && time >= this->refreshTime &&
		x > 0 &&
		x + 1 < mapSizeW &&
		!gridMap[x][y].getSeen()) {

		// Check right diagonal
		if (gridMap[x][y + 1].getType() == elementTypes::EMPTY || gridMap[x][y + 1].getType() == elementTypes::WATER) {

			gridMap[x][y].setType(gridMap[x + 1][y + 1].getType());
			gridMap[x + 1][y + 1].setType(elementTypes::SAND);

			gridMap[x + 1][y + 1].setSeen(true);

		}
		// Check left diagonal
		else if (gridMap[x][y + 1].getType() == elementTypes::EMPTY || gridMap[x][y + 1].getType() == elementTypes::WATER) {

			gridMap[x][y].setType(gridMap[x - 1][y + 1].getType());
			gridMap[x - 1][y + 1].setType(elementTypes::SAND);

			gridMap[x - 1][y + 1].setSeen(true);
		}
	}
}
