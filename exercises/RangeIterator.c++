// -----------------
// RangeIterator.c++
// -----------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

int main () {
    using namespace std;
    cout << "RangeIterator.c++" << endl;

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 2;
    assert(b == e);
    }

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 3;
    assert(b != e);
    assert(*b == 2);
    ++b;
    assert(b == e);
    }

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 4;
    assert(b != e);
    assert(*b == 2);
    ++b;
    assert(b != e);
    assert(*b == 3);
    ++b;
    assert(b == e);
    }

    {
    range_iterator<int> b = 2;
    range_iterator<int> e = 5;
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "234");
    }

    cout << "Done." << endl;
    return 0;}
