#include<iostream>
using namespace std;

void myTokenizer(char *data, char **list_tokens, char delimiter, int total)
{
	int j = 0;
	int m = 0, n = 0;
	int count = 0;

	for (int i = 0; i < total; i++)
	{
		n = 0;

		for (j = j; data[j] != delimiter; j++)
		{
			count++;
			list_tokens[m][n++] = data[j];
		}

		
		j++;
		list_tokens[m][n++] = '\0';
		m++;		
	}

	
}

int main()
{
	char *arr = new char[];
	char delimiter;
	int count = 0;

	cout << "Enter a string:";
	cin >> arr;

	cout << "Enter the delimiter:";
	cin >> delimiter;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == delimiter)
		{
			count++;
		}
	}

	// creating array of 50x50
	char **tokens = new char *[10];
	for (int i = 0; i < 10; i++)
	{
		tokens[i] = new char[count];
	}

	myTokenizer(arr, tokens, delimiter, count);

	for (int i = 0; i <= count; i++)
	{
		cout << tokens[i]<<endl;
	}

	system("PAUSE");
	return 0;
}