// ------------
// IsPrimeT.c++
// ------------

// https://en.wikipedia.org/wiki/Primality_test

#include <cassert>  // assert
#include <cmath>    // sqrt
#include <iostream> // cout, endl

bool is_prime (int n) {
    assert(n > 0);
    if ((n == 1) || ((n % 2) == 0))
        return false;
    for (int i = 3; i < sqrt(n); ++i)
        if ((n % i) == 0)
            return false;
    return true;}

int main () {
    using namespace std;
    cout << "IsPrimeT.c++" << endl;

    assert(!is_prime(1));
    assert(!is_prime(2));
    assert( is_prime(3));
    assert(!is_prime(4));
    assert( is_prime(5));
    assert( is_prime(7));
    assert( is_prime(9));
    assert(!is_prime(27));
    assert( is_prime(29));

    cout << "Done." << endl;
    return 0;}

/*
% IsPrimeT
IsPrimeT.c++
Done.



% gcov -b IsPrimeT.c++ | grep -A 5 "File 'IsPrimeT.c++'"
File 'IsPrimeT.c++'
Lines executed:100.00% of 19
Branches executed:100.00% of 28
Taken at least once:64.29% of 28
No calls
IsPrimeT.c++:creating 'IsPrimeT.c++.gcov'
*/
