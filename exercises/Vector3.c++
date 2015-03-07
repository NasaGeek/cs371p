// -----------
// Vector3.c++
// -----------

#include <algorithm> // fill
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <memory>    // allocator
#include <sstream>   // ostringstream

template <typename A, typename BI>
void my_destroy (A& a, BI b, BI e) {
    while (b != e) {
        --e;
        a.destroy(&*e);}}

template <typename A, typename BI, typename U>
void my_uninitialized_fill (A& a, BI b, BI e, const U& v) {
    BI p = b;
    try {
        while (b != e) {
            a.construct(&*b, v);
            ++b;}}
    catch (...) {
        my_destroy(a, p, b);
        throw;}}

template <typename T, typename A = std::allocator<T> >
class my_vector {
    private:
        A                 _x;
        T* const          _a;
        const std::size_t _s;

    public:
        my_vector (std::size_t s = 0, const T& v = T(), const A& x = A()) :
                _x (x),
                _a (_x.allocate(s)),
                _s (s) {
            my_uninitialized_fill(_x, _a, _a + _s, v);}

        ~my_vector () {
            my_destroy(_x, _a, _a + _s);
            _x.deallocate(_a, _s);}

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
    cout << "Vector3.c++" << endl;

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
