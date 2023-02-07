#include<iostream>
using namespace std;

void Incrementer()
{
	int arr[10] = { 3 };

	int *x = arr;

	for (int i = 0; i < 10; i++)
	{
		cout << *x<<endl;
		*x += 3;
	}
}

int main()
{
	Incrementer();

	system("PAUSE");
	return 0;
}

