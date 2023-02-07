#include<iostream>
using namespace std;

int main()
{
	int size = 5;
	float *arr = new float[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the element in index " << i<<": ";
		cin >> arr[i];
	}

	float max = 0;

	// second largest first occurence in array
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	float secondMax = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < max && arr[i] > secondMax)
		{
			secondMax = arr[i];
		}
	}

	cout <<"Max:"<< max<<endl;
	cout << "Second Max:" << secondMax<<endl;

	system("PAUSE");
	return 0;
}

