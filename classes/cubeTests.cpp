#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.h"
#include <string>
using namespace std;

string str_toupper(string str) {
    std::locale settings;
	std::string converted;
    for(int i = 0; i < str.size(); ++i)
		converted += (std::toupper(str[i], settings));
	return converted;
}

void cube::runTestCases(int &counter, int length, testCase* testCases)
{
    cout<<endl;
    bool wasError = false;
    string original = "";
    for (int i = 0; i < length; i++)
    {
        testCase currentCase = testCases[i];
        if (currentCase.functionToRun == "displayCube")
        {
            displayCube();
            cout << toString() << endl;
            continue;
        }
        if (!wasError)
        {
            bool result = execute(currentCase.functionToRun, currentCase.functionArgument);
            if (currentCase.functionToRun == "setTiles" && currentCase.cubeState == "")
                currentCase.cubeState = currentCase.functionArgument;
            if (currentCase.cubeState == "don't check")
                currentCase.cubeState = "";
            if (result == currentCase.functionResult && (currentCase.cubeState == "" || (currentCase.cubeState != "" && toString() == currentCase.cubeState)))
            {
                showSuccessMessage("Test " + to_string(++counter) + " Passed");
                original = toString();
            }
            else 
            {
                if (currentCase.description == "")
                    if (currentCase.functionToRun == "setTiles")
                        currentCase.description = "Setting cube to " + currentCase.functionArgument;
                    else if (currentCase.functionToRun == "move")
                    {
                        currentCase.description = "Executing " + str_toupper(currentCase.functionArgument) + " move ";
                        if (original != "")
                            currentCase.description += "on " + original;
                    }
                    else if (currentCase.functionToRun == "runSequence")
                    {
                        currentCase.description = "Executing sequence " + str_toupper(currentCase.functionArgument);
                        if (original != "")
                            currentCase.description += " on " + original;
                    }
                showErrorMessage("Test " + to_string(++counter) + " Failed: " + currentCase.description );
                wasError = true;
            }
        }
        else
        {
            showWarningMessage("Skipping test " + to_string(++counter) + " as initialization failed");
        }
    }
}

