#include "cube.h"
#include <iostream>
using namespace std;

cube::cube(int _size){
    size = _size;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            tiles[i][j] = 0;
        }
    }
    correct = false;
    solved = false;
}

void cube::updateIsSolved(){
    for (int i = 0; i < 6; i++)
    {
        bool sideSolved = true;
        short color = tiles[i][0];
        for (int j = 1; j < 9; j++)
        {
            if (tiles[i][j] != color)
            {
                sideSolved = false;
                break;
            }
        }
        if (!sideSolved)
        {
            solved = false;
            break;
        }
    }
    solved = true;
}

bool cube::setTiles(string order)
{
    short newNet[6][9];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            newNet[i][j] = -1;
        }
    }
}