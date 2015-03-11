// -----------
// Vector3.c++
// -----------

#include <algorithm> // copy, equal, fill
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // distance

template <typename T>
class my_vector {
    private:
        std::size_t _s;
        T*          _a;

    public:
        explicit my_vector (std::size_t s, const T& v = T()) :
                _s (s),
                _a (new T[_s]) {
            std::fill(begin(), end(), v);}

        my_vector (const my_vector& that) :
            <your code>

        my_vector& operator = (my_vector that) {
            <your code>

        ~my_vector () {
            delete [] _a;}

        T* begin () {
            return _a;}

        const T* begin () const {
            return _a;}

        T* end () {
            return _a + _s;}

        const T* end () const {
            return _a + _s;}

        std::size_t size () const {
            return _s;}};

int main () {
    using namespace std;
    cout << "Vector3.c++" << endl;

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