void cube::testClass()
{
    testing = true;
    cout << "\nStarting Testing set:\n";
    int counter = 0;

    // 1
    testCase* toBeTested = new testCase[1]();
    toBeTested[0].set(
        "setTiles",
        "000010000 000010000 0000 1000 1 1 1 1 100000",
        "000000000 000000000 000000000 000000000 000000000 000000000",
        false
    );
    runTestCases(counter, 1, toBeTested);
    delete[] toBeTested;

    // 2
    toBeTested = new testCase[1]();
    toBeTested[0].set(
        "setTiles",
        "000010000 000010000 000010000 000010000 0000100001000010000",
        "000000000 000000000 000000000 000000000 000000000 000000000",
        false
    );
    runTestCases(counter, 1, toBeTested);
    delete[] toBeTested;

    // 3
    toBeTested = new testCase[1]();
    toBeTested[0].set(
        "setTiles",
        "000010000 000010000 000010000 000010000 000010000 000010000",
        "000000000 000000000 000000000 000000000 000000000 000000000",
        false
    );
    runTestCases(counter, 1, toBeTested);
    delete[] toBeTested;

    // 4
    toBeTested = new testCase[1]();
    toBeTested[0].set(
        "setTiles",
        "000000000 000010000 000020000 000030000 000040000 000050000",
        "000000000 000000000 000000000 000000000 000000000 000000000",
        false
    );
    runTestCases(counter, 1, toBeTested);
    delete[] toBeTested;

    // 5
    toBeTested = new testCase[1]();
    toBeTested[0].set(
        "setTiles",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    runTestCases(counter, 1, toBeTested);
    delete[] toBeTested;

    //6,7
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "002002002 111111111 223223223 533533533 444444444 550550550"
    );
    toBeTested[1].set(
        "move",
        "r",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //8,9
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "250501121 521314200 243424411 503331555 450240312 033052434"
    );
    toBeTested[1].set(
        "move",
        "r'",
        "253504121 140210532 245423415 403231355 450240312 030051431"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //10,11
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "baefabacd fddabfeca cfbdcecfa cbdddbbeb ecadeedcc eafbfefaf",
        "104501023 533015420 251324250 213331141 420344322 405154505"
    );
    toBeTested[1].set(
        "move",
        "u",
        "533501023 213015420 232525041 420331141 104344322 405154505"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //12,13
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "010204524 541210032 210125231 201531445 354240333 135554403"
    );
    toBeTested[1].set(
        "move",
        "u'",
        "354204524 010210032 051123212 541531445 201240333 135554403"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //14,15
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "999999999 888888888 777777777 666666666 555555555 444444444",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    toBeTested[1].set(
        "move",
        "l",
        "200200200 111111111 322322322 335335335 444444444 055055055"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //16,17
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "350100050 533414503 522224111 414235132 305440011 234355422"
    );
    toBeTested[1].set(
        "move",
        "l",
        "550200150 533414503 222524411 414233132 043140105 334155022"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //18,19
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "200200200 111111111 322322322 335335335 444444444 055055055"
    );
    toBeTested[1].set(
        "move",
        "l'",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //20,21
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "521503315 225415451 421423400 340035514 203341332 120154200"
    );
    toBeTested[1].set(
        "move",
        "l'",
        "121103215 225415451 521523300 344034514 312043233 420554000"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //22-28
    toBeTested = new testCase[7]();
    toBeTested[0].set(
        "setTiles",
        "521503315 225415451 421423400 340035514 203341332 120154200"
    );
    toBeTested[1].set("move", "l");
    toBeTested[2].set("move", "u");
    toBeTested[3].set("move", "r");
    toBeTested[4].set("move", "r'");
    toBeTested[5].set("move", "u'");
    toBeTested[6].set("move", "l'",
        "521503315 225415451 421423400 340035514 203341332 120154200",
        true,
        "Executing sequence LURR'U'L' on 521503315 225415451 421423400 340035514 203341332 120154200"
    );
    runTestCases(counter, 7, toBeTested);
    delete[] toBeTested;

    //29,30
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "000000111 111111333 222222222 333333444 444444000 555555555"
    );
    toBeTested[1].set(
        "move",
        "d",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //31,32
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "300205331 552014020 504423111 344531532 335240012 122554414"
    );
    toBeTested[1].set(
        "move",
        "d",
        "300205012 552014331 504423111 344531020 335240532 451152442"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //33-41
    toBeTested = new testCase[9]();
    toBeTested[0].set(
        "setTiles",
        "511303222 000512314 452421355 103434230 551042543 401352410"
    );
    toBeTested[1].set("move", "l");
    toBeTested[2].set("move", "u");
    toBeTested[3].set("move", "r");
    toBeTested[4].set("move", "d");
    toBeTested[5].set("move", "d'");
    toBeTested[6].set("move", "r'");
    toBeTested[7].set("move", "u'");
    toBeTested[8].set("move", "l'",
        "511303222 000512314 452421355 103434230 551042543 401352410",
        true,
        "Executing sequence LURDD'R'U'L' on 511303222 000512314 452421355 103434230 551042543 401352410"
    );
    runTestCases(counter, 9, toBeTested);
    delete[] toBeTested;

    //42,43
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "211105305 220012031 225524350 411033324 334140245 441554035"
    );
    toBeTested[1].set(
        "move",
        "d'",
        "211105031 220012324 225524350 411033245 334140305 145453450"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //44,45
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "105205540 343110511 552123351 431430052 022243014 324053442"
    );
    toBeTested[1].set(
        "move",
        "f",
        "521400055 343510111 552123432 431430052 023242014 513053442"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //46,47
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "141100424 054514034 532223225 013533343 100245113 515054202"
    );
    toBeTested[1].set(
        "move",
        "f'",
        "104402114 554114534 532223050 013533343 105242112 053054202"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //48,49
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "315403330 452112150 513523103 150032421 405443044 225054212"
    );
    toBeTested[1].set(
        "move",
        "b",
        "315403330 452111152 220523103 401235120 305143544 225054440"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //50,51
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "002305530 121115200 553224543 534430413 331141200 441255422"
    );
    toBeTested[1].set(
        "move",
        "b'",
        "002305530 125115203 213224543 403331544 431241200 441255051"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //52-64
    toBeTested = new testCase[13]();
    toBeTested[0].set(
        "setTiles",
        "531402234 052010330 443121325 125531203 001245434 042551541"
    );
    toBeTested[1].set("move", "l");
    toBeTested[2].set("move", "u");
    toBeTested[3].set("move", "r");
    toBeTested[4].set("move", "d");
    toBeTested[5].set("move", "b");
    toBeTested[6].set("move", "f");
    toBeTested[7].set("move", "f'");
    toBeTested[8].set("move", "b'");
    toBeTested[9].set("move", "d'");
    toBeTested[10].set("move", "r'");
    toBeTested[11].set("move", "u'");
    toBeTested[12].set("move", "l'",
        "531402234 052010330 443121325 125531203 001245434 042551541",
        true,
        "Executing sequence LURDBFF'B'D'R'U'L' on 531402234 052010330 443121325 125531203 001245434 042551541"
    );
    runTestCases(counter, 13, toBeTested);
    delete[] toBeTested;

    //65,66
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "424201131 044513304 155222202 343434010 213043250 555051135"
    );
    toBeTested[1].set(
        "move",
        "2r",
        "420204133 403315440 155221205 143134410 213043250 555052132"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //67-73
    toBeTested = new testCase[7]();
    toBeTested[0].set(
        "setTiles",
        "023304431 513012233 052023544 444130521 551145050 243152201"
    );
    toBeTested[1].set("move", "2u", "444304431 551012233 445320250 023130521 513145050 243152201");
    toBeTested[2].set("move", "2r", "445301430 332210155 443322251 123430421 513145050 245150200");
    toBeTested[3].set("move", "2d", "445301421 332210050 443322251 123430430 513145155 002051542");
    toBeTested[4].set("move", "2l", "045001321 332210050 043022551 124433434 551541315 402351242");
    toBeTested[5].set("move", "2f", "123100540 532110150 043022204 124433434 550542313 155351242");
    toBeTested[6].set("move", "2b", 
        "123100540 533115155 242022204 434334421 050042213 155351340",
        true,
        "Executing sequence 2U 2R 2D 2L 2F 2B on 023304431 413012233 052023544 44413051 551145050 243152201"
    );
    runTestCases(counter, 7, toBeTested);
    delete[] toBeTested;

    //74,75
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "023304431 513012233 052023544 444130521 551145050 243152201"
    );
    toBeTested[1].set(
        "runSequence",
        "2u 2r 2d 2l 2f 2b",
        "123100540 533115155 242022204 434334421 050042213 155351340"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //76,77
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "310022144 423414201 102331135 452550555 025441313 230502430",
        "don't check"
    );
    toBeTested[1].set(
        "runSequence",
        "r 2f r' f' l' 2b u' f' u' f u' f u' 2f u' f u' f' u f u b u' 2b u b 2u b' u b f u r u' r' f' u' b u b' u b 2u b' 2u r u' l' u r' u' l u f u' b' u f' u' b",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;

    //78,79
    toBeTested = new testCase[2]();
    toBeTested[0].set(
        "setTiles",
        "221405031 514012225 243023013 204335424 011345555 143150340"
    );
    toBeTested[1].set(
        "runSequence",
        "r' 2b l' 2d r 2f 2d r u b' l r' u l' u b f d' 2l",
        "000000000 111111111 222222222 333333333 444444444 555555555"
    );
    runTestCases(counter, 2, toBeTested);
    delete[] toBeTested;
    setTiles("221405031 514012225 243023013 204335424 011345555 143150340");
    displayCube();
    cout << toString() << endl;
}