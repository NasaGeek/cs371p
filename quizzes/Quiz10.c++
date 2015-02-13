/*
CS371p: Quiz #10 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. In C++, what four methods constitute the orthodox canonical class
    form?
    [Sec. 5.6, Pg. 115]
    (4 pts)

default constructor
copy constructor
copy assignment operator
destructor
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (2 pts)

8
12
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;

    int  a[3]    = {2, 3, 4};
    int* p       = a;
    int  (&r)[3] = a;

    cout << sizeof(p) << endl;
    cout << sizeof(r) << endl;

    return 0;}
