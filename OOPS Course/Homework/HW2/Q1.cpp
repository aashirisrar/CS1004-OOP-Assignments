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
        if (inches >= 12)
        {
            feet += inches / 12;
            inches %= 12;
        }
        else if (inches < 0)
        {
            feet -= abs(inches) / 12 + 1;

            inches = 12 - abs(inches) % 12;
            if (inches == 12)
            {
                inches = 0;
                feet--;
            }
        }
    }

public:
    // constructor
    //  write copy constructor if there is need
    // overload assignment operator, if there is need

    // default constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // copy constructor
    FeetInches(const FeetInches &obj)
    {
        feet = obj.feet;
        inches = obj.inches;
    }

    // overloaded = operator
    void operator=(const FeetInches &obj)
    {
        feet = obj.feet;
        inches = obj.inches;
    }

    FeetInches operator+(const FeetInches &obj)
    {
        int total_inches = inches + obj.inches;
        int total_feet = feet + obj.feet;
        if (total_inches >= 12)
        {
            total_feet += total_inches / 12;
            total_inches %= 12;
        }
        return FeetInches(total_feet, total_inches);
    }

    FeetInches operator-(const FeetInches &obj)
    {
        int total_inches = inches - obj.inches;
        int total_feet = feet - obj.feet;
        if (total_inches < 0)
        {
            total_feet -= abs(total_inches) / 12 + 1;
            total_inches = 12 - abs(total_inches) % 12;
        }
        return FeetInches(total_feet, total_inches);
    }

    FeetInches operator*(const int &num)
    {
        int total_inches = inches * num;
        int total_feet = feet * num;
        if (total_inches >= 12)
        {
            total_feet += total_inches / 12;
            total_inches %= 12;
        }
        return FeetInches(total_feet, total_inches);
    }

    FeetInches operator/(const int &num)
    {
        int total_inches = inches / num;
        int total_feet = feet / num;
        if (inches % num != 0)
        {
            total_feet += total_inches / 12;
            total_inches %= 12;
        }
        return FeetInches(total_feet, total_inches);
    }

    bool operator>(const FeetInches &obj)
    {
        if (feet > obj.feet)
        {
            return true;
        }
        else if (feet == obj.feet && inches > obj.inches)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<(const FeetInches &obj)
    {
        if (feet < obj.feet)
        {
            return true;
        }
        else if (feet == obj.feet && inches < obj.inches)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator>=(const FeetInches &obj)
    {
        return (*this > obj || *this == obj);
    }

    bool operator<=(const FeetInches &obj)
    {
        return (*this < obj || *this == obj);
    }

    bool operator==(const FeetInches &obj)
    {
        return (feet == obj.feet) && (inches == obj.inches);
    }

    // mutator function - setters
    void feetSetter(int f)
    {
        feet = f;
    }

    void inchesSetter(int i)
    {
        inches = i;
    }

    // accessor function - getters
    int feetGetter()
    {
        return feet;
    }

    int inchesGetter()
    {
        return inches;
    }

    void display()
    {
        cout << feet << " " << inches << endl;
    }
};

int main()
{
    FeetInches f1;
    f1.display();

    FeetInches f2 = f1;
    f2.display();

    FeetInches f3(5, 18);
    f3.display();

    f1 = f3;
    f1.display();
    f3.display();

    return 0;
}