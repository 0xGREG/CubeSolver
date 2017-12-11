#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.h"
using namespace std;

cube::cube(int _size){
    size = _size;
    testing = false;
    correct = false; // cube is not yet correct (not set/not in solvable state)
    solved = false;
    sides = 6; // currently only cubes are supported
    tilesOnSide = _size * _size; // there is (size^2) tiles on each side

    if (globalFlags::fDebug && !testing)
        cout << "--- Starting cube initialization ---" << endl;

    initializeCube();

    if (globalFlags::fDebug && !testing)
        showSuccessMessage("All tiles set to 0");
}

void cube::initializeCube()
// initialize the cube to 3x3x3 with all tiles set to 0
{
    tiles = new short*[sides];
    for (int i = 0; i < sides; i++)
    {
        tiles[i] = new short[tilesOnSide];
        for (int j = 0; j < tilesOnSide; j++)
        {
            tiles[i][j] = 0;
        }
    }
}

void cube::updateIsSolved()
// check if the cube is in solved state and update solved variable to required state
{
    for (int i = 0; i < sides; i++)
    {
        short color = tiles[i][0]; // get color (value) of the first tile on the side
        for (int j = 1; j < tilesOnSide; j++)
        {
            if (tiles[i][j] != color) 
            {
                solved = false; // if at least one tile on the side is different than the first one we know that cube is not solved
                return;
            }
        }
    }
    solved = true; // if all the sades are single-colored we know that cube is solved
}

bool cube::setTiles(string order)
{
    if (globalFlags::fDebug && !testing)
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
        if (globalFlags::fDebug && !testing)
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

    if (!testing)
        showSuccessMessage("All tiles set\n");
    return true;
}

bool cube::checkString(string order)
{
    if (order.length() != 59)
    {
        if (!testing)
            showErrorMessage("The order provided has wrong length");
        return false;
    }

    for (int i = 0; i < 5; i++)
    {
        if (!order[i*10+9] == ' ')
        {
            if (!testing)
                showErrorMessage("Blocks (sides) are not separated with space");
            return false;
        }
    }

    char characters[6];
    if (globalFlags::fDebug&& !testing)
        cout << "centers: " << endl;

    for (int i = 0; i < 6; i++)
    {
        characters[i] = order[i*10+4];
        if (globalFlags::fDebug && !testing)
            cout << characters[i] << " ";
        for (int j = 0; j < i; j++)
        {
            if (characters[i] == characters[j])
            {
                if (!testing)
                {
                    cout << "\n";
                    showErrorMessage("Centers are not all different!");
                }
                return false;
            }
        }
    }
    if (globalFlags::fDebug && !testing)
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
            if (!testing)
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
            if (!testing)
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

string cube::createColoredString(short character) // gets number as input and prints it as colored ascii (if input was 1 output will be "1")
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

string cube::toString()
{
    string output = "";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            output += (char)(tiles[i][j]+48);
        }
        if (i != 5)
            output += " ";
    }
    return output;
}

short** cube::cubeCopy()
{
    short** newCube = new short*[6]();
    for (int i = 0; i < 6; i++)
    {
        newCube[i] = sideCopy(i);
    }
    return newCube;
}

bool cube::solve()
{
    if (globalFlags::fDebug)
        cout << "\nStarting solving procedure\n\n";
    if (globalFlags::fLearning)
        solveLearning();
    return true;
}

bool cube::solveLearning()
{
    if (globalFlags::fDebug)
        cout << "Solving in learning mode\n\n";
    return true;
}

bool cube::execute(string functionToRun, string arguments)
{
    if (functionToRun == "setTiles")
        return setTiles(arguments);
    else if (functionToRun == "move")
        return move(arguments);
    else if (functionToRun == "runSequence")
        return runSequence(arguments);
    return false;
}

bool cube::runSequence(string sequence)
{
    if (sequence.length() == 0)
        return false;
    
    int position = 0;
    while (true)
    {
        int newPosition = sequence.find(' ', position);
        if (newPosition == -1)
        {
            return move(sequence.substr(position));
        }

        if (!move(sequence.substr(position, newPosition - position)))
        {
            return false;
        }
        position = newPosition + 1;
    }
    return true;
}