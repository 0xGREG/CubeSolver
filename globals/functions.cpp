#include "functions.h"
#include <iostream>
using namespace std;

void showErrorMessage(string message)
{
    cout << "[\x1b[1;31mERROR\x1b[0m] " << message << endl;
}

void showSuccessMessage(string message)
{
    cout << "[\x1b[1;32mOK\x1b[0m] " << message << endl;
}

void showWarningMessage(string message)
{
    cout << "[\x1b[1;33mWARNING\x1b[0m] " << message << endl;
}