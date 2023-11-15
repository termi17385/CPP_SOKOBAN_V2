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

	Coordinate& moveDirection();
	std::map<char, Coordinate*> inputMap;
	Coordinate currentPosition;
	void currentPositionNamed(TileType);
};
