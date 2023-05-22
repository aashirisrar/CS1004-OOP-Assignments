#include <iostream>
#include <iomanip>
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
  friend istream &operator>>(istream &is, bigint &num)
  {
    string s;
    is >> s;

    int i = 0;
    for (int j = s.length() - 1; j >= 0; j -= 9)
    {
      int digits = 0;
      for (int k = max(0, j - 8); k <= j; ++k)
      {
        digits = digits * 10 + (s[k] - '0');
      }
      num.v[i++] = digits;
    }

    for (int j = i; j < 5; ++j)
    {
      num.v[j] = 0;
    }

    return is;
  }

  friend ostream &operator<<(ostream &os, const bigint &num)
  {
    int i = 4;
    while (i >= 0 && num.v[i] == 0)
    {
      --i;
    }

    if (i < 0)
    {
      os << "0";
      return os;
    }

    os << num.v[i];
    for (--i; i >= 0; --i)
    {
      os << setfill('0') << setw(9) << num.v[i];
    }

    return os;
  }

  friend bigint operator+(const bigint &a, const bigint &b)
  {
    bigint result;
    int carry = 0;
    for (int i = 0; i < 5; ++i)
    {
      result.v[i] = a.v[i] + b.v[i] + carry;
      carry = result.v[i] / 1000000000;
      result.v[i] %= 1000000000;
    }
    return result;
  }

  friend bigint operator-(const bigint &a, const bigint &b)
  {
    bigint result;
    int carry = 0;
    for (int i = 0; i < 5; ++i)
    {
      result.v[i] = a.v[i] - b.v[i] - carry;
      if (result.v[i] < 0)
      {
        result.v[i] += 1000000000;
        carry = 1;
      }
      else
      {
        carry = 0;
      }
    }
    return result;
  }

  friend bool operator<(const bigint &a, const bigint &b)
  {
    for (int i = 4; i >= 0; --i)
    {
      if (a.v[i] != b.v[i])
      {
        return a.v[i] < b.v[i];
      }
    }
    return false;
  }

  friend bool operator>(const bigint &a, const bigint &b)
  {
    for (int i = 4; i >= 0; --i)
    {
      if (a.v[i] != b.v[i])
      {
        return a.v[i] > b.v[i];
      }
    }
    return false;
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
    for (int i = 0; i < 5; ++i)
    {
      if (a.v[i] != b.v[i])
      {
        return false;
      }
    }
    return true;
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

  bigint x4(999999999, 999999999, 999999999, 20);

  cout << x4 << "+1 = " << x4 + 1 << endl;

  bigint y4(000000000, 000000000, 000000000, 000000000, 0000000001);

  cout << y4 << "-1 = " << y4 - 1 << endl;

  cout << x1 + x2 + x3 + x4 - y3 + 1 << endl;

  for (int i = 0; i < 3; i++)
  {
    bigint x5, y5;
    cin >> x5 >> y5;
    cout << "x = " << x5 << endl;
    cout << "y = " << y5 << endl;

    cout << "x+y=" << x5 + y5 << endl;
    cout << "x-y=" << x5 - y5 << endl;
  }

  return 0;
}
