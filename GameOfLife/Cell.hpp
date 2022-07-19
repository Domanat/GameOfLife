#pragma once

#include <string>
#include "Constants.hpp"

class Cell
{

public:

	Cell();
	Cell(int x, int y);

	void SetPosition(Point newPos);
	void SetOutlineThickness(float width);
	void SetColor(sf::Color color);

	Point GetPosition();
	sf::RectangleShape& GetShape();
	sf::Color GetColor();


private:

	Point position;
	sf::RectangleShape rect;
	sf::Color color;

};

