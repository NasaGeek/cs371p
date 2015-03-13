/*
CS371p: Quiz #21 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Fill in the TWO blanks below:
    [Sec. 11.2, Pg. 224]
    (2 pts)

    In a statically typed object-oriented programming language, the
    legality of a message-passing expression is determined at compile time
    based on the <BLANK> class of the receiver and not on its current
    <BLANK> value.
*/

/* -----------------------------------------------------------------------
 2. Define vector<T>'s copy constructor and copy assignment operator as
    are freely provided by the compiler.
    (4 pts)
*/

template <typename T>
class my_vector {
    private:
        T*          _a;
        std::size_t _s;

    public:
        ...};
