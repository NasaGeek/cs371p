/*
CS371p: Quiz #14 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. What are the two reasons to use inheritance?
    [Sec. 8.1, Pg. 163]
    (2 pts)

code    reuse (implementation)
concept reuse (interface)
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (4 pts)

3 false
3 true
*/

#include <iostream> // boolalpha, cout, endl

int*& f (int*& r) {
    ++*r;
    return r;}

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int  i = 2;
    int* p = &i;
    int* q = f(p);
    cout << i          << " ";
    cout << (&q == &p) << endl;
    }

    {
    int   i = 2;
    int*  p = &i;
    int*& q = f(p);
    cout << i          << " ";
    cout << (&q == &p) << endl;
    }

    return 0;}
