// ---------
// Range.c++
// ---------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

int main () {
    using namespace std;
    cout << "Range.c++" << endl;

    {
    range<int> x(2, 2);
    range<int>::iterator b = x.begin();
    range<int>::iterator e = x.end();
    assert(b == e);
    }

    {
    range<int> x(2, 3);
    range<int>::iterator b = x.begin();
    range<int>::iterator e = x.end();
    assert(b != e);
    assert(*b == 2);
    ++b;
    assert(b == e);
    }

    {
    range<int> x(2, 4);
    range<int>::iterator b = x.begin();
    range<int>::iterator e = x.end();
    assert(b != e);
    assert(*b == 2);
    ++b;
    assert(b != e);
    assert(*b == 3);
    ++b;
    assert(b == e);
    }

    {
    range<int> x(2, 5);
    range<int>::iterator b = x.begin();
    range<int>::iterator e = x.end();
    ostringstream out;
    copy(b, e, ostream_iterator<int>(out));
    assert(out.str() == "234");
    }

    cout << "Done." << endl;
    return 0;}
