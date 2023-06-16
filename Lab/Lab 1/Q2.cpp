#include<iostream>
using namespace std;

int SUM(int &a, int &b)
{
	int sum;
	sum = a + b;
	return sum;
}

int main()
{
	int a, b;

	cout << "Enter the first number:";
	cin >> a;

	cout << "Enter the second number:";
	cin >> b;

	int sum = SUM(a, b);

	cout << "The sum is " << sum<<endl;

	system("PAUSE");
	return 0;
}
