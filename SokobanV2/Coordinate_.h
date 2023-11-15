#pragma once
#include <fstream>


struct Coordinate
{
	int x;
	int y;

	Coordinate(int _x, int _y) : x(_x), y(_y) { }

	/*--------------------------- Operator Overloading --------------------------------*/

	const Coordinate operator+(const Coordinate& _other) const
	{
		Coordinate newCoord(x + _other.x, y + _other.y);
		return newCoord;
	}
	Coordinate& operator+=(const Coordinate& _other)
	{
		x += _other.x;
		y += _other.y;
		return *this; // Return a reference to the current object
	}
	// Friend function to overload the '<<' operator
	friend std::ostream& operator<<(std::ostream& os, const Coordinate& coord)
	{
		os << '(' << coord.x << ", " << coord.y << ')';
		return os;
	}

	Coordinate() = default;
};
class Coordinate_
{
public:

	Coordinate up = Coordinate(-1,0);
	Coordinate down = Coordinate(1,0);
	Coordinate left = Coordinate(0,-1);
	Coordinate right = Coordinate(0,1);

};