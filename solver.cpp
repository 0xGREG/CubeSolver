#include <iostream>
#include "classes/cube.h"
#include "globals/includes.h"
using namespace std;

bool globalFlags::fDebug = false;

int main(int argc, char *argv[]){
    globalFlags::fDebug = (argc > 1 && (argv[1][0] == '-' && argv[1][1] == 'v'));
    if (globalFlags::fDebug)
        cout << "CubeSolver 0.0.1\n" << endl;


    cube testCube = cube(3);
    testCube.testClass();

    cube newCube = cube(3);
    newCube.setTiles("000000000 111111111 222222222 333333333 444444444 555555555");
    do 
    {
        newCube.move("r");
        newCube.move("u");
        newCube.displayCube();
    } while (!newCube.isSolved());


    return 0;
}