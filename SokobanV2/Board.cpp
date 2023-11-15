#include "Board.h"
#include <iomanip>

std::vector<std::vector<int>>& Board::getCurrentLevel()
{
	return currentLevel;
}

void Board::displayBoard()
{
	system("CLS");

	size_t row = currentLevel.size();
	size_t col = currentLevel[0].size();

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			size_t combinedIndex = i + j;
			size_t max = (row - 1) + (col - 1);
			
			if (combinedIndex > 0 && combinedIndex < max) std::cout << std::setw(2) << characterMap[currentLevel[i][j]];
			else std::cout << std::setw(2) << i;
		}
		
		std::cout << std::endl;
	}
}

void Board::setCurrentLevel(std::vector<std::vector<int>>& _nextLevel)
{
	currentLevel = _nextLevel;
}