#include <iostream>
using namespace std;

template <class T>
void increment(T a)
{
    cout << ++a << endl;
}

template <>
void increment<char *>(char *a)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 97 && a[i] <= 122)
        {
            a[i] -= 32;
        }
    }
}

int main()
{
    int a = 5;
    increment(a);

    char *ptr = new char[5];
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = 'a' + i;
    }

    increment(ptr);

    for (int i = 0; i < 5; i++)
    {
        cout << ptr[i] << endl;
    }

    delete ptr;
    ptr = 0;

    return 0;
}