// -----------
// Vector5.c++
// -----------

#include <algorithm> // copy, equal, swap
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <memory>    // allocator
#include <sstream>   // ostringstream
#include <vector>    // vector

using namespace std;

int main () {
    cout << "Vector5.c++" << endl;

    {
    vector<int> x;
    }

    {
    vector<int, allocator<int>> x(3);
    assert(x.size() == 3);
    assert(x[1] == 0);
    x[1] = 2;
    assert(x[1] == 2);
    }

    {
    const vector<int> x(3, 4, allocator<int>());
    assert(x.size() == 3);
    assert(x[1] == 4);
    ostringstream out;
    copy(x.begin(), x.end(), ostream_iterator<int>(out));
    assert(out.str() == "444");
    }

    {
    const vector<int> x(10, 2);
    const vector<int> y = x;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    {
          vector<int> x(10, 2);
    const vector<int> y(20, 3);
    x = y;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    cout << "Done." << endl;
    return 0;}
