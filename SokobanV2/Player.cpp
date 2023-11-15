#include "Player.h"
#include <iostream>

Coordinate_ coord;

Player::Player(Coordinate _setPosition)
{
	currentPosition = _setPosition;
	inputMap['W'] = &coord.up;
	inputMap['w'] = &coord.up;

	inputMap['S'] = &coord.down;
	inputMap['s'] = &coord.down;

	inputMap['A'] = &coord.left;
	inputMap['a'] = &coord.left;

	inputMap['D'] = &coord.right;
	inputMap['d'] = &coord.right;

}


Coordinate& Player::moveDirection()
{
	static auto coord = Coordinate(0, 0);

	std::cout << "Please input a move! (w,a,s,d) quit or restart (q/r): ";

	static char input;

	std::cin >> input;

	std::cout << std::endl;

	if (input == 'q' || input == 'Q') quitted = true;

	if (input == 'r' || input == 'R') restarted = true;
	
	if (!inputMap.contains(input)) return coord;

	return *inputMap[input];
}

void Player::currentPositionNamed(TileType _type)
{
	std::string str;
	
	std::cout << "Player is at position: " << currentPosition;

	switch (_type)
	{
		case PLAYER_ON_GOAL:
			str = " Type: On Goal";
			break;
		case PLAYER:
			str = " Type: Not On Goal";
			break;
	}

	std::cout << str << std::endl << std::endl;
}

Coordinate& Player::getCurrentPosition()
{
	return currentPosition;
}

void Player::setCurrentPosition(Coordinate& _newCoords)
{
	currentPosition = _newCoords;
}

void Player::movePlayer(std::vector<std::vector<int>>& _currentLevel)
{
	std::cout << std::endl << std::endl;

	Coordinate direction = moveDirection();

	if (restarted || quitted) return;

	Coordinate lastPosition = currentPosition;
	Coordinate nextPosition = currentPosition + direction;

	std::cout << std::endl;

	int nextTile = _currentLevel[nextPosition.x][nextPosition.y];
	int currentTile = _currentLevel[currentPosition.x][currentPosition.y];
	
	
	int nextTileType = EMPTY;
	int lastTileType = EMPTY;

	if (nextTile == WALL) return;

	Coordinate nextPositionBox = nextPosition + direction;
	int nextTileBox = _currentLevel[nextPositionBox.x][nextPositionBox.y];

	bool unMoveable = (nextTile == WALL) || (nextTile == BOX && nextTileBox == WALL) || (nextTile == BOX && nextTileBox == BOX);
	
	if (unMoveable)
	{
		std::cout << "Blocked!"; 
		return;
	}
	else
	{
		if (nextTile == GOAL)
		{
			nextTileType = PLAYER_ON_GOAL;
			lastTileType = EMPTY;
		}

		if (nextTile == BOX || nextTile == BOX_ON_GOAL)
		{
			if (nextTileBox == WALL) return;
				 
			int nextTileTypeBox = EMPTY;

			// Checks if we are about to push a box onto a goal, and sets tile accordingly
			nextTileBox == GOAL ? nextTileTypeBox = BOX_ON_GOAL : nextTileTypeBox = BOX;
			
			// Checks if the player is about to be on a goal, and sets it depending on goal type
			nextTile == BOX_ON_GOAL ? nextTileType = PLAYER_ON_GOAL : nextTileType = PLAYER;
			
			// sets the last tile accordingly
			currentTile == PLAYER_ON_GOAL ? lastTileType = GOAL : lastTileType = EMPTY;

			// updates the box render
			_currentLevel[nextPositionBox.x][nextPositionBox.y] = nextTileTypeBox;
		}

		if (nextTile == EMPTY)
		{
			nextTileType = PLAYER;
			currentTile == PLAYER_ON_GOAL ? lastTileType = GOAL : lastTileType = EMPTY;
		}
	}

	_currentLevel[nextPosition.x][nextPosition.y] = nextTileType;
	_currentLevel[lastPosition.x][lastPosition.y] = lastTileType;
	currentPosition = nextPosition;
}