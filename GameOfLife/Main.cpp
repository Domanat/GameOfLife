#include <iostream>
#include <vector>
#include <string>
#include <thread>

const int mapSize = 20;

typedef std::vector<std::string> Map;

enum State {Die = 0, Born, Live, None};

void printMap(Map& map)
{
	for (int i = 0; i < mapSize; i++)
	{
		std::cout << map[i] << std::endl;
	}
}

void fillMap(Map& map)
{

	for (int i = 0; i < mapSize; i++)
	{
		for (int j = 0; j < mapSize; j++)
		{
			map[i].append(".");
		}
	}
}



void spawnCells(Map& map)
{
	
}

State checkNeighbours(Map& map, int x, int y)
{
	int numberOfNeighbours = 0;

	// Top left neighbour
	if (y - 1 >= 0 && x - 1 >= 0 && map[y - 1][x - 1] == 'O')
		numberOfNeighbours++;
	// Top neighbour
	if (y - 1 >= 0 && x >= 0 && map[y - 1][x] == 'O')
		numberOfNeighbours++;
	// Top right neighbour
	if (y - 1 >= 0 && x + 1 < mapSize && map[y - 1][x + 1] == 'O')
		numberOfNeighbours++;
	// Right neighbour
	if (x + 1 < mapSize && map[y][x + 1] == 'O')
		numberOfNeighbours++;
	// Left neighbour
	if (x - 1 >= 0 && map[y][x - 1] == 'O')
		numberOfNeighbours++;
	// Bottom left neighbour
	if (y + 1 < mapSize && x - 1 >= 0 && map[y + 1][x - 1] == 'O')
		numberOfNeighbours++;
	// Bottom neighbour
	if (y + 1 < mapSize && map[y + 1][x] == 'O')
		numberOfNeighbours++;
	// Bottom right neighbour
	if (y + 1 < mapSize && x + 1 < mapSize && map[y + 1][x + 1] == 'O')
		numberOfNeighbours++;

	//std::cout << "Number of neighbours: " << numberOfNeighbours << std::endl;

	switch (numberOfNeighbours)
	{
	case 2:
		if (map[y][x] == 'O')
			return State::Live;
		else
			return State::None;

	case 3:
		if (map[y][x] == 'O')
			return State::Live;
		else
			return State::Born;
	default:
		return State::Die;
	}

}

void refreshMap(Map& map)
{
	for (int y = 0; y < mapSize; y++)
	{
		for (int x = 0; x < mapSize; x++)
		{
			State state = checkNeighbours(map, x, y);

			switch (state)
			{
			case Die:
				//std::cout << "Dies" << std::endl;
				map[y][x] = '.';
				break;
			case Live:
				//std::cout << "Live" << std::endl;

				break;
			case Born:
				//std::cout << "Born" << std::endl;
				map[y][x] = 'O';
				break;
			default:
				//std::cout << "None" << std::endl;
				break;

			}
		}

		std::cout << map[y] << std::endl;
	}
}

/*
	Rules:
	1) If there is less than 2 neighbours cell is dying.
	2) If there are 3 or 2 neighbours cell is goes to the second generation
	3) if there are more than 3 neighbours cell is dying.
	4) if there are 3 neighbours around cell, cell is born.

*/
int main()
{
	Map map{ 
		"......O..O......O..",
		"..O....O.O..O.O.O..",
		".O.O..O..O...OO....",
		".....O..O.O...O....",
		"....O.....O........",
		"...........O.......",
		"..O.OO..O......O...",
		"..........O..O.....",
		".O....O.......O....",
		"..........O......O.",
		".OO.....O.....O....",
		"................O..",
		"..O....O....O..O...",
		"......O.....O..O...",
		".O.......OOO....O..",
		"..O........O.......",
		"......OO.O...O..O..",
		"...O....O...O......",
		".O......O...O...O..",
		".....O....O....O..."};

	fillMap(map);

	char choice;

	for (int i = 0; i < 100; i++)
	{
		printMap(map);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		refreshMap(map);
		system("cls");
	}

	return 0;
}