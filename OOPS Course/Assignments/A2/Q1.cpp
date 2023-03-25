#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    // You can add your code here
private:
    char *str;
    int length; // including the null char here
    // Add GetStringFromBuffer as private member (helper)
    void GetStringFromBuffer();
    // Add Concatenate as private member (helper)
    void Concatenate();
    // You can add your class members here
public:
    //-------------DO_NOT_CHANGE REGION starts below---------------------
    // Do not change the prototypes given below
    MyString operator+(const MyString);
    MyString &operator=(const MyString &);
    bool operator<(MyString); // Comparison on the basis of ascii values
    //-------------End of DO_NOT_CHANGE REGION---------------------
    MyString(int length = 1)
    {
        this->length = length;
        str = new char[length];
        str[0] = '\0';
    }

    MyString(const MyString &obj)
    {
        length = obj.length;
        str = new char[length];
        strcpy(str, obj.str);
    }

    friend ostream &operator<<(ostream &strm, const MyString &obj)
    {
        if (obj.str[0] != '\n')
        {
            strm << obj.str;
        }
        return strm;
    }

    friend istream &operator>>(istream &strm, MyString &obj)
    {
        strm >> obj.str;
        return strm;
    }

    bool operator!()
    {
        return length == 1;
    }

    MyString operator[](int n)
    {
        return str[n];
    }

    // // destructor
    // ~MyString()
    // {
    //     delete[] str;
    // }
};
//--------------------------Add your code here----------------------
MyString MyString::operator+(const MyString obj)
{
    MyString result(obj.length + length);
    strcpy(result.str, str);
    strcat(result.str, obj.str);
    return result;
}

MyString &MyString::operator=(const MyString &obj)
{
    if (str != obj.str)
    {
        length = obj.length;
        delete[] str;
        str = new char[length];
        strcpy(str, obj.str);
    }
    return *this;
}

bool MyString::operator<(MyString obj)
{
    return strcmp(str, obj.str);
}

//-------------DO_NOT_CHANGE REGION starts below---------------------
int main()
{
    MyString str1, str2, str3, str4; // Default constructor will make a string of
    // lenght 1 having null character only i.e.empty string
    if (!str1)
    {
        cout << "String 1 is Empty.\n";
        cout << "Str 1 = " << str1 << endl
             << endl
             << endl;
    }
    cout << "Enter String 1:\t";
    cin >> str1;
    cout << "Enter String 2:\t";
    cin >> str2;
    cout << "\n\n\nUser Entered:\n";
    cout << "String 1 = " << str1 << endl;
    cout << "String 2 = " << str2 << endl
         << endl
         << endl;
    // What is following code testing?
    cout << "Before str1 = str1; str1 = " << str1 << endl;
    str1 = str1;
    cout << "After str1 = str1, str1 = " << str1 << endl
         << endl
         << endl;
    cout << "Before str4 = str3 = str1+str2\n";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    str4 = str3 = str1 + str2;
    cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;
    cout << "str3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    cout << "\n\n\nEnter String 3:\t";
    cin >> str3;
    cout << "\n\n\nEnter String 4:\t";
    cin >> str4;
    cout << "\n\n\nstr3 = " << str3 << endl;
    cout << "str4 = " << str4 << endl;
    // if (str3 < str4)
    //     cout << "String 3 is Less than String 4.\n";
    // else
    //     cout << "String 3 is NOT Less than String 4.\n";
    // MyString str5 = str1 + str2;
    // cout << "\n\n\nStr5:\t" << str5 << endl;
    // cout << "Str5[7]:\t" << str5[7] << endl; // Function Call: str5.operator[](7).
    // str5[7] = '$';
    // cout << "\n\nStr5:\t" << str5 << endl;
    // cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl; // Substring of lenght 10
    // starting from index 5.Function Call str5.operator()(5, 10) Let the returned MyString or char *leak
    return 0;
}
//-------------End of DO_NOT_CHANGE REGION---------------------