#include <vector>

#pragma once

// WALL = -1, EMPTY = 0, PLAYER = 1, BOX = 2, GOAL = 3

const std::vector<std::vector<int>> LEVEL_ONE = {
	{-1, -1, -1, -1, -1, -1},
	{-1,  3,  0,  0,  1, -1},
    {-1,  0,  2,  0,  0, -1},
    {-1,  0,  0,  0,  0, -1},
	{-1, -1, -1, -1, -1, -1}
};

const std::vector<std::vector<int>> LEVEL_TWO = {
    {-1, -1, -1, -1, -1, -1, -1},
    {-1,  0,  0,  3,  0,  0, -1},
    {-1,  0, -1,  2, -1,  0, -1},
    {-1,  1,  0,  2,  0,  0, -1},
    {-1,  0,  0,  3,  0,  0, -1},
    {-1, -1, -1, -1, -1, -1, -1}
};

const std::vector<std::vector<int>> LEVEL_THREE = {
    {-1, -1, -1, -1, -1, -1, -1,-1, -1},
    {-1,  0,  0,  0,  3,  0,  0, 0, -1},
    {-1,  0, -1, -1, -1, -1,  0, 0, -1},
    {-1,  0, -1,  0,  2,  0,  0, 0, -1},
    {-1,  1,  0,  2,  0, -1,  0, 0, -1},
    {-1,  0,  0,  0,  3, -1,  0, 0, -1},
    {-1, -1, -1, -1, -1, -1, -1,-1, -1}
};

const std::vector<std::vector<int>> LEVEL_FOUR = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  3,  0,  0,  0,  0,  1,  0, -1},
    {-1,  0,  0, -1,  2, -1,  0,  0, -1},
    {-1,  0,  0, -1,  0, -1,  2,  0, -1},
    {-1,  3,  0,  0,  0,  0,  0,  0, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1}
};

const std::vector<std::vector<int>> LEVEL_FIVE = {
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  3, -1,  0,  0,  0,  0, -1},
    {-1,  0, -1,  0,  0,  0,  0, -1},
    {-1,  0, -1,  0, -1,  2,  0, -1},
    {-1,  1,  2,  0, -1,  0,  0, -1},
    {-1,  0,  0,  0,  0, -1,  3, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1}
};

const std::vector<std::vector<int>> LEVEL_SIX = {
    {-1, -1, -1, -1, -1, -1, -1, -1, -1},
    {-1,  3,  0,  0,  0,  0,  0,  3, -1},
    {-1,  0, -1, -1,  2, -1, -1,  0, -1},
    {-1,  0, -1,  0,  1,  0, -1,  0, -1},
    {-1,  0,  2,  0, -1,  0,  2,  0, -1},
    {-1,  0,  0,  0,  0,  0,  0,  0, -1},
    {-1,  0,  0, -1, -1, -1,  0,  3, -1},
    {-1, -1, -1, -1, -1, -1, -1, -1, -1}
};
