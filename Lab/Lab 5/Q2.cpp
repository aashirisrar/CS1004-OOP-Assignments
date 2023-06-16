#include <iostream>
using namespace std;

class MyBigInt
{
    int *big_int_;
    int int_length_;

public:
    MyBigInt()
    {
        big_int_ = nullptr;
        int_length_ = 0;
    }

    MyBigInt(int size)
    {
        int_length_ = size;
        big_int_ = new int[int_length_];
    }

    MyBigInt(const MyBigInt &obj)
    {
        cout << "Copy constructor called!" << endl;

        big_int_ = new int[obj.int_length_];
        int_length_ = obj.int_length_;

        for (int i = 0; i < int_length_; i++)
        {
            big_int_[i] = obj.big_int_[i];
        }
    }

    void assign(const MyBigInt &obj)
    {
        if (big_int_ != nullptr)
        {
            delete[] big_int_;
        }

        big_int_ = new int[obj.int_length_];
        int_length_ = obj.int_length_;

        for (int i = 0; i < int_length_; i++)
        {
            big_int_[i] = obj.big_int_[i];
        }
    }

    void display()
    {
        if (big_int_ == nullptr)
        {
            cout << "No Value Assigned" << endl;
            return;
        }

        cout << "Big int:" << endl;
        for (int i = 0; i < int_length_; i++)
        {
            cout << big_int_[i];
        }

        cout << endl;
    }

    ~MyBigInt()
    {
        if (big_int_ != nullptr)
        {
            delete[] big_int_;
            big_int_ = nullptr;
        }
    }
};

int main()
{
    MyBigInt obj1(5);
    obj1.display();

    MyBigInt obj2(obj1);
    obj2.display();

    MyBigInt obj3;
    obj3.assign(obj2);
    obj3.display();

    return 0;
}