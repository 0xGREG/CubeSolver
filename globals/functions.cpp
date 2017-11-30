#include "includes.h"
#include <iostream>
using namespace std;

void showErrorMessage(string message)
{
    cout << "[\x1b[1;31mError\x1b[0m] " << message << endl;
}

void showSuccessMessage(string message)
{
    cout << "[\x1b[1;32mOK\x1b[0m] " << message << endl;
}