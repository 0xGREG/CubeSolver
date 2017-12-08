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
    
    if (!setTiles("000010000 000010000 0000 1000 1 1 1 1 100000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000")
        showSuccessMessage("Test 1 Passed");
    else
        showErrorMessage("Failed on 000010000 000010000 0000 1000 1 1 1 1 100000");

    if (!setTiles("000010000 000010000 000010000 000010000 0000100001000010000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000")
        showSuccessMessage("Test 2 Passed");
    else
        showErrorMessage("Failed on 000010000 000010000 000010000 000010000 0000100001000010000");
    
    if (!setTiles("000010000 000010000 000010000 000010000 000010000 000010000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000")
        showSuccessMessage("Test 3 Passed");
    else
        showErrorMessage("Failed on 000010000 000010000 000010000 000010000 000010000 000010000");
    
    if (!setTiles("000000000 000010000 000020000 000030000 000040000 000050000") && toString()=="000000000 000000000 000000000 000000000 000000000 000000000")
        showSuccessMessage("Test 4 Passed");
    else
        showErrorMessage("Failed on 000000000 000010000 000020000 000030000 000040000 000050000");
    
    if (setTiles("000000000 111111111 222222222 333333333 444444444 555555555") && toString()=="000000000 111111111 222222222 333333333 444444444 555555555")
        showSuccessMessage("Test 5 Passed");
    else
        showErrorMessage("Failed on 000000000 111111111 222222222 333333333 444444444 555555555");
    
    wasError = false;
    if (setTiles("002002002 111111111 223223223 533533533 444444444 550550550") && toString()=="002002002 111111111 223223223 533533533 444444444 550550550")
        showSuccessMessage("Test 6 Passed");
    else
    {
        showErrorMessage("Failed on 002002002 111111111 223223223 533533533 444444444 550550550");
        wasError = true;
    }

    if (!wasError)
    {
        move("r");

        if (toString()=="000000000 111111111 222222222 333333333 444444444 555555555")
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
    if (setTiles("250501121 521314200 243424411 503331555 450240312 033052434") && toString()=="250501121 521314200 243424411 503331555 450240312 033052434")
        showSuccessMessage("Test 8 Passed");
    else
    {
        showErrorMessage("Failed on 250501121 521314200 243424411 503331555 450240312 033052434");
        wasError = true;
    }

    if (!wasError)
    {
        move("r'");

        if (toString()=="253504121 140210532 245423415 403231355 450240312 030051431")
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
    if (setTiles("baefabacd fddabfeca cfbdcecfa cbdddbbeb ecadeedcc eafbfefaf") && toString()=="104501023 533015420 251324250 213331141 420344322 405154505")
        showSuccessMessage("Test 10 Passed");
    else
    {
        showErrorMessage("Failed on baefabacd fddabfeca cfbdcecfa cbdddbbeb ecadeedcc eafbfefaf");
        wasError = true;
    }

    if (!wasError)
    {
        move("u");

        if (toString()=="533501023 213015420 232525041 420331141 104344322 405154505")
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
    if (setTiles("010204524 541210032 210125231 201531445 354240333 135554403") && toString()=="010204524 541210032 210125231 201531445 354240333 135554403")
        showSuccessMessage("Test 12 Passed");
    else
    {
        showErrorMessage("Failed on 010204524 541210032 210125231 201531445 354240333 135554403");
        wasError = true;
    }

    if (!wasError)
    {
        move("u'");

        if (toString()=="354204524 010210032 051123212 541531445 201240333 135554403")
            showSuccessMessage("Test 13 Passed");
        else
            showErrorMessage("Failed on U' turn on 010204524 541210032 210125231 201531445 354240333 135554403");
    }
    else
    {
        showWarningMessage("Skipping test 13 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("999999999 888888888 777777777 666666666 555555555 444444444") && toString()=="000000000 111111111 222222222 333333333 444444444 555555555")
        showSuccessMessage("Test 14 Passed");
    else
    {
        showErrorMessage("Failed on 999999999 888888888 777777777 666666666 555555555 444444444");
        wasError = true;
    }

    if (!wasError)
    {
        move("l");

        if (toString()=="200200200 111111111 322322322 335335335 444444444 055055055")
            showSuccessMessage("Test 15 Passed");
        else
            showErrorMessage("Failed on L turn on 000000000 111111111 222222222 333333333 444444444 555555555");
    }
    else
    {
        showWarningMessage("Skipping test 15 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("350100050 533414503 522224111 414235132 305440011 234355422") && toString()=="350100050 533414503 522224111 414235132 305440011 234355422")
        showSuccessMessage("Test 16 Passed");
    else
    {
        showErrorMessage("Failed on 350100050 533414503 522224111 414235132 305440011 234355422");
        wasError = true;
    }

    if (!wasError)
    {
        move("l");

        if (toString()=="550200150 533414503 222524411 414233132 043140105 334155022")
            showSuccessMessage("Test 17 Passed");
        else
            showErrorMessage("Failed on L turn on 350100050 533414503 522224111 414235132 305440011 234355422");
    }
    else
    {
        showWarningMessage("Skipping test 17 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("200200200 111111111 322322322 335335335 444444444 055055055") && toString()=="200200200 111111111 322322322 335335335 444444444 055055055")
        showSuccessMessage("Test 18 Passed");
    else
    {
        showErrorMessage("Failed on 200200200 111111111 322322322 335335335 444444444 055055055");
        wasError = true;
    }

    if (!wasError)
    {
        move("l'");

        if (toString()=="000000000 111111111 222222222 333333333 444444444 555555555")
            showSuccessMessage("Test 19 Passed");
        else
            showErrorMessage("Failed on L turn on 200200200 111111111 322322322 335335335 444444444 055055055");
    }
    else
    {
        showWarningMessage("Skipping test 19 as initialization failed");
        wasError = false;
    }


    wasError= false;
    if (setTiles("521503315 225415451 421423400 340035514 203341332 120154200") && toString()=="521503315 225415451 421423400 340035514 203341332 120154200")
        showSuccessMessage("Test 20 Passed");
    else
    {
        showErrorMessage("Failed on 521503315 225415451 421423400 340035514 203341332 120154200");
        wasError = true;
    }

    if (!wasError)
    {
        move("l'");

        if (toString()=="121103215 225415451 521523300 344034514 312043233 420554000")
            showSuccessMessage("Test 21 Passed");
        else
            showErrorMessage("Failed on L turn on 521503315 225415451 421423400 340035514 203341332 120154200");
    }
    else
    {
        showWarningMessage("Skipping test 21 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("521503315 225415451 421423400 340035514 203341332 120154200") && toString()=="521503315 225415451 421423400 340035514 203341332 120154200")
        showSuccessMessage("Test 22 Passed");
    else
    {
        showErrorMessage("Failed on 521503315 225415451 421423400 340035514 203341332 120154200");
        wasError = true;
    }

    if (!wasError)
    {
        move("l");
        move("u");
        move("r");
        move("r'");
        move("u'");
        move("l'");

        if (toString()=="521503315 225415451 421423400 340035514 203341332 120154200")
            showSuccessMessage("Test 23 Passed");
        else
            showErrorMessage("Failed on LURR'U'L' sequence on 521503315 225415451 421423400 340035514 203341332 120154200");
    }
    else
    {
        showWarningMessage("Skipping test 23 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("000000111 111111333 222222222 333333444 444444000 555555555") && toString()=="000000111 111111333 222222222 333333444 444444000 555555555")
        showSuccessMessage("Test 24 Passed");
    else
    {
        showErrorMessage("Failed on 000000111 111111333 222222222 333333444 444444000 555555555");
        wasError = true;
    }

    if (!wasError)
    {
        move("d");

        if (toString()=="000000000 111111111 222222222 333333333 444444444 555555555")
            showSuccessMessage("Test 25 Passed");
        else
            showErrorMessage("Failed on D turn on 000000111 111111333 222222222 333333444 444444000 555555555");
    }
    else
    {
        showWarningMessage("Skipping test 25 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("300205331 552014020 504423111 344531532 335240012 122554414") && toString()=="300205331 552014020 504423111 344531532 335240012 122554414")
        showSuccessMessage("Test 26 Passed");
    else
    {
        showErrorMessage("Failed on 300205331 552014020 504423111 344531532 335240012 122554414");
        wasError = true;
    }

    if (!wasError)
    {
        move("d");

        if (toString()=="300205012 552014331 504423111 344531020 335240532 451152442")
            showSuccessMessage("Test 27 Passed");
        else
            showErrorMessage("Failed on D turn on 300205331 552014020 504423111 344531532 335240012 122554414");
    }
    else
    {
        showWarningMessage("Skipping test 27 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("511303222 000512314 452421355 103434230 551042543 401352410") && toString()=="511303222 000512314 452421355 103434230 551042543 401352410")
        showSuccessMessage("Test 28 Passed");
    else
    {
        showErrorMessage("Failed on 511303222 000512314 452421355 103434230 551042543 401352410");
        wasError = true;
    }

    if (!wasError)
    {
        move("l");
        move("u");
        move("r");
        move("d");
        move("d'");
        move("r'");
        move("u'");
        move("l'");

        if (toString()=="511303222 000512314 452421355 103434230 551042543 401352410")
            showSuccessMessage("Test 29 Passed");
        else
            showErrorMessage("Failed on LURDD'R'U'L' sequence on 511303222 000512314 452421355 103434230 551042543 401352410");
    }
    else
    {
        showWarningMessage("Skipping test 29 as initialization failed");
        wasError = false;
    }

    wasError= false;
    if (setTiles("211105305 220012031 225524350 411033324 334140245 441554035") && toString()=="211105305 220012031 225524350 411033324 334140245 441554035")
        showSuccessMessage("Test 30 Passed");
    else
    {
        showErrorMessage("Failed on 211105305 220012031 225524350 411033324 334140245 441554035");
        wasError = true;
    }

    if (!wasError)
    {
        move("d'");

        if (toString()=="211105031 220012324 225524350 411033245 334140305 145453450")
            showSuccessMessage("Test 31 Passed");
        else
            showErrorMessage("Failed on D' turn on 211105305 220012031 225524350 411033324 334140245 441554035");
    }
    else
    {
        showWarningMessage("Skipping test 31 as initialization failed");
        wasError = false;
    }

}