/*
CS371p: Quiz #18 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Fill in the TWO blanks below:
    [The Liskov Substitution Principle]
    (2 pts)

    Functions that use pointers or references to <BLANK> classes must be
    able to use objects of <BLANK> classes without knowing it.

base
derived
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (4 pts)

_p _q
_q _p
*/

#include <cassert>  // assert
#include <iostream> // cout, endl, ostream

using namespace std;

struct A {
    ostream* _p;
    ostream* _q;

    A (int) :
            _q (&(cout << "_q ")),
            _p (&(cout << "_p "))
        {}

    A (int, int) {
        _q = &(cout << "_q ");
        _p = &(cout << "_p ");}};

int main () {
    {
    A x(2);
    }
    cout << endl;

    {
    A x(2, 3);
    }
    cout << endl;
    return 0;}
