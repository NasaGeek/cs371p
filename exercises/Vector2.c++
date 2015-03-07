// -----------
// Vector2.c++
// -----------

#include <algorithm> // fill
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream

template <typename T>
class my_vector {
    private:
        T* const          _a;
        const std::size_t _s;

    public:
        my_vector (size_t s = 0, const T& v = T()) :
                _a (s == 0 ? 0 : new T[s]),
                _s (s) {
            std::fill(_a, _a + _s, v);}

        ~my_vector () {
            delete [] _a;}

        T& operator [] (size_t i) {
            return _a[i];}

        const T& operator [] (size_t i) const {
            return _a[i];}

        T* begin () {
            return _a;}

        const T* begin () const {
            return const_cast<my_vector<T>*>(this)->begin();}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return const_cast<my_vector<T>*>(this)->end();}

        std::size_t size () const {
            return _s;}};

int main () {
    using namespace std;
    cout << "Vector2.c++" << endl;

    {
    my_vector<int> x;
    }

    {
    my_vector<int> x(3);
    assert(x.size() == 3);
    assert(x[1] == 0);
    x[1] = 2;
    assert(x[1] == 2);
    }

    {
    my_vector<int> x(3, 4);
    assert(x.size() == 3);
    assert(x[1] == 4);
    x[1] = 2;
    assert(x[1] == 2);
    ostringstream out;
    copy(x.begin(), x.end(), ostream_iterator<int>(out));
    assert(out.str() == "424");
    }

    cout << "Done." << endl;
    return 0;}
