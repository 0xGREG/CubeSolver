#ifndef CUBE_H
#define CUBE_H

#include <iostream>
using namespace std;

class cube
{
    private:
        int size;
        short tiles[6][9];
        short* right;
        short* left;
        short* front;
        short* back;
        short* top;
        short* bottom;
        bool correct; // set this flag to true after setting cube and validating all sides
        bool solved; // flag set to true by updateIsSolved() if cube is in solved state

        void updateIsSolved();

    public:
        cube(int _size);
        bool setTiles(string order);
};

#endif