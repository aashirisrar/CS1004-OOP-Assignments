#include <iostream>
using namespace std;

// Exception class
class tornadoException
{
    int m;

public:
    tornadoException()
    {
        m = -1;
    }

    tornadoException(int m)
    {
        this->m = m;
    }

    string what()
    {
        if (m < 0)
        {
            return "Tornado: Take cover immediately";
        }
        else
        {
            return "Tornado:" + to_string(m) + " miles away and approching";
        }
    }
};

int main()
{
    try
    {
        throw tornadoException();
    }
    catch (tornadoException &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        throw tornadoException(5);
    }
    catch (tornadoException &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}