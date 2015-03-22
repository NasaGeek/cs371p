// ----------
// Vector.c++
// ----------

#include <algorithm> // fill
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream
#include <vector>    // vector

using namespace std;

int main () {
    cout << "Vector.c++" << endl;

    {
    vector<int> x;
    }

    {
    vector<int> x(3);
    assert(x.size() == 3);
    assert(x[1] == 0);
    x[1] = 2;
    assert(x[1] == 2);
    }

    {
    const vector<int> x(3, 4);
    assert(x.size() == 3);
    assert(x[1] == 4);
    ostringstream out;
    copy(x.begin(), x.end(), ostream_iterator<int>(out));
    assert(out.str() == "444");
    }

    cout << "Done." << endl;
    return 0;}
