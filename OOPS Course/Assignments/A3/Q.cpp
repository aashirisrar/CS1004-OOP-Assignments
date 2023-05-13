#include <iostream>
#include <math.h>
using namespace std;

class bigint
{
  int v[5];

public:
  // constructors
  bigint()
  {
    v[0] = 0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
  }
  bigint(int x0)
  {
    v[0] = x0;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
  }
  bigint(int x0, int x1)
  {
    v[0] = x0;
    v[1] = x1;
    v[2] = 0;
    v[3] = 0;
    v[4] = 0;
  }
  bigint(int x0, int x1, int x2)
  {
    v[0] = x0;
    v[1] = x1;
    v[2] = x2;
    v[3] = 0;
    v[4] = 0;
  }
  bigint(int x0, int x1, int x2, int x3)
  {
    v[0] = x0;
    v[1] = x1;
    v[2] = x2;
    v[3] = x3;
    v[4] = 0;
  }
  bigint(int x0, int x1, int x2, int x3, int x4)
  {
    v[0] = x0;
    v[1] = x1;
    v[2] = x2;
    v[3] = x3;
    v[4] = x4;
  }

  // functions
  friend istream &operator>>(istream &strm, const bigint &obj)
  {
    return strm;
  }

  friend ostream &operator<<(ostream &strm, const bigint &obj)
  {
    strm << obj.v[4] << "," << obj.v[3] << "," << obj.v[2] << "," << obj.v[1] << "," << obj.v[0];

    return strm;
  }

  void operator+(const bigint &obj)
  {
  }

  void operator-(const bigint &obj)
  {
  }

  friend bool operator<(const bigint &a, const bigint &b)
  {
    for (int i = 4; i >= 0; i--)
    {
      if (a.v[i] != b.v[i])
      {
        return a.v[i] < b.v[i];
      }
    }

    return 0;
  }

  friend bool operator>(const bigint &a, const bigint &b)
  {
    for (int i = 4; i >= 0; i--)
    {
      if (a.v[i] != b.v[i])
      {
        return a.v[i] > b.v[i];
      }
    }

    return 0;
  }

  friend bool operator<=(const bigint &a, const bigint &b)
  {
    return !(a > b);
  }

  friend bool operator>=(const bigint &a, const bigint &b)
  {
    return !(a < b);
  }

  friend bool operator==(const bigint &a, const bigint &b)
  {
    for (int i = 0; i < 5; i++)
    {
      if (a.v[i] != b.v[i])
      {
        return 0;
      }
    }
    return 1;
  }

  friend bool operator!=(const bigint &a, const bigint &b)
  {
    return !(a == b);
  }
};

int main()
{
  bigint x;
  bigint y;

  if (x == y)
    cout << x << " is equal to " << y << "." << endl;
  if (x != y)
    cout << x << " is not equal to " << y << "." << endl;
  if (x > y)
    cout << x << " is larger than " << y << "." << endl;
  if (x >= y)
    cout << x << " is larger than or equal to " << y << "." << endl;
  if (x < y)
    cout << x << " is smaller than " << y << "." << endl;
  if (x <= y)
    cout << x << " is smaller than or equal to " << y << "." << endl;

  bigint x1(123456789);
  bigint y1(111111111);

  if (x1 == y1)
    cout << x1 << " is equal to " << y1 << "." << endl;
  if (x1 != y1)
    cout << x1 << " is not equal to " << y1 << "." << endl;
  if (x1 > y1)
    cout << x1 << " is larger than " << y1 << "." << endl;
  if (x1 >= y1)
    cout << x1 << " is larger than or equal to " << y1 << "." << endl;
  if (x1 < y1)
    cout << x1 << " is smaller than " << y1 << "." << endl;
  if (x1 <= y1)
    cout << x1 << " is smaller than or equal to " << y1 << "." << endl;

  bigint x2(123456789, 111, 111, 111, 111);
  bigint y2(111111111, 111, 111, 111, 111);

  if (x2 == y2)
    cout << x2 << " is equal to " << y2 << "." << endl;
  if (x2 != y2)
    cout << x2 << " is not equal to " << y2 << "." << endl;
  if (x2 > y2)
    cout << x2 << " is larger than " << y2 << "." << endl;
  if (x2 >= y2)
    cout << x2 << " is larger than or equal to " << y2 << "." << endl;
  if (x2 < y2)
    cout << x2 << " is smaller than " << y2 << "." << endl;
  if (x2 <= y2)
    cout << x2 << " is smaller than or equal to " << y2 << "." << endl;

  bigint x3(123456789, 12, 12);
  bigint y3(111111111, 13, 12);

  if (x3 == y3)
    cout << x3 << " is equal to " << y3 << "." << endl;
  if (x3 != y3)
    cout << x3 << " is not equal to " << y3 << "." << endl;
  if (x3 > y3)
    cout << x3 << " is larger than " << y3 << "." << endl;
  if (x3 >= y3)
    cout << x3 << " is larger than or equal to " << y3 << "." << endl;
  if (x3 < y3)
    cout << x3 << " is smaller than " << y3 << "." << endl;
  if (x3 <= y3)
    cout << x3 << " is smaller than or equal to " << y3 << "." << endl;

  // bigint x4(999999999, 999999999, 999999999, 20);

  // cout << x4 << "+1 = " << x4 + 1 << endl;

  // bigint y4(000000000, 000000000, 000000000, 000000000, 0000000001);

  // cout << y4 << "-1 = " << y4 - 1 << endl;

  // cout << x1 + x2 + x3 + x4 - y3 + 1 << endl;

  // for (int i = 0; i < 3; i++)
  // {
  //   bigint x5, y5;
  //   cin >> x5 >> y5;
  //   cout << "x = " << x5 << endl;
  //   cout << "y = " << y5 << endl;

  //   cout << "x+y=" << x5 + y5 << endl;
  //   cout << "x-y=" << x5 - y5 << endl;
  // }

  return 0;
}