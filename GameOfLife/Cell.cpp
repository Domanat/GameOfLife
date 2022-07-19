#include "Cell.hpp"

Cell::Cell()
{

}

Cell::Cell(int x, int y) :
	position(Point(x, y)),
	rect(sf::Vector2f(cellWidth - 2, cellHeight - 2)),
	color(sf::Color::Black)
{
	rect.setPosition(sf::Vector2f(position.x, position.y));
	rect.setFillColor(color);
	rect.setOutlineColor(sf::Color::Green);
	rect.setOutlineThickness(1.f);
}

void Cell::SetPosition(Point point)
{
	//position = newPos;
	rect.setPosition(sf::Vector2f(point.x, point.y));
}

void Cell::SetOutlineThickness(float width)
{
	rect.setOutlineThickness(width);
}

void Cell::SetColor(sf::Color newColor)
{
	rect.setFillColor(newColor);
}

Point Cell::GetPosition()
{
	return Point(rect.getPosition().x, rect.getPosition().y);
}

sf::RectangleShape& Cell::GetShape()
{
	return rect;
}

sf::Color Cell::GetColor()
{
	return color;
}