#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.cpp"
using namespace std;

cube::cube(int _size){
    size = _size;
    if (globalFlags::fDebug)
        cout << "--- Starting cube initialization ---" << endl;
    tiles = new short*[6];
    for (int i = 0; i < 6; i++)
    {
        tiles[i] = new short[9];
        for (int j = 0; j < 9; j++)
        {
            tiles[i][j] = 0;
        }
    }
    if (globalFlags::fDebug)
        cout << "[\x1b[1;32mOK\x1b[0m] All tiles set to 0" << endl;
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
    if (globalFlags::fDebug)
        cout << "\n--- Starting tiles setting procedure ---\n" << endl;
    short** newNet;
    newNet = new short*[6];
    for (int i = 0; i < 6; i++)
    {
        newNet[i] = new short[9];
        for (int j = 0; j < 9; j++)
        {
            newNet[i][j] = -1;
        }
    }
    if (!checkString(order))
    {
        if (globalFlags::fDebug)
            cout << "Failed to set the cube tiles\n" << endl;
        return false;
    }

    char characters[6];
    if (globalFlags::fDebug)
        cout << "centers: " << endl;
    for (int i = 0; i < 6; i++)
    {
        characters[i] = 0;
        characters[i] = order[i*10+4];
        if (globalFlags::fDebug)
            cout << characters[i] << " ";
    }
    if (globalFlags::fDebug)
        cout << endl;

    
    
    if (verifyTiles(newNet))
    {
        tiles = newNet;
        return true;
    }

    return false;
}

bool cube::checkString(string order)
{
    if (order.length() != 59)
    {
        showErrorMessage("The order provided has wrong length");
        return false;
    }

    for (int i = 0; i < 5; i++)
    {
        if (!order[i*10+9] == ' ')
        {
            showErrorMessage("Blocks (sides) are not separated with space");
            return false;
        }
    }

    char c = '\0';

    for (int i = 0; i < order.length(); i%10==8?i+=2:i++)
    {
        c = order[i];
    }

    return true;
}

bool cube::verifyTiles(short**)
{
    return true;
}