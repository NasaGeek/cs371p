/*
CS371p: Quiz #24 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Describe the "the fragile base-class problem".
    [Why Extends is Evil]
    (2 pts)

Base classes are considered fragile because you can modify a base class in
a seemingly safe way, but this new behavior, when inherited by the derived
classes, might cause the derived classes to malfunction.
*/

/* -----------------------------------------------------------------------
 2. Define vector<T>'s copy assignment operator with the swap trick.
    (4 pts)
*/

template <typename T>
class my_vector {
    private:
        std::size_t _s;
        T*          _a;

    public:
        my_vector& operator = (my_vector rhs) {
            swap(_s, rhs._s);
            swap(_a, rhs._a);
            return *this;}};
