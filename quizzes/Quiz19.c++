/*
CS371p: Quiz #19 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. What is the output of the following?
    (6 pts)

A() A() A()
A(int)
=(A) =(A) =(A)
~A() ~A() ~A()
~A()

A(int)
A(A) A(A) A(A)
~A() ~A() ~A()
~A()
*/

#include <cassert>  // assert
#include <iostream> // cout, endl, ostream
#include <memory>   // allocator

using namespace std;

struct A {
    A             ()         {cout << "A() ";}                  // default constructor
    A             (int)      {cout << "A(int) ";}               // int constructor
    A             (const A&) {cout << "A(A) ";}                 // copy constructor
    ~A            ()         {cout << "~A() ";}                 // destructor
    A& operator = (const A&) {cout << "=(A) "; return *this;}}; // copy assignment operator

int main () {
    int s = 3;

    {
    A*  a = new A[s];
    cout << endl;
    A   v = 2;
    cout << endl;
    for (int i = 0; i != s; ++i)
        a[i] = v;
    cout << endl;
    delete [] a;
    cout << endl;
    }
    cout << endl << endl;

    {
    allocator<A> x;
    A* a = x.allocate(s);
    A  v = 2;
    cout << endl;
    for (int i = 0; i != s; ++i)
        x.construct(a + i, v);
    cout << endl;
    for (int i = 0; i != s; ++i)
        x.destroy(a + i);
    cout << endl;
    x.deallocate(a, s);
    }
    cout << endl;
    return 0;}
