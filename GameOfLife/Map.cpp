#include "Map.hpp"
#include <iostream>

Map::Map():
	map(screenHeight / cellHeight, std::vector<Cell>(screenWidth / cellWidth))
{
	numberOfCellsX = screenWidth / cellWidth;
	numberOfCellsY = screenHeight / cellHeight;

	FillMap();
}

void Map::FillMap()
{
	int row = 0;
	for (int y = 1; y < screenHeight; y += cellHeight, row++)
	{
		for (int x = 1; x < screenWidth; x += cellWidth)
		{
			map[row].push_back(Cell(x, y));
		}
	}
}

void Map::DrawMap(sf::RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			window.draw(map[i][j].GetShape());
		}
	}
}

void Map::ChangeColorOfCell(int x, int y)
{
	map[y][x].SetColor(sf::Color::Red);

}