#pragma once
#include <SFML/Graphics.hpp>

const int screenWidth = 800;
const int screenHeight = 600;

const int cellWidth = 18; // + 2(border) = 20
const int cellHeight = 18;// + 2(border) = 20

struct Point
{
	int x;
	int y;
};