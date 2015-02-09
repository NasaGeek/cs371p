/*
CS371p: Quiz #8 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

2 false
3 true
2 false
*/

#include <iostream> // boolalpha, cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int  i = 2;
    int* p = &i;
    ++p;
    cout << i         << " ";
    cout << (p == &i) << endl;
    }

    {
    int  i = 2;
    int* p = &i;
    ++*p;
    cout << i         << " ";
    cout << (p == &i) << endl;
    }

    {
    int   i = 2;
    int*  p = &i;
    int** q = &p;
    ++*q;
    cout << i         << " ";
    cout << (p == &i) << endl;
    }

    return 0;}
