#include <iostream>
#include "classes/cube.h"
#include "globals/includes.h"

#define VERSION "0.0.1a"

using namespace std;

bool globalFlags::fDebug = false;
bool globalFlags::fLearning = false;

void setFlags(int argc,char **argv);
void showHelp();

int main(int argc, char *argv[]){

    setFlags(argc, argv);

    if (globalFlags::fDebug)
        cout << "CubeSolver " << VERSION << endl << endl;


    cube testCube = cube(3); // test cube
    testCube.testClass();

    testCube.solve();

    return 0;
}

void setFlags(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) // check for every argument
    {
        if (argv[i][0] == '-') // only check for flags if arguments starts with '-'
        {
            for (int j = 1; j < string(argv[i]).length(); j++) // check every character of argument, can be multiple flags in one (-lv)
            {
                switch (argv[i][j])
                {
                    case 'v':
                        globalFlags::fDebug = true;
                        break;
                    case 'l':
                        globalFlags::fLearning = true;
                        break;
                    case 'h':
                        showHelp();
                        break;
                    default: // if found incorrect flag show help
                        showHelp();
                }
            }
        }
    }
}

void showHelp()
{
    cout << "CubeSolver " << VERSION << endl;
    cout << "---" << endl;
    cout << "Usage: cubeSolver [-hlv]" << endl << endl;
    cout << "-h - help, show this screen" << endl;
    cout << "-l - learning mode, find the shortest algorithm by analizng all the possible moves" << endl;
    cout << "-v - debug/verbose mode. show information about what's happening" << endl;
    exit(0);
}