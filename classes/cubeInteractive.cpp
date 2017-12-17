#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.h"
#include <string>
#include <stdio.h>
#include <limits>
using namespace std;

void cube::interactiveMode()
{
    bool set = false;
    short side = 0;
    short row = 0;
    short column = 0;
    while (!set)
    {
        cout << endl;
        displayCube();
        cout << "                 \r"; // to remove user input from screen
        char c = cin.get();
        if (c == '\n')  
            cout << "\033[1A";
        if (c == EOF)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "\033[15A\r";
            continue;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\033[15A\r";
    }
}

int* getInteractiveCoordinates(short side, short column, short row)
{
    int* coordinates = new int[2]();
    return coordinates;
}