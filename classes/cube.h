#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cctype>
#include <clocale>
using namespace std;

class cube;

string str_toupper(string str);

struct testCase
{
    string functionToRun;
    string functionArgument;
    bool functionResult;
    string cubeState;
    string description;
    void set(string _functionToRun, string _functionArgument, string _cubeState = "", bool _functionResult = true, string _description = "")
    {
        functionArgument = _functionArgument;
        functionResult = _functionResult;
        cubeState = _cubeState;
        description = _description;
        functionToRun = _functionToRun;
    }
    testCase(){
        functionToRun = "";
        functionArgument = "";
        functionResult = true;
        cubeState = "";
        description = "";
    };
};

class cube
{
    private:
        int size;
        short** tiles;
        short* right;
        short* left;
        short* front;
        short* back;
        short* top;
        short* bottom;
        bool testing; // it's set to true if this is an test set instace
        bool correct; // set this flag to true after setting cube and validating all sides
        bool solved; // flag set to true by updateIsSolved() if cube is in solved state
        int sides;
        int tilesOnSide;

        void updateIsSolved();
        string createColoredString(short character);
        short* sideCopy(int side);
        void moveTile(short* source, int source_tile, int destination_side, int destination_tile);
        void moveTile(int source_side, int source_tile, int destination_side, int destination_tile);
        short** cubeCopy();
        void initializeCube();
        bool execute(string functionToRun, string argumets);
        void runTestCases(int& counter, int length, testCase* testCases);
        bool runSequence(string sequence);
        
        void move_r();
        void move_r_prime();
        void move_2r();
        void move_u();
        void move_u_prime();
        void move_2u();
        void move_l();
        void move_l_prime();
        void move_2l();
        void move_d();
        void move_d_prime();
        void move_2d();
        void move_f();
        void move_f_prime();
        void move_2f();
        void move_b();
        void move_b_prime();
        void move_2b();

        int* getInteractiveCoordinates(short side, short column, short row);

        int shortestAlgorithmLength;
        string shortestAlgorithm;

    public:
        cube(int _size);
        void testClass(); // for debugging purposes only! will run test cases and mess up with an object
        bool setTiles(string order);
        bool verifyTiles(short**);
        bool checkString(string order);
        void displayCube();
        bool move(string side);
        string toString();

        bool solve();
        bool solveLearning();

        bool isSolved() {updateIsSolved(); return solved;}

        void interactiveMode();
};

#endif