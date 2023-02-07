#include<iostream>
using namespace std;

int main()
{
	float InArr[10];
	float ResArr[9];

	float const * myptr = InArr;

	for (int i = 0; i < 10; i++)
	{
		ResArr[i] = InArr[i] + InArr[i + 1];
	}

	myptr = ResArr;

	system("PAUSE");
	return 0;
}

