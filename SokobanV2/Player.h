#pragma once

#include "Board.h"
#include "Coordinate_.h"
#include <vector>
#include <map>

class Player
{
public:
	
	Player() = default;
	Player(Coordinate);
	
	Coordinate& getCurrentPosition();
	void setCurrentPosition(Coordinate&);
	void movePlayer(std::vector<std::vector<int>>&);

	bool quitted = false;
	bool restarted = false;

private:

	Coordinate currentPosition = Coordinate(0,0);
	std::map<char, Coordinate*> inputMap;

	Coordinate& moveDirection();
	void currentPositionNamed(TileType);
};
