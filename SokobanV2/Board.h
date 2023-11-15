#pragma once
#include <iostream>
#include <vector>
#include <map>

enum TileType : int
{
	WALL = -1,
	EMPTY = 0,
	PLAYER = 1,
	BOX = 2,
	GOAL = 3,
	PLAYER_ON_GOAL = 4,
	BOX_ON_GOAL = 5
};

class Board
{
private:
	
	std::map<int, char> characterMap;
	std::vector<std::vector<int>> currentLevel;

public:

	Board() = default;
	
	Board(const std::vector<std::vector<int>>& currentLevel)
		: currentLevel(currentLevel) 
	{
		currentLevelClean = currentLevel;

		characterMap[PLAYER_ON_GOAL] =  'P';
		characterMap[BOX_ON_GOAL] = '@';
		characterMap[PLAYER] = 'P';
		characterMap[BOX] =  'B';

		characterMap[EMPTY]  =  '.';
		characterMap[GOAL]	 =  'x';
		characterMap[WALL]	 =  'ß';
	}

	std::vector<std::vector<int>>& getCurrentLevel();
	
	void setCurrentLevel(std::vector<std::vector<int>>& _nextLevel);

	void displayBoard();

	std::vector<std::vector<int>> currentLevelClean;
};