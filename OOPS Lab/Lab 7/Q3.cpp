#include <iostream>
using namespace std;

class B;
class C;
class A
{
	int number1;
	friend class B;
	friend class C;
	friend int Sum(A &num1, B &num2);
	friend int SumNew(A &num1);

public:
	A(int n=1)
	{
		number1 = n;
	}

};

class B
{
private:
	int number2;
	friend class A;
	friend int Sum(A &num1, B &num2);

public:
	B(int n=1)
	{
		number2 = n;
	}
};

class C
{
private:
	int number3;
	friend class A;
	friend int SumNew(A &num1);

public:
	C(int n = 1)
	{
		number3 = n;
	}

	int SumNew(A &num1)
	{
		int sum = 0;

		sum = num1.number1 + number3;

		return sum;
	}

};

int Sum(A &num1, B &num2)
{
	int sum = 0;

	sum = num1.number1 + num2.number2;

	return sum;
}



int main()
{
	A num1(5);
	B num2(10);
	C num3(15);

	cout<<num3.SumNew(num1)<<endl;	

	system("PAUSE");
	return 0;
}