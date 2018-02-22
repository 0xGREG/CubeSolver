#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.h"
#include <string>
#include <stdio.h>
#include <limits>
using namespace std;

void clearStream()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct position
{
    short side;
    short tile;
};

position getNewSideRow(short side, short tile, char move);

void cube::interactiveMode()
{
    bool set = false;
    short side = 0;
    short tile = 0;

    bool valid = verifyTiles(tiles);


    while (!set)
    {
        system("clear");
        cout << "0-5 - set tile" << endl;
        cout << "WASD/arrows - change active tile" << endl;
        cout << "I - Finish setting and verify configuration" << endl;
        string validString = (valid) ? "True " : "False";
        cout << "Is Configuration Valid: " << validString << endl
             << endl;

        cout << endl;
        char temp = tiles[side][tile];
        tiles[side][tile] = -1;
        displayCube();
        tiles[side][tile] = temp;
        cout << "                 \r"; // to remove user input from screen
        char c = cin.get();
        if (c == EOF)
        {
            return;
        }

        // Support arrow keys
        short arrow = 0;
        if (c == 27)
        {
            arrow = 1;
            c = cin.get();
        }
        if (c == 91 && arrow == 1)
        {
            arrow = 2;
            c = cin.get();
        }
        if (arrow == 2)
        {
            if (c == 'A')
                c = 'W';
            else if (c == 'B')
                c = 'S';
            else if (c == 'D')
                c = 'A';
            else if (c == 'C')
                c = 'D';
        }

        if (c >= 97)
            c -= 32; //change character to uppercase

        if ((c == 'I') && verifyTiles(tiles))
        {
            set = true;
        }

        if (c == 'W' || c == 'A' || c == 'S' || c == 'D')
        {
            position output = getNewSideRow(side, tile, c);
            side = output.side;
            tile = output.tile;
        }

        if (c >= '0' && c <= '5' )
        {
            valid = updateTile(side, tile, c - '0');
        }
    }
}

// return new side and row as an array ([0] - side, [1] - tile)
position getNewSideRow(short side, short tile, char move)
{
    if (move == 'W')
    {
        if (tile >= 3)
        {
            tile -= 3;
        }
        else
        {
            tile += 6;
            switch (side)
            {
            case 0:
            case 1:
            case 3:
            case 4:
                side = 2;
                break;
            case 2:
                side = 5;
                break;
            case 5:
                side = 0;
                break;
            }
        }
    }
    else if (move == 'S')
    {
        if (tile < 6)
        {
            tile += 3;
        }
        else
        {
            tile -= 6;
            switch (side)
            {
            case 0:
            case 1:
            case 3:
            case 4:
                side = 5;
                break;
            case 2:
                side = 0;
                break;
            case 5:
                side = 2;
                break;
            }
        }
    }
    else if (move == 'D')
    {
        if (tile % 3 != 2)
        {
            tile += 1;
        }
        else
        {
            tile -= 2;
            switch (side)
            {
            case 2:
            case 0:
            case 5:
                side = 1;
                break;
            case 1:
                side = 3;
                break;
            case 3:
                side = 4;
                break;
            case 4:
                side = 0;
                break;
            }
        }
    }
    else if (move == 'A')
    {
        if (tile % 3 != 0)
        {
            tile -= 1;
        }
        else
        {
            tile += 2;
            switch (side)
            {
            case 2:
            case 0:
            case 5:
                side = 4;
                break;
            case 4:
                side = 3;
                break;
            case 3:
                side = 1;
                break;
            case 1:
                side = 0;
                break;
            }
        }
    }

    position pos;
    pos.tile = tile;
    pos.side = side;
    return pos;
}