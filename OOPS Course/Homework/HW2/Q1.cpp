#include <iostream>
using namespace std;

class FeetInches
{
    int feet;
    int inches;

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

    // overloaded operators
    void operator=(const FeetInches &obj)
    {
        feet = obj.feet;
        inches = obj.inches;
    }

    FeetInches operator+(const FeetInches &obj) const
    {
        FeetInches result(feet + obj.feet, inches + obj.inches);
        result.simplify();
        return result;
    }

    FeetInches operator-(const FeetInches &obj) const
    {
        FeetInches result(feet - obj.feet, inches - obj.inches);
        result.simplify();
        return result;
    }

    FeetInches operator*(int n) const
    {
        FeetInches result(feet * n, inches * n);
        result.simplify();
        return result;
    }

    FeetInches operator/(int n) const
    {
        FeetInches result(feet / n, inches / n);
        result.simplify();
        return result;
    }

    bool operator>(const FeetInches &obj) const
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

    bool operator<(const FeetInches &obj) const
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

    bool operator>=(const FeetInches &obj) const
    {
        if (feet > obj.feet)
        {
            return true;
        }
        else if (feet == obj.feet && inches >= obj.inches)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator<=(const FeetInches &obj) const
    {
        if (feet < obj.feet)
        {
            return true;
        }
        else if (feet == obj.feet && inches <= obj.inches)
        {
            return true;
        }
        else
        {
            return false;
        }
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