#include "Map.hpp"
#include <iostream>

Map::Map()
{
	// Create map
	// Fill cells

	numberOfCellsX = screenWidth / 20;
	numberOfCellsY = screenHeight / 20;


}

void Map::FillMap()
{
	for (int y = 0; y < numberOfCellsY; y++)
	{
		for (int x = 0; x < numberOfCellsX; x++)
		{

		}
	}
}

void Map::DrawMap()
{

}