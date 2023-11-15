#include <iostream>
#include <vector>
#include <string>

#include "Constants.h"
#include "Game.h"

void runSokoban(const std::vector<std::vector<int>>&, LevelType);

int main()
{
	std::cout << "### SOKOBAN ###" << std::endl << std::endl;

	std::cout << "Controls: " << std::endl;

	std::cout << "UP and DOWN: W/S" << std::endl;
	std::cout << "LEFT and RIGHT: A/D" << std::endl;
	std::cout << "QUIT OR RESTART Q/R" << std::endl;

	std::cout << std::endl << std::endl;

	system("pause");

	std::cout << std::endl << std::endl;

	runSokoban(LEVEL_ONE, LEVELONE);

	std::cout << "**GAME OVER**";

	std::cout << std::endl;

	system("pause");

	return 0;
}

void runSokoban(const std::vector<std::vector<int>>& _level, LevelType _levelType)
{
	Game* game = new Game(new Board(_level), _levelType);

	bool restart = false;
	
	bool quit = false;

	do { quit = game->play(restart); } while (!quit && !restart);

	std::vector<std::vector<int>> restartLevel = game->getCurrentLevel();

	LevelType restartLevelType = game->currentLevel;

	delete game;

	if (restart) runSokoban(restartLevel, restartLevelType);
}