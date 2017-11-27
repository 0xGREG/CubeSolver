#include <iostream>
#include "classes/cube.h"
#include "globals/includes.h"
using namespace std;

bool globalFlags::fDebug = false;

int main(int argc, char *argv[]){
    globalFlags::fDebug = (argc > 1 && (argv[1][0] == '-' && argv[1][1] == 'v'));
    if (globalFlags::fDebug)
        cout << "CubeSolver 0.0.1\n" << endl;
    cube mainCube = cube(3);
    if (globalFlags::fDebug)
        cout << "--- Created empty 3x3 cube ---\n" << endl;
    mainCube.setTiles("000010000 000010000 0000 1000 1 1 1 1 100000");
    mainCube.setTiles("000010000 000010000 000010000 000010000 0000100001000010000");
    mainCube.setTiles("000010000 000010000 000010000 000010000 000010000 000010000");
    mainCube.setTiles("000000000 000010000 000020000 000030000 000040000 000050000");

    return 0;
}