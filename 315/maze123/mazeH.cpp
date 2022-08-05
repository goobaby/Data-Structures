/* C/C++ program to solve Rat in
   a Maze problem using backtracking */
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "mazeH.h"

   // Maze size 

Maze::Maze(std::string inputFileName)
{
    int row = 0;
    int column = 0;
    //std::string maze;
    std::ifstream mz(inputFileName);
    if (!mz) {
        throw "Error, file couldn't be opened";
        //return 1;
    }

    
    while (!mz.eof())
    {
        
        std::string readBuffer;
        mz >> readBuffer;
        //mz >> maze[row][column];
        //std::cout << "DEBUG reading line " << readBuffer << "\n";
        //row++;
        //column++;
        //std::cout << "DEBUG CRASh \n";
        if (readBuffer.at(0)!= '1' && readBuffer.at(0) != '0')
        {
            
            row--;
            break;
        }

        //std::string a = readBuffer;
        for (int i = 0; i < readBuffer.length(); i++)
        {
            char x = readBuffer.at(i);
            //std::cout << x << " DEBUG buffer" << "\n";
            if (i == 0)
            {
                if (x == '0')
                {
                    startX = row;
                    startY = i;
                }
            }
            maze[row][i] = x;
            sol[row][i] = x;
            //std::cout << maze[row][i] << " DEBUG maze \n";
        }
        row++;
        column = readBuffer.length();
        //std::cout << "DEBUG: column " << column << "\n";
        //std::cout << "DEBUG reading row " << row << "\n";
    }
    mazeRowSize = row;
    mazeColSize = column;
    //dumpMaze();
}

/* A utility function to print
solution matrix sol[N][N] */
void Maze::printSolution()
{
    for (int i = 0; i < mazeRowSize; i++) {
        for (int j = 0; j < mazeColSize; j++)
            printf("%c", sol[i][j]);
        printf("\n");
    }
}

/* A utility function to check if x,
y is valid*/
bool Maze::isSafe( int x, int y)
{
    
    //x >= 0 && x < mazeRowSize && y >= 0 && y < mazeColSize && 
    if (maze[x][y] == '0')
    {
        //std::cout << "DEBUG: isSafe " << x << y << "\n";
        return true;
    }
        
    //std::cout << "DEBUG: isNotSafe " << x << y << "\n";

    return false;
}

/* This function solves the Maze problem
using Backtracking. It mainly uses
solveMazeUtil() to solve the problem.
*/
bool Maze::solveMaze()
{
    
    if (solveMazeUntil(startX, startY)== false) 
    {
        printf("Solution doesn't exist");
        return false;
    }

    printSolution();
    return true;
}

/* A recursive utility function
to solve Maze problem */
bool Maze::solveMazeUntil(int x, int y)
{
    int saveLastX = xLastPos;
    int saveLastY = yLastPos;

    if (x >= mazeRowSize || x < 0 || y>= mazeColSize || y < 0)
    {
        return false;
    }

    if (foundSolution)
    {
        return true;
    }

    curLevel++;
    sol[x][y] = ' ';

    //std::cout << "----------------------------------------------" << x << ", " << y << "\n";
    // if (x, y is goal) return true 
    if (y == mazeColSize - 1 && maze[x][y] == '0')
    {
        //std::cout << "DEBUG: found solution " << curLevel << " \n";
        //positions.push_back(std::make_tuple(x, y));
        sol[x][y] = ' ';
        foundSolution = true;
        return true;
    }

    // Check if maze[x][y] is valid 

        // mark x, y as part of solution path 


        /*
        positions.push_back(std::make_tuple(x, y));
        
        if (positions.size() != 1)
        {
            auto lastPosition = positions.at(positions.size() - 1);
            xLast = std::get<0>(lastPosition);
            yLast = std::get<1>(lastPosition);
        }
        */
        // check down
        if (xLastPos != x+1 || yLastPos != y)
        {
            if (isSafe(x+1, y))
            {
                xLastPos = x;
                yLastPos = y;
                //std::cout << "check down \n";
                solveMazeUntil(x + 1, y);
                if (foundSolution)
                {
                    return true;
                }
                xLastPos = saveLastX;
                yLastPos = saveLastY;
            }
        }


        // check right
        if (xLastPos != x  || yLastPos != y+1)
        {
            if (isSafe(x, y+1))
            {
                xLastPos = x;
                yLastPos = y;
                //std::cout << "check right \n";
                solveMazeUntil(x, y + 1);
                if (foundSolution)
                {
                    return true;
                }
                xLastPos = saveLastX;
                yLastPos = saveLastY;
            }
        }

        //check up
        if (xLastPos != x - 1 || yLastPos != y)
        {
            if (isSafe(x - 1, y))
            {
                xLastPos = x;
                yLastPos = y;
                //std::cout << "check up \n";
                solveMazeUntil(x - 1, y);
                if (foundSolution)
                {
                    return true;
                }
                xLastPos = saveLastX;
                yLastPos = saveLastY;
            }
        }

        //check left
        if (xLastPos != x || yLastPos != y - 1)
        {
            if (isSafe(x, y-1))
            {
                xLastPos = x;
                yLastPos = y;
                //std::cout << "check left \n";
                solveMazeUntil(x, y - 1);
                if (foundSolution)
                {
                    return true;
                }
                xLastPos = saveLastX;
                yLastPos = saveLastY;
            }
            
        }

        if (curLevel == 1)
        {
            return false;
        }
        else
        {
            //std::cout << "DEBUG: Backtracking to " << xLastPos << ", " << yLastPos << " from " << x << ", " << y << "\n";
            curLevel--;
            sol[x][y] = '0';
            maze[x][y] = '1';
            //solveMazeUtil(xLastPos, yLastPos);
            return true;
        }
        /* If none of the above movements
           work then BACKTRACK: unmark
           x, y as part of solution path */
    /*
    std::cout << "DEBUG: x & y before pop " << x << " " << y << "\n";

    if (positions.size() != 0)
    {
        positions.pop_back();
        auto val = positions.back();
        x = std::get<0>(val);
        y = std::get<1>(val);
        std::cout << "DEBUG: x & y after pop" << x << " " << y << "\n";
        solveMazeUtil(x, y);
    }
    else
    {
        std::cout << "no solution found \n";
        exit(0);
    }
    */
     //CHANGE
    //std::cout << "DEBUG: Backtrack \n";
    return false;
}

void Maze::dumpMaze()
{
    if (mazeRowSize == 0)
    {
        std::cout << "maze is empty";

    }
    //std::cout << "dumping maze \n";
    for (int i = 0; i < mazeRowSize; i++)
    {
        for (int j = 0; j < mazeColSize; j++)
        {
            std::cout << maze[i][j];
        }
        std::cout << "\n";
    }
}
