#pragma once
#include<iostream>
#include"Player.h"

// when updating this, update the max value + 1 to the last level added.
enum LevelType
{
	LEVELONE = 0,
	
	LEVELTWO = 1,
	
	LEVELTHREE = 2,
	
	LEVELFOUR = 3,
	
	LEVELFIVE = 4,
	
	LEVELSIX = 5,
	
	LEVELMAX = 6
};

class Game
{
public:
	
	Game(Board* _board, LevelType _currentLevel) : currentBoard(_board)
	{
		currentPlayer = new Player(determineSpecialTiles());

		goalsCount = goalPositions.size();

		currentLevel = _currentLevel;
	}

	Game(Board* _board) : currentBoard(_board) 
	{
		currentPlayer = new Player(determineSpecialTiles());
		
		goalsCount = goalPositions.size();

		currentLevel = LEVELONE;
	}

	bool play(bool&);

	std::vector<std::vector<int>>& getCurrentLevel() { return currentBoard->currentLevelClean; }

	LevelType currentLevel;

	~Game()
	{
		delete currentPlayer;
		delete currentBoard;
	}

private:
	
	void changeLevel();

	void resetBoard(const std::vector<std::vector<int>>&);

	Board* currentBoard;
	
	Player* currentPlayer;

	std::vector<Coordinate> goalPositions;

	int goalsCount = 0;

	std::vector<std::vector<int>> levelSelection(LevelType _level);
	
	Coordinate& determineSpecialTiles();

	bool winCondition();
};