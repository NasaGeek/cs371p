/*
CS371p: Quiz #11 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Which of the following lines do NOT compile?
    Why not?
    (6 pts)
*/

#include <algorithm>    // equal, sort, reverse
#include <cassert>      // assert
#include <forward_list> // forward_list
#include <iostream>     // cout, endl
#include <list>         // list
#include <vector>       // vector

int main () {
    using namespace std;

    // forward_list is singly-linked
    // list         is doubly-linked
    // vector       is based on arrays

    // reverse needs to go backwards
    // sort    needs random access

    {
    forward_list<int> x = {2, 3, 4};
    assert(equal(x.begin(), x.end(), x.begin()));
//  reverse(x.begin(), x.end());
//  sort(x.begin(), x.end());
    }

    {
    list<int> x = {2, 3, 4};
    assert(equal(x.begin(), x.end(), x.begin()));
    reverse(x.begin(), x.end());
//  sort(x.begin(), x.end());
    }

    {
    vector<int> x = {2, 3, 4};
    assert(equal(x.begin(), x.end(), x.begin()));
    reverse(x.begin(), x.end());
    sort(x.begin(), x.end());
    }

    return 0;}
