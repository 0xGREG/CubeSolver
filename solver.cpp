#include <iostream>
#include "classes/cube.h"
#include "globals/includes.h"

#define VERSION "0.0.1a"

using namespace std;

bool globalFlags::fDebug = false;
bool globalFlags::fLearning = false;
bool globalFlags::fTest = false;
bool globalFlags::fInteractive = false;

void setFlags(int argc,char **argv);
void showHelp();

int main(int argc, char *argv[]){

    setFlags(argc, argv);

    if (globalFlags::fDebug)
        cout << "CubeSolver " << VERSION << endl << endl;

    if (globalFlags::fTest)
    {
        cube testCube = cube(3); // test cube
        testCube.testClass();
    }

    if (globalFlags::fInteractive)
    {
        cube interactiveCube = cube(3);
        interactiveCube.setTiles("000000000 111111111 222222222 333333333 444444444 555555555");
        interactiveCube.interactiveMode(); 
    }

    return 0;
}

void setFlags(int argc, char** argv)
{
    for (int i = 1; i < argc; i++) // check for every argument
    {
        if (argv[i][0] == '-') // only check for flags if arguments starts with '-'
        {
            if (string(argv[i]).length() > 2 && argv[i][1] == '-')
            {
                string command = string(argv[i]).substr(2);
                if (command == "test")
                {
                    globalFlags::fTest = true;
                    continue;
                }
                else
                {
                    showHelp(); // if the argument is incorrect show help and exit
                }
            }
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
                    case 'i':
                        globalFlags::fInteractive = true; 
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
    cout << "Usage: cubeSolver [-hlvig]" << endl << endl;
    cout << "-h - help, show this screen" << endl;
    cout << "-l - learning mode, find the shortest algorithm by analizng all the possible moves" << endl;
    cout << "-v - debug/verbose mode. show information about what's happening" << endl;
    cout << "-i - intercative mode" << endl;
    cout << "-g - GUI version" << endl;
    cout << endl << "Extended arguments:" << endl;
    cout << "--test - runs test cases" << endl;
    exit(0);
}