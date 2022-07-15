#pragma once

#include <string>
#include "Constants.hpp"

class Cell
{

public:

	Cell(int x, int y);

	void SetPosition(Point newPos);

	Point GetPosition();
	sf::RectangleShape& GetShape();
	sf::Color GetColor();


private:


	Point position;
	sf::RectangleShape rect;
	sf::Color color;

};

