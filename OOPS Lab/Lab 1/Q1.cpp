#include<iostream>
using namespace std;

int main()
{
	int x = 3;
	int y = 4;
	int* p;
	int* q;

	p = &x;
	q = &y;

	cout << "The value of x:" << x <<endl;
	cout << "The value of p:" << p << endl;
	cout << "The value of *p:" << *p << endl;
	cout << "The value of &p:" << &p << endl;
	cout << "The value of &x:" << &x << endl<<endl;

	cout << "The value of y:" << y << endl;
	cout << "The value of q:" << q << endl;
	cout << "The value of *q:" << *q << endl;
	cout << "The value of &q:" << &q << endl;
	cout << "The value of &y:" << &y << endl;

	system("PAUSE");
	return 0;
}

