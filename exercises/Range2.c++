// ----------
// Range2.c++
// ----------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename T>
class range {
    private:
        T _b;
        T _e;

    public:
        class iterator {
            private:
                T _v;

            public:
                iterator(const T& v) :
                        _v (v)
                    {}

                bool operator == (const iterator& rhs) const {
                    return (_v == rhs._v);}

                bool operator != (const iterator& rhs) const {
                    return !(*this == rhs);}

                T operator * () {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        range (const T& b, const T& e) :
                _b (b),
                _e (e)
            {}

        iterator begin () {
            return iterator(_b);}

        const iterator begin () const {
            return const_cast<range<T>*>(this)->begin();}

        iterator end () {
            return iterator(_e);}

        const iterator end () const {
            return const_cast<range<T>*>(this)->end();}};

int main () {
    using namespace std;
    cout << "Range2.c++" << endl;

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
