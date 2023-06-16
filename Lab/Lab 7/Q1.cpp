#include <iostream>
using namespace std;

class String
{
	char *str;

public:
	String()
	{
		str = new char[1024];
	}

	void Input(char *arr)
	{
		str = arr;
	}

	friend bool operator==(const String &obj1, const String &obj2)
	{
		if (strcmp(obj1.str, obj2.str) == 0)
		{
			return 1;
		}

		return 0;
	}

	~String()
	{
		str = nullptr;
	}
};

int main()
{
	String s1, s2;

	char str1[1024];
	char str2[1024];

	cout << "Enter the string 1:";
	cin>>str1;

	cout << "Enter the string 2:";
	cin >> str2;

	s1.Input(str1);
	s2.Input(str2);

	if (s1 == s2)
	{
		cout << "They are equal!";
	}
	else
	{
		cout << "They are not equal!";
	}
	
	system("PAUSE");
	return 0;
}