// ---------
// Equal.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/equal/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int main () {
    using namespace std;
    cout << "Equal2.c++" << endl;

    {
    const int a[] = {2, 3, 4};
    const int b[] = {2, 3, 4};
    assert(my_equal(a, a + 3, b));
    assert(   equal(a, a + 3, b));
    }

    {
    const vector<int> x = {2, 3, 4};
    const list<int>   y = {2, 3, 4};
    assert(my_equal(x.begin(), x.end(), y.begin()));
    assert(   equal(x.begin(), x.end(), y.begin()));
    }

    {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {2, 3, 4};
    assert(my_equal(x.begin(), x.end(), y.begin()));
    assert(   equal(x.begin(), x.end(), y.begin()));
    }

    cout << "Done." << endl;
    return 0;}
