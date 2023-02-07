#include<iostream>
using namespace std;

int main()
{
	int a = 20;
	int* b = &a;

	cout << "The value of a using b:" <<*b << endl;

	int** c = &b;

	cout <<"The value of a using c:"<<**c << endl;

	system("PAUSE");
	return 0;
}