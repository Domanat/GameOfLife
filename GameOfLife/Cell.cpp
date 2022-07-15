#include "Cell.hpp"


Cell::Cell(int x, int y) :
	position(Point(x, y)),
	rect(sf::Vector2f(cellWidth, cellHeight)),
	color(sf::Color::White)
{
	rect.setFillColor(color);
	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(1.f);
}

void Cell::SetPosition(Point newPos)
{
	position = newPos;
}

Point Cell::GetPosition()
{
	return position;
}

sf::RectangleShape& Cell::GetShape()
{
	return rect;
}

sf::Color Cell::GetColor()
{
	return color;
}