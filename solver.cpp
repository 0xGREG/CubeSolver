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
    mainCube.setTiles("000000000 111111111 222222222 333333333 444444444 555555555");
    mainCube.displayCube();

    mainCube.setTiles("002002002 111111111 223223223 533533533 444444444 550550550");
    mainCube.displayCube();
    mainCube.move("r");
    mainCube.displayCube();
    mainCube.move("r'");
    mainCube.displayCube();
    cout << "-------------------------------------\n\n";

    mainCube.setTiles("250501121 521314200 243424411 503331555 450240312 033052434");
    mainCube.displayCube();
    mainCube.move("r");
    mainCube.displayCube();
    mainCube.move("r'");
    mainCube.displayCube();

    return 0;
}