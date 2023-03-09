#include <iostream>
using namespace std;

class FeetInches
{
    int feet;
    int inches;

    /* this function checks for values in the inches memeber
    greater than twelve or lesss than zero. If such a a value
    is found, the numbers in feet and inches are adjusted to
    conform to a standard feet and inches expression.
    for example, 3 feet 14 inches would be adjusted to 4 feet 2 inches
    and 5 feet 2 inches would be adjusted to 4 feet and 10 inches.*/
    void simplify()
    {
    }

public:
    // constructor
    //  write copy constructor if there is need
    // overload assignment operator, if there is need
    FeetInches()
    {
    }

    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
        // mutator function
        // accessor function
    }
};

int main()
{
    FeetInches f1;
    // display f1
    FeetInches f2 = f1;
    // display f2
    FeetInches f3(5, 18);
    // display f3
    f1 = f3;
    // display f1
    // dsipaly f3
    system("puase");

    return 0;
}