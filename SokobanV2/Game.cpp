#include "Game.h"
#include "Constants.h"

bool Game::play(bool& _restart)
{
	auto& level = currentBoard->getCurrentLevel();

	currentBoard->displayBoard();

	currentPlayer->movePlayer(level);

	_restart = currentPlayer->restarted;

	if (winCondition())
	{
		// change level
		changeLevel();

		currentBoard->displayBoard();
	}

	return currentPlayer->quitted;
}

std::vector<std::vector<int>> Game::levelSelection(LevelType _level)
{
	switch (_level)
	{
	case LEVELONE:
		return LEVEL_ONE;
	case LEVELTWO:
		return LEVEL_TWO;
	case LEVELTHREE:
		return LEVEL_THREE;
	case LEVELFOUR:
		return LEVEL_FOUR;
	case LEVELFIVE:
		return LEVEL_FIVE;
	case LEVELSIX:
		return LEVEL_SIX;
	}

	return std::vector<std::vector<int>>();
}

void Game::changeLevel()
{
	int current = currentLevel;
	
	current++;

	if (current >= (int)LEVELMAX)
	{
		currentPlayer->quitted = true;
		return;
	}

	LevelType nextLevel = static_cast<LevelType>(current);

	auto level = levelSelection(nextLevel);
	
	currentLevel = nextLevel;
	
	resetBoard(level);
}

Coordinate& Game::determineSpecialTiles()
{
	auto& level = currentBoard->getCurrentLevel();
	
	size_t row = level.size();
	size_t col = level[1].size();

	Coordinate player_coords;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Coordinate tempCoord = Coordinate(i,j);

			if (level[i][j] == PLAYER) player_coords = tempCoord;
			else if (level[i][j] == GOAL) goalPositions.push_back(tempCoord);
		}
	}

	return player_coords;
}

void Game::resetBoard(const std::vector<std::vector<int>>& _newLevel)
{
	goalPositions.clear();

	currentBoard = new Board(_newLevel);

	currentPlayer = new Player(determineSpecialTiles());

	goalsCount = goalPositions.size();
}

bool Game::winCondition()
{
	int count = 0;
	for (size_t i = 0; i < goalPositions.size(); i++)
	{
		Coordinate pos = goalPositions[i];
		auto& level = currentBoard->getCurrentLevel();
		if (level[pos.x][pos.y] == BOX_ON_GOAL) count++;
	}
	return count >= goalsCount;
}
