#include<iostream>
using namespace std;

int main()
{
	int num1=1, num2, num3;
	int* a = &num1;
	int* b = &num2;
	int* c = &num3;

	cout << "Enter the first number:";
	cin >> *a;
	cout << "Enter the second number:";
	cin >> *b;
	cout << "Enter the third number:";
	cin >> *c;

	float aver = (*a + *b + *c) / 3;

	cout << "The average of the three numbers is:" << aver<< endl;

	system("PAUSE");
	return 0;
}
