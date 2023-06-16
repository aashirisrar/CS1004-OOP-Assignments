#include <iostream>
#include <cstring>
using namespace std;

class InvalidDate
{
    int date;

public:
    InvalidDate(int date)
    {
        this->date = date;
    }

    string what()
    {
        return "Invalid Date: " + to_string(date);
    }
};

class InvalidMonth
{
    int month;

public:
    InvalidMonth(int month)
    {
        this->month = month;
    }

    string what()
    {

        return "Invalid Month: " + to_string(month);
    }
};

class InvalidYear
{
    int year;

public:
    InvalidYear(int year)
    {
        this->year = year;
    }

    string what()
    {

        return "Invalid Year: " + to_string(year);
    }
};

int main()
{
    string date;
    try
    {
        cout << "Enter your date of birth in the format (mm-dd-yyyy):";
        cin >> date;

        int i = 0;
        int dob = 0;
        int mob = 0;
        int yob = 0;

        for (; date[i] != '-'; i++)
        {
            dob = dob * 10 + (date[i] - '0');
        }
        i++;
        for (; date[i] != '-'; i++)
        {
            mob = mob * 10 + (date[i] - '0');
        }
        i++;
        for (; date[i] != '\0'; i++)
        {
            yob = yob * 10 + (date[i] - '0');
        }

        if (dob < 1 || dob > 31)
        {
            throw InvalidDate(dob);
        }
        else if (mob < 1 || mob > 12)
        {
            throw InvalidMonth(mob);
        }
        else if (yob < 1950)
        {
            throw InvalidYear(yob);
        }
        else
        {
            if (mob == 1)
            {
                cout << "January " << dob << ", " << yob << endl;
            }
            else if (mob == 2)
            {
                cout << "February " << dob << ", " << yob << endl;
            }
            else if (mob == 3)
            {
                cout << "March " << dob << ", " << yob << endl;
            }
            else if (mob == 4)
            {
                cout << "April " << dob << ", " << yob << endl;
            }
            else if (mob == 5)
            {
                cout << "May " << dob << ", " << yob << endl;
            }
            else if (mob == 6)
            {
                cout << "June " << dob << ", " << yob << endl;
            }
            else if (mob == 7)
            {
                cout << "July " << dob << ", " << yob << endl;
            }
            else if (mob == 8)
            {
                cout << "August " << dob << ", " << yob << endl;
            }
            else if (mob == 9)
            {
                cout << "September " << dob << ", " << yob << endl;
            }
            else if (mob == 10)
            {
                cout << "October " << dob << ", " << yob << endl;
            }
            else if (mob == 11)
            {
                cout << "November " << dob << ", " << yob << endl;
            }
            else if (mob == 12)
            {
                cout << "December " << dob << ", " << yob << endl;
            }
        }
    }
    catch (InvalidDate &e)
    {
        cout << e.what();
    }
    catch (InvalidMonth &e)
    {
        cout << e.what();
    }
    catch (InvalidYear &e)
    {
        cout << e.what();
    }

    return 0;
}