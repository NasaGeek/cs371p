// ------------------
// RangeIterator2.c++
// ------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename T>
class range_iterator {
    private:
        T _v;

    public:
        range_iterator(const T& v) :
                _v (v)
            {}

        bool operator == (const range_iterator& rhs) const {
            return (_v == rhs._v);}

        bool operator != (const range_iterator& rhs) const {
            return !(*this == rhs);}

        T operator * () {
            return _v;}

        range_iterator& operator ++ () {
            ++_v;
            return *this;}

        range_iterator operator ++ (int) {
            range_iterator x = *this;
            ++*this;
            return x;}};

int main () {
    using namespace std;
    cout << "RangeIterator2.c++" << endl;

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
