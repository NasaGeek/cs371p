// -------------
// IsPrimeT2.c++
// -------------

// https://en.wikipedia.org/wiki/Primality_test

#include <cassert>  // assert
#include <cmath>    // sqrt
#include <iostream> // cout, endl

bool is_prime (int n) {
    assert(n > 0);
    if ((n == 1) || ((n % 2) == 0))
        return n == 2;
    for (int i = 3; i <= sqrt(n); ++++i)
        if ((n % i) == 0)
            return false;
    return true;}

int main () {
    using namespace std;
    cout << "IsPrimeT2.c++" << endl;

    assert(!is_prime(1));
    assert( is_prime(2));
    assert( is_prime(3));
    assert(!is_prime(4));
    assert( is_prime(5));
    assert( is_prime(7));
    assert(!is_prime(9));
    assert(!is_prime(27));
    assert( is_prime(29));

    cout << "Done." << endl;
    return 0;}

/*
% IsPrimeT2
IsPrimeT2.c++
Done.



% gcov -b IsPrimeT2.c++ | grep -A 5 "File 'IsPrimeT2.c++'"
File 'IsPrimeT2.c++'
Lines executed:100.00% of 23
Branches executed:100.00% of 30
Taken at least once:66.67% of 30
No calls
IsPrimeT2.c++:creating 'IsPrimeT2.c++.gcov'
*/
