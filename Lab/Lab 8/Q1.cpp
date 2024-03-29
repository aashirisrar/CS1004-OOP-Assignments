#include <iostream>
using namespace std;

class Date
{
    int month;
    int day;
    int year;

public:
    Date();
    Date(int, int, int);
    void setDate(int, int, int);
    void getDate(int &, int &, int &);
    void printDate();
};

Date::Date()
{
    month = 0;
    day = 0;
    year = 0;
}

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::setDate(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::getDate(int &m, int &d, int &y)
{
    m = month;
    d = day;
    y = year;
}

void Date::printDate()
{
    cout << day << "-" << month << "-" << year << endl;
}

class Time
{
    int hr;
    int min;

public:
    Time();
    Time(int, int);
    void setTime(int, int);
    void getTime(int &, int &);
    void printTime();
    void incrementHours();
    void incrementMinutes();
};

Time::Time()
{
    hr = 0;
    min = 0;
}

Time::Time(int h, int m)
{
    hr = h;
    min = m;
}

void Time::setTime(int h, int m)
{
    hr = h;
    min = m;
}

void Time::getTime(int &h, int &m)
{
    h = hr;
    m = min;
}

void Time::printTime()
{
    cout << hr << ":" << min << endl;
}

void Time::incrementHours()
{
    hr++;
}

void Time::incrementMinutes()
{
    min++;
}

class Event
{
    string eventName;
    Time eventTime;
    Date eventDay;

public:
    Event(int, int, int, int, int, string);
    void setEventData(int, int, int, int, int, string);
    void printEventData();
};

Event::Event(int hours = 0, int minutes = 0, int m = 1, int d = 1, int y = 1900, string name = "Christmas")
{
    eventTime.setTime(hours, minutes);
    eventDay.setDate(m, d, y);
    eventName = name;
}

void Event::setEventData(int hours, int minutes, int m, int d, int y, string name)
{
    eventTime.setTime(hours, minutes);
    eventDay.setDate(m, d, y);
    eventName = name;
}

void Event::printEventData()
{
    cout << eventName << endl;
    eventTime.printTime();
    eventDay.printDate();
}

int main()
{
    Event object;

    object.setEventData(6, 0, 12, 25, 2010, "Christmas");

    object.printEventData();

    Event object2;

    object2.setEventData(1, 15, 7, 4, 2010, "Fourth of July");

    object2.printEventData();

    system("PAUSE");
    return 0;
}