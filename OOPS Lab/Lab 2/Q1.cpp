#include<iostream>
using namespace std;

int main()
{
	int n;

	cout << "Enter the value for n:";
	cin >> n;

	int *arr = new int[n];

	arr[0] = 0;
	arr[1] = 1;

	cout << arr[0] << " " <<arr[1]<<" ";

	for (int i = 2; i < n; i++)
	{
		arr[i] = arr[i - 1] + arr[i-2];
		cout << arr[i] << " ";
	}
	

	system("PAUSE");
	return 0;
}


