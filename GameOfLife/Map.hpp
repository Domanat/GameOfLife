#pragma once
#include <string>
#include <vector>
#include "Constants.hpp"
#include "Cell.hpp"

class Map
{
public:
	Map();
	void DrawMap();

private:
	void FillMap();

	std::vector<std::vector<Cell>> map;
	
	int numberOfCellsX;
	int numberOfCellsY;
};

