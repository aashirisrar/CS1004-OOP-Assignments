#include <iostream>
using namespace std;

class Complex
{
    int real;
    int imaginary;

public:
    // Default constructor
    Complex(int real = 0, int imaginary = 0)
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    // Copy constructor
    Complex(const Complex &obj)
    {
        real = obj.real;
        imaginary = obj.imaginary;
    }

    // overload the operators +, - , << , >>, ==, !=,=
    Complex operator+(const Complex &obj)
    {
        Complex result(real + obj.real, imaginary + obj.imaginary);
        return result;
    }

    Complex operator-(const Complex &obj)
    {
        Complex result(real - obj.real, imaginary - obj.imaginary);
        return result;
    }

    friend ostream &operator<<(ostream &strm, const Complex &obj)
    {
        if (obj.imaginary > 0)
        {
            strm << obj.real << " + " << obj.imaginary << "i" << endl;
        }
        else
        {
            strm << obj.real << " " << obj.imaginary << "i" << endl;
        }
        return strm;
    }

    friend istream &operator>>(istream &strm, Complex &obj)
    {
        cout << "Enter the real part:";
        strm >> obj.real;

        cout << "Enter the imaginary part:";
        strm >> obj.imaginary;

        return strm;
    }

    bool operator==(const Complex &obj)
    {
        return (real == obj.real) && (imaginary == obj.imaginary);
    }

    bool operator!=(const Complex &obj)
    {
        return (real != obj.real) && (imaginary != obj.imaginary);
    }

    void operator=(const Complex &obj)
    {
        real = obj.real;
        imaginary = obj.imaginary;
    }

    // Destructor
    ~Complex()
    {
        real = 0;
        imaginary = 0;
    }
};

int main()
{
    Complex C1;
    Complex C2(5, 6);
    Complex C3;

    cout << "Input a complex number:" << endl;
    cin >> C3;

    cout << C1 << C2 << C3;

    if (C1 == C2)
        cout << "C1 == C2" << endl;
    else
        cout << "C1 != C2" << endl;

    if (C1 != C3)
        cout << "C1 != C3" << endl;
    else
        cout << "C1 == C3" << endl;

    Complex C4 = C2 - C3;
    cout << C4;

    return 0;
}
