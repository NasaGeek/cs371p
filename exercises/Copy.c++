// ---------
// Copy2.c++
// ---------

// http://www.cplusplus.com/reference/algorithm/copy/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

int main () {
    using namespace std;
    cout << "Copy.c++" << endl;

    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    vector<int>::iterator p = my_copy(x.begin(), x.end(), y.begin() + 1);
    assert(p == y.begin() + 4);
    assert(equal(x.begin(), x.end(), y.begin() + 1));

    cout << "Done." << endl;
    return 0;}
