/*
CS371p: Quiz #15 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Fill in the TWO blanks below.
    [The Open-Closed Principle]
    (2 pts)

    Software entities (classes, modules, functions, etc.) should be open
    for <BLANK>, but closed for <BLANK>.

extension
modification
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (4 pts)

A()
A(A) A(A)
A(A) A(A)
=(A) =(A)
~A() ~A() ~A() ~A() ~A()
*/

#include <iostream> // cout, endl
#include <vector>   // vector

using namespace std;

struct A {
    A             ()         {cout << "A() ";}                  // default constructor
    A             (const A&) {cout << "A(A) ";}                 // copy constructor
    ~A            ()         {cout << "~A() ";}                 // destructor
    A& operator = (const A&) {cout << "=(A) "; return *this;}}; // copy assignment operator

int main () {
    {
    A x;
    cout << endl;
    vector<A> y(2, x);
    cout << endl;
    vector<A> z = y;
    cout << endl;
    z = y;
    cout << endl;
    }
    cout << endl;

    return 0;}
