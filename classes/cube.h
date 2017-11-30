#ifndef CUBE_H
#define CUBE_H

#include <iostream>
using namespace std;

class cube
{
    private:
        int size;
        short** tiles;
        short* right;
        short* left;
        short* front;
        short* back;
        short* top;
        short* bottom;
        bool correct; // set this flag to true after setting cube and validating all sides
        bool solved; // flag set to true by updateIsSolved() if cube is in solved state

        void updateIsSolved();
        string createColoredString(short character);
        short* sideCopy(int side);
        void moveTile(short* source, int source_tile, int destination_side, int destination_tile);
        void moveTile(int source_side, int source_tile, int destination_side, int destination_tile);
        
        void move_r();
        void move_r_prime();

    public:
        cube(int _size);
        bool setTiles(string order);
        bool verifyTiles(short**);
        bool checkString(string order);
        void displayCube();
        void move(string side);
};

#endif