#include<iostream>
using namespace std;

void copyArray(int *arr, int *&arr1, int size);
void reduceArray(int * arr, int *&arr1, int size);

int main()
{
	int size;

	cout << "Enter the size of array:";
	cin >> size;

	int *arr = new int[size];
	int *arr1 = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the value in the index " << i << ": ";
		cin >> arr[i];
	}
	
	copyArray(arr, arr1, size);

	reduceArray(arr, arr1, size);

	system("PAUSE");
	return 0;
}

void copyArray(int *arr, int *&arr1, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr[i];
	}
}

void reduceArray(int * arr, int *&arr1, int size)
{
	int sizeOfReducedArray;

	cout << "Enter the size of the reduced array:";
	cin >> sizeOfReducedArray;

	cout << "Array after reduction is:" << endl;
	for (int i = size - sizeOfReducedArray; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}
