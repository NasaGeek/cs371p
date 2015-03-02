/*
CS371p: Quiz #17 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Define the class Fraction such that the following works.
    (6 pts)
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename T>
class Fraction {
    private:
        T _n;
        T _d;

    public:
        Fraction (const T& n, const T& d) :
                _n (n),
                _d (d)
            {}

        bool operator == (const Fraction& rhs) const {
            return (_n * rhs._d) == (_d * rhs._n);}

        const Fraction operator * (const Fraction& rhs) const {
            return Fraction(_n * rhs._n, _d * rhs._d);}};

int main () {
    Fraction<int> x(2, 3);
    Fraction<int> y(4, 5);
    Fraction<int> z = x * y;           // z = x.operator*(y)
    assert(z == Fraction<int>(8, 15)); // z.operator==(Fraction<int>(8, 15))
    return 0;}
