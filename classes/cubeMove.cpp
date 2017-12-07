#include "cube.h"
#include <iostream>
#include "../globals/includes.h"
#include "../globals/functions.h"
using namespace std;

void cube::move(string side)
{
    if (side == "r")
        move_r();
    else if (side == "r'")
        move_r_prime(); 
    else if (side == "u")
        move_u();
    else if (side == "u'")
        move_u_prime();
    else if (side == "l")
        move_l();
    else if (side == "l'")
        move_l_prime();
}

void cube::move_r()
{
    short* old;
    short* old2;
    old = sideCopy(0);
    moveTile(5,2,0,2);
    moveTile(5,5,0,5);
    moveTile(5,8,0,8);
    old2 = sideCopy(2);
    moveTile(old,2,2,2);
    moveTile(old,5,2,5);
    moveTile(old,8,2,8);
    old = old2;
    old2 = sideCopy(3);
    moveTile(old,2,3,6);
    moveTile(old,5,3,3);
    moveTile(old,8,3,0);
    old = old2;
    moveTile(old,0,5,8);
    moveTile(old,3,5,5);
    moveTile(old,6,5,2);
    old = sideCopy(1);
    moveTile(old,0,1,2);
    moveTile(old,1,1,5);
    moveTile(old,2,1,8);
    moveTile(old,3,1,1);
    moveTile(old,5,1,7);
    moveTile(old,6,1,0);
    moveTile(old,7,1,3);
    moveTile(old,8,1,6);
}

void cube::move_r_prime()
{
    short* old;
    short* old2;
    old = sideCopy(5);
    moveTile(0,2,5,2);
    moveTile(0,5,5,5);
    moveTile(0,8,5,8);
    old2 = sideCopy(3);
    moveTile(old,2,3,6);
    moveTile(old,5,3,3);
    moveTile(old,8,3,0);
    old = old2;
    old2 = sideCopy(2);
    moveTile(old,0,2,8);
    moveTile(old,3,2,5);
    moveTile(old,6,2,2);
    old = old2;
    moveTile(old,2,0,2);
    moveTile(old,5,0,5);
    moveTile(old,8,0,8);
    old = sideCopy(1);
    moveTile(old,0,1,6);
    moveTile(old,1,1,3);
    moveTile(old,2,1,0);
    moveTile(old,3,1,7);
    moveTile(old,5,1,1);
    moveTile(old,6,1,8);
    moveTile(old,7,1,5);
    moveTile(old,8,1,2);
}


void cube::move_u()
{
    short* old;
    short* old2;
    old = sideCopy(0);
    moveTile(1,0,0,0);
    moveTile(1,1,0,1);
    moveTile(1,2,0,2);
    old2 = sideCopy(4);
    moveTile(old,0,4,0);
    moveTile(old,1,4,1);
    moveTile(old,2,4,2);
    old = old2;
    old2 = sideCopy(3);
    moveTile(old,0,3,0);
    moveTile(old,1,3,1);
    moveTile(old,2,3,2);
    old = old2;
    moveTile(old,0,1,0);
    moveTile(old,1,1,1);
    moveTile(old,2,1,2);
    old = sideCopy(2);
    moveTile(old,0,2,2);
    moveTile(old,1,2,5);
    moveTile(old,2,2,8);
    moveTile(old,3,2,1);
    moveTile(old,5,2,7);
    moveTile(old,6,2,0);
    moveTile(old,7,2,3);
    moveTile(old,8,2,6);
}

void cube::move_u_prime()
{
    short* old;
    short* old2;
    old = sideCopy(0);
    moveTile(4,0,0,0);
    moveTile(4,1,0,1);
    moveTile(4,2,0,2);
    old2 = sideCopy(1);
    moveTile(old,0,1,0);
    moveTile(old,1,1,1);
    moveTile(old,2,1,2);
    old = old2;
    old2 = sideCopy(3);
    moveTile(old,0,3,0);
    moveTile(old,1,3,1);
    moveTile(old,2,3,2);
    old = old2;
    moveTile(old,0,4,0);
    moveTile(old,1,4,1);
    moveTile(old,2,4,2);
    old = sideCopy(2);
    moveTile(old,0,2,6);
    moveTile(old,1,2,3);
    moveTile(old,2,2,0);
    moveTile(old,3,2,7);
    moveTile(old,5,2,1);
    moveTile(old,6,2,8);
    moveTile(old,7,2,5);
    moveTile(old,8,2,2);
}

void cube::move_l()
{
    short* old;
    short* old2;
    old = sideCopy(5);
    moveTile(0,0,5,0);
    moveTile(0,3,5,3);
    moveTile(0,6,5,6);
    old2 = sideCopy(3);
    moveTile(old,0,3,8);
    moveTile(old,3,3,5);
    moveTile(old,6,3,2);
    old = old2;
    old2 = sideCopy(2);
    moveTile(old,2,2,6);
    moveTile(old,5,2,3);
    moveTile(old,8,2,0);
    old = old2;
    moveTile(old,0,0,0);
    moveTile(old,3,0,3);
    moveTile(old,6,0,6);
    old = sideCopy(4);
    moveTile(old,0,4,2);
    moveTile(old,1,4,5);
    moveTile(old,2,4,8);
    moveTile(old,3,4,1);
    moveTile(old,5,4,7);
    moveTile(old,6,4,0);
    moveTile(old,7,4,3);
    moveTile(old,8,4,6);
}

void cube::move_l_prime()
{
    short* old;
    short* old2;
    old = sideCopy(0);
    moveTile(5,0,0,0);
    moveTile(5,3,0,3);
    moveTile(5,6,0,6);
    old2 = sideCopy(2);
    moveTile(old,0,2,0);
    moveTile(old,3,2,3);
    moveTile(old,6,2,6);
    old = old2;
    old2 = sideCopy(3);
    moveTile(old,0,3,8);
    moveTile(old,3,3,5);
    moveTile(old,6,3,2);
    old = old2;
    moveTile(old,2,5,6);
    moveTile(old,5,5,3);
    moveTile(old,8,5,0);
    old = sideCopy(4);
    moveTile(old,0,4,6);
    moveTile(old,1,4,3);
    moveTile(old,2,4,0);
    moveTile(old,3,4,7);
    moveTile(old,5,4,1);
    moveTile(old,6,4,8);
    moveTile(old,7,4,5);
    moveTile(old,8,4,2);
}