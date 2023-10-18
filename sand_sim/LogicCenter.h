#ifndef LOGICCENTER_H
#define LOGICCENTER_H

#include <vector>
#include "GridElement.h"

class LogicCenter
{
private:

	const float refreshTime = 50.f;

public:

	// Controls the movement of water 
	void moveWater(std::vector<std::vector<GridElement>>& gridMap, int x, int y, float mapSizeW, float mapSizeH);

	// Controls the movement of sand
	void moveSand(std::vector<std::vector<GridElement>>& gridMap, int x, int y, float mapSizeW, float mapSizeH);
};

#endif

