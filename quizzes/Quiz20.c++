/*
CS371p: Quiz #20 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Fill in the blank below.
    [The Dependency Inversion Principle]
    (2 pts)

    High level modules should not depend upon low level modules. Both
    should depend on <BLANK>.

abstractions
*/

/* -----------------------------------------------------------------------
 2. What is the output of the following?
    (4 pts)

-40
12
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T, std::size_t N>
class Allocator {
    private:
        char a[N];

    public:
        const int& operator [] (int i) const {
            return *reinterpret_cast<const int*>(&a[i]);}

    ...};

int main () {
    assert(sizeof(double) == 8);

    Allocator<double, 100> x;

    x.allocate(5);
    x.allocate(3);

    cout << x[0]  << endl;
    cout << x[96] << endl;
    return 0;}
