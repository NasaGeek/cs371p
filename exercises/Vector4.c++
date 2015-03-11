// -----------
// Vector4.c++
// -----------

#include <algorithm> // copy, equal, fill, swap
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // distance

template <typename T>
class my_vector {
    private:
        T*          _a;
        std::size_t _s;

    public:
        my_vector (std::size_t s = 0, const T& v = T()) :
                _a (s == 0 ? 0 : new T[s]),
                _s (s) {
            std::fill(begin(), end(), v);}

        my_vector (const my_vector& that) :
                _a (new T[that._s]),
                _s (that._s) {
            std::copy(that.begin(), that.end(), begin());}

        my_vector& operator = (my_vector that) {
            std::swap(_a, that._a);
            std::swap(_s, that._s);
            return *this;}

        ~my_vector () {
            delete [] _a;}

       T& operator [] (std::size_t i) {
            return _a[i];}

        const T& operator [] (std::size_t i) const {
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
    cout << "Vector4.c++" << endl;

    {
    const my_vector<int> x(10, 2);
    const my_vector<int> y = x;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    {
          my_vector<int> x(10, 2);
    const my_vector<int> y(20, 3);
    x = y;
    assert(equal(x.begin(), x.end(), y.begin()) == true);
    }

    cout << "Done." << endl;
    return 0;}
