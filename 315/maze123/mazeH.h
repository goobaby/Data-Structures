#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <stack>
constexpr int MAX_MAZE_ROW_MAX = 25;
constexpr int MAX_MAZE_COLUMN_MAX = 25;

class Maze {

public:
	char maze[MAX_MAZE_ROW_MAX][MAX_MAZE_COLUMN_MAX] = {0};
	int mazeRowSize = 0;
	int	mazeColSize = 0;
	Maze(std::string inputFileName);
	bool solveMaze();
	char sol[MAX_MAZE_ROW_MAX][MAX_MAZE_COLUMN_MAX] = {0};
	int curLevel = 0;
	int xLastPos = -1;
	int yLastPos = -1;
	bool foundSolution = false;
	int startX = -1;
	int startY = -1;


	std::vector<std::tuple<int, int>> positions;
	std::tuple<int, int> lastPosition;

private:
	bool solveMazeUntil(int x, int y);

	void dumpMaze();

	void printSolution();

	bool isSafe(int x, int y);

	
};