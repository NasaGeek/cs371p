/*
CS371p: Quiz #12 (7 pts)
*/

/* -----------------------------------------------------------------------
 1. Which of p, q, and r, compiles or doesn't compile?
    If not, why not>
    (6 pts)

p compiles
q doesn't compile, read-write pointer to read-only target
r compiles
*/

int main () {
          int i  = 2;
    const int ci = 2;

    const int*  p = &i;
//  int*  const q = &ci;
    const int&  r = i;

    return 0;}
