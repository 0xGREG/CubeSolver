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
        showSuccessMessage("All tiles set to 0");
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
            showErrorMessage("Failed to set the cube tiles\n");
        return false;
    }

    char map[6] = {0,0,0,0,0,0};

    for (int i = 4; i < order.length(); i += 10)
    {
        map[i/10] = order[i]; 
    }

    for (int i = 0; i < order.length(); i%10==8?i+=2:i++)
    {
        int character = -1;
        for (int j = 0; j < 6; j++)
        {
            if (order[i] == map[j])
            {
                character = j;
                break;
            }
        }
        newNet[i/10][i%10] = character;
    }

    if (verifyTiles(newNet))
    {
        tiles = newNet;
    }

    showSuccessMessage("All tiles set\n");
    return true;
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

    char characters[6];
    if (globalFlags::fDebug)
        cout << "centers: " << endl;

    for (int i = 0; i < 6; i++)
    {
        characters[i] = order[i*10+4];
        if (globalFlags::fDebug)
            cout << characters[i] << " ";
        for (int j = 0; j < i; j++)
        {
            if (characters[i] == characters[j])
            {
                cout << "\n";
                showErrorMessage("Centers are not all different!");
                return false;
            }
        }
    }
    if (globalFlags::fDebug)
        cout << endl;

    char c = '\0';

    int counter[6] = {0,0,0,0,0,0};

    for (int i = 0; i < order.length(); i%10==8||i%10==3?i+=2:i++)
    {
        c = order[i];
        int match = -1;
        for (int j = 0; j < 6; j++)
        {
            if (c == characters[j])
            {
                match = j;
            }
        }
        if (match == -1)
        {
            showErrorMessage("The order provided contains more than 9 colors");
            return false;
        }
        else
        {
            counter[match]++;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        if (counter[i] != 8)
        {
            showErrorMessage("The number of tiles in each color doesn't match");
            return false;
        }
    }

    return true;
}

bool cube::verifyTiles(short**)
{
    return true;
}

string cube::createColoredString(short character)
{
    string output = "";//"\x1b[";
    switch(character)
    {
        case 0:
            output += "\x1b[1;37m";
            break;
        case 1:
            output += "\x1b[1;35m";
            break;
        case 2:
            output += "\x1b[1;32m";
            break;
        case 3:
            output += "\x1b[1;33m";
            break;
        case 4:
            output += "\x1b[1;31m";
            break;
        case 5:
            output += "\x1b[1;34m";
            break;
    }
    output += char(character+48);
    output += "\x1b[0m";
    return output;
}

void cube::displayCube()
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "         ";
        for (int j = i*3; j < i*3+3; j++)
        {
            cout << createColoredString(tiles[2][j])<<" ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = i*3; j < i*3+3; j++)
        {
            cout << createColoredString(tiles[4][j])<<" ";
        }
        cout << "  ";
        for (int j = i*3; j < i*3+3; j++)
        {
            cout << createColoredString(tiles[0][j])<<" ";
        }
        cout << "  ";
        for (int j = i*3; j < i*3+3; j++)
        {
            cout << createColoredString(tiles[1][j])<<" ";
        }
        cout << "  ";
        for (int j = i*3; j < i*3+3; j++)
        {
            cout << createColoredString(tiles[3][j])<<" ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "         ";
        for (int j = i*3; j < i*3+3; j++)
        {
            cout << createColoredString(tiles[5][j])<<" ";
        }
        cout << endl;
    }
    cout << endl;
}

short* cube::sideCopy(int side)
{
    short* newSide = new short[9]();
    for (int i = 0; i < 9; i++)
    {
        newSide[i] = tiles[side][i];
    }
    return newSide;
}

void cube::moveTile(short* source, int source_tile, int destination_side, int destination_tile)
{
    tiles[destination_side][destination_tile] = source[source_tile];
}
void cube::moveTile(int source_side, int source_tile, int destination_side, int destination_tile)
{
    tiles[destination_side][destination_tile] = tiles[source_side][source_tile];
}

void cube::move_r()
{
    short* old;
    short* old2;
    old = sideCopy(0);
    moveTile(5,2,0,2);
    moveTile(5,5,0,5);
    moveTile(5,8,0,8);
    old2 = sideCopy(2);
    moveTile(old,2,2,2);
    moveTile(old,5,2,5);
    moveTile(old,8,2,8);
    old = old2;
    old2 = sideCopy(3);
    moveTile(old,2,3,6);
    moveTile(old,5,3,3);
    moveTile(old,8,3,0);
    old = old2;
    old2 = sideCopy(5);
    moveTile(old,0,5,8);
    moveTile(old,3,5,5);
    moveTile(old,6,5,2);
    old = sideCopy(1);
    moveTile(old,0,1,2);
    moveTile(old,1,1,5);
    moveTile(old,2,1,8);
    moveTile(old,3,1,1);
    moveTile(old,5,1,7);
    moveTile(old,6,1,0);
    moveTile(old,7,1,3);
    moveTile(old,8,1,6);
}

void cube::move_r_prime()
{
    short* old;
    short* old2;
    old = sideCopy(5);
    moveTile(0,2,5,2);
    moveTile(0,5,5,5);
    moveTile(0,8,5,8);
    old2 = sideCopy(3);
    moveTile(old,2,3,6);
    moveTile(old,5,3,3);
    moveTile(old,8,3,0);
    old = old2;
    old2 = sideCopy(2);
    moveTile(old,0,2,8);
    moveTile(old,3,2,5);
    moveTile(old,6,2,2);
    old = old2;
    old2 = sideCopy(0);
    moveTile(old,2,0,2);
    moveTile(old,5,0,5);
    moveTile(old,8,0,8);
    old = sideCopy(1);
    moveTile(old,0,1,6);
    moveTile(old,1,1,3);
    moveTile(old,2,1,0);
    moveTile(old,3,1,7);
    moveTile(old,5,1,1);
    moveTile(old,6,1,0);
    moveTile(old,7,1,5);
    moveTile(old,8,1,2);
}

void cube::move(string side)
{
    if (side == "r")
        move_r();
    else if (side == "r'")
        move_r_prime(); 
}