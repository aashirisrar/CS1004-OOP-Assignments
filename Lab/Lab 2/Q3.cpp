#include<iostream>
using namespace std;

void Input(int *&iarr, int &size);
void Reverse(int *iarr, int size);
void Output(int *iarr, int size);

int main()
{
	int size = 5;
	int *arr = new int[size];

	Input(arr, size);
	Reverse(arr, size);
	Output(arr, size);

	system("PAUSE");
	return 0;
}

void Input(int *&iarr, int &size)
{
	bool broken = false;
	int i=0;
	int count = 0;

	while(!broken)
	{
		for (i=i; i < size; i++)
		{
			cout << "Enter the value for the index " << i << ": ";
			cin >> iarr[i];
			count++;

			if (iarr[i] == -1)
			{
				broken = true;
				break;
			}
		}

		if (!broken)
		{
			size *= 2;
			cout << "Array size:" << size << endl;
		}
	}

	size = count-2;
}

void Reverse(int *iarr, int size)
{
	for (int i = 0; i < size/2; i++)
	{		
		int temp = iarr[i];
		iarr[i] = iarr[size-i];
		iarr[size-i] = temp;
	}

}

void Output(int *iarr, int size)
{
	for (int i = 0; i <= size; i++)
	{
		cout << iarr[i] << endl;
	}
}

