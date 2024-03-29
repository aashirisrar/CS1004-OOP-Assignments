#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
private:
    char *str;
    int length;

public:
    // Default constructor
    MyString()
    {
        length = 1;
        str = new char[length];
        str[0] = '\0';
    }

    // Parametrized constructor
    MyString(const char *s)
    {
        length = strlen(s) + 1;
        str = new char[length];
        StringCopy(str, s);
    }

    // Copy constructor
    MyString(const MyString &obj)
    {
        length = strlen(obj.str) + 1;
        str = new char[length];
        StringCopy(str, obj.str);
    }

    // Destructor
    ~MyString()
    {
        delete[] str;
        str = NULL;
    }

    MyString operator+(const MyString);
    MyString &operator=(const MyString &);
    bool operator<(MyString);

    // Stream insertion operator
    friend ostream &operator<<(ostream &os, const MyString &obj)
    {
        return os << obj.str;
    }

    // Stream extraction operator
    friend istream &operator>>(istream &is, MyString &obj)
    {
        char buffer[1024];
        is >> buffer;
        obj = MyString(buffer);
        return is;
    }

    // Subscript operator
    char &operator[](int index)
    {
        return str[index];
    }

    // Substring operator
    MyString operator()(int start, int len)
    {
        char *substr = new char[len + 1];
        StringNumCopy(substr, str + start, len);
        substr[len] = '\0';
        MyString result(substr);
        delete[] substr;
        return result;
    }

    // Empty string check
    bool operator!()
    {
        return str[0] == '\0';
    }

    // StringCopy function
    void StringCopy(char *dest, const char *src)
    {
        char *ptr = dest;
        while (*src != '\0')
        {
            *ptr++ = *src++;
        }
        *ptr = '\0';
    }

    // StringNumCopy function
    void StringNumCopy(char *dest, const char *src, size_t n)
    {
        char *ptr = dest;
        size_t i;
        for (i = 0; i < n && *src != '\0'; i++)
        {
            *ptr++ = *src++;
        }
        for (; i < n; i++)
        {
            *ptr++ = '\0';
        }
    }

    // StringCat function
    void StringCat(char *dest, const char *src)
    {
        char *ptr = dest + strlen(dest);
        while (*src != '\0')
        {
            *ptr++ = *src++;
        }
        *ptr = '\0';
    }
};

// Assignment operator
MyString &MyString::operator=(const MyString &obj)
{
    if (this != &obj)
    {
        delete[] str;
        str = new char[strlen(obj.str) + 1];
        StringCopy(str, obj.str);
    }
    return *this;
}

// Concatenation operator
MyString MyString::operator+(const MyString obj)
{
    MyString result;
    delete[] result.str;
    result.str = new char[strlen(str) + strlen(obj.str) + 1];
    StringCopy(result.str, str);
    StringCat(result.str, obj.str);
    return result;
}

// Comparision Operator
bool MyString::operator<(const MyString obj)
{
    return strcmp(str, obj.str) < 0;
}

int main()
{
    MyString str1, str2, str3, str4;
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
    if (str3 < str4)
        cout << "String 3 is Less than String 4.\n";
    else
        cout << "String 3 is NOT Less than String 4.\n";
    MyString str5 = str1 + str2;
    cout << "\n\n\nStr5:\t" << str5 << endl;
    cout << "Str5[7]:\t" << str5[7] << endl;
    str5[7] = '$';
    cout << "\n\nStr5:\t" << str5 << endl;
    cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;
    return 0;
}
