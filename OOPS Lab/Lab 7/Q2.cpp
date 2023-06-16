#include <iostream>
using namespace std;

class B;
class A
{
	int number1;
	friend class B;
	friend int Sum(A &num1, B &num2);

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

	cout<<Sum(num1, num2)<<endl;	

	system("PAUSE");
	return 0;
}