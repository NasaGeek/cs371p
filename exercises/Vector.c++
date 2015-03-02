// ----------
// Vector.c++
// ----------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // ostream_iterator
#include <sstream>   // ostringstream
#include <vector>    // vector

int main () {
    using namespace std;
    cout << "Vector.c++" << endl;

    {
    vector<int> x;
    }

    {
    vector<int> x(3);
    assert(x.size() == 3);
    assert(x[1] == 0);
    x[1] = 2;
    assert(x[1] == 2);
    }

    {
    vector<int> x(3, 4);
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
