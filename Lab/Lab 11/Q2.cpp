#include <iostream>
using namespace std;

template <class T, class U, class D>
T GetMax(T a, U b, D c)
{
    return (a > b && a > c ? a : b > a && b > c ? b
                                                : c);
}

template <class T, class U, class D>
T GetMin(T a, U b, D c)
{
    return (a < b && a < c ? a : b < a && b < c ? b
                                                : c);
}

int main()
{
    int j = 6, k;
    long l = 10, m = 5, n;
    k = GetMax(j, m, l);
    n = GetMin(j, m, l);
    cout << k << endl;
    cout << n << endl;
    return 0;
}

// 3- Yes the program still works
// 5- No there is no problem with this version