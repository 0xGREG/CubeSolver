#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.h"
using namespace std;

void cube::testClass()
{
    testing = true;
    cout << "\nStarting Testing set:\n\n";

    int wasError = false;
    
    if (!setTiles("000010000 000010000 0000 1000 1 1 1 1 100000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000 ")
        showSuccessMessage("Test 1 Passed");
    else
        showErrorMessage("Failed on 000010000 000010000 0000 1000 1 1 1 1 100000");

    if (!setTiles("000010000 000010000 000010000 000010000 0000100001000010000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000 ")
        showSuccessMessage("Test 2 Passed");
    else
        showErrorMessage("Failed on 000010000 000010000 000010000 000010000 0000100001000010000");
    
    if (!setTiles("000010000 000010000 000010000 000010000 000010000 000010000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000 ")
        showSuccessMessage("Test 3 Passed");
    else
        showErrorMessage("Failed on 000010000 000010000 000010000 000010000 000010000 000010000");
    
    if (!setTiles("000000000 000010000 000020000 000030000 000040000 000050000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000 ")
        showSuccessMessage("Test 4 Passed");
    else
        showErrorMessage("Failed on 000000000 000010000 000020000 000030000 000040000 000050000");
    
    if (setTiles("000000000 111111111 222222222 333333333 444444444 555555555") && toString()=="000000000 111111111 222222222 333333333 444444444 555555555 ")
        showSuccessMessage("Test 5 Passed");
    else
        showErrorMessage("Failed on 000000000 111111111 222222222 333333333 444444444 555555555");
    
    wasError = false;
    if (setTiles("002002002 111111111 223223223 533533533 444444444 550550550") && toString()=="002002002 111111111 223223223 533533533 444444444 550550550 ")
        showSuccessMessage("Test 6 Passed");
    else
    {
        showErrorMessage("Failed on 002002002 111111111 223223223 533533533 444444444 550550550");
        wasError = true;
    }

    if (!wasError)
    {
        move("r");

        if (toString()=="000000000 111111111 222222222 333333333 444444444 555555555 ")
            showSuccessMessage("Test 7 Passed");
        else
            showErrorMessage("Failed on R turn on 002002002 111111111 223223223 533533533 444444444 550550550");
    }
    else
    {
        showWarningMessage("Skipping test 7 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("250501121 521314200 243424411 503331555 450240312 033052434") && toString()=="250501121 521314200 243424411 503331555 450240312 033052434 ")
        showSuccessMessage("Test 8 Passed");
    else
    {
        showErrorMessage("Failed on 250501121 521314200 243424411 503331555 450240312 033052434");
        wasError = true;
    }

    if (!wasError)
    {
        move("r'");

        if (toString()=="253504121 140210532 245423415 403231355 450240312 030051431 ")
            showSuccessMessage("Test 9 Passed");
        else
            showErrorMessage("Failed on R' turn on 250501121 521314200 243424411 503331555 450240312 033052434");
    }
    else
    {
        showWarningMessage("Skipping test 9 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("baefabacd fddabfeca cfbdcecfa cbdddbbeb ecadeedcc eafbfefaf") && toString()=="104501023 533015420 251324250 213331141 420344322 405154505 ")
        showSuccessMessage("Test 10 Passed");
    else
    {
        showErrorMessage("Failed on baefabacd fddabfeca cfbdcecfa cbdddbbeb ecadeedcc eafbfefaf");
        wasError = true;
    }

    if (!wasError)
    {
        move("u");

        if (toString()=="533501023 213015420 232525041 420331141 104344322 405154505 ")
            showSuccessMessage("Test 11 Passed");
        else
            showErrorMessage("Failed on U turn on 104501023 533015420 251324250 213331141 420344322 405154505");
    }
    else
    {
        showWarningMessage("Skipping test 11 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("010204524 541210032 210125231 201531445 354240333 135554403") && toString()=="010204524 541210032 210125231 201531445 354240333 135554403 ")
        showSuccessMessage("Test 12 Passed");
    else
    {
        showErrorMessage("Failed on 010204524 541210032 210125231 201531445 354240333 135554403");
        wasError = true;
    }

    if (!wasError)
    {
        move("u'");

        if (toString()=="354204524 010210032 051123212 541531445 201240333 135554403 ")
            showSuccessMessage("Test 13 Passed");
        else
            showErrorMessage("Failed on U' turn on 010204524 541210032 210125231 201531445 354240333 135554403");
    }
    else
    {
        showWarningMessage("Skipping test 13 as initialization failed");
        wasError = false;
    }
}