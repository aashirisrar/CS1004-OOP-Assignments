#include <iostream>
using namespace std;

class Faculty
{

public:
	virtual void Print() = 0;
};

class Administrator : virtual public Faculty
{

public:
	void Print()
	{
		cout << "Administrator" << endl;
	}
};

class Teacher : virtual public Faculty
{

public:
	void Print()
	{
		cout << "Teacher" << endl;
	}
};

class AdministratorTeacher : public Administrator, public Teacher
{
public:
	void Print()
	{
		cout << "Administrator Teacher" << endl;
	}
};

int main()
{
	Faculty *faculty[3];
	Administrator adminstrator;
	Teacher teacher;
	AdministratorTeacher adminstratorTeacher;

	faculty[0] = &adminstrator;
	faculty[1] = &teacher;
	faculty[2] = &adminstratorTeacher;

	for (int i = 0; i < 3; i++)
	{
		(*faculty[i]).Print();
	}

	teacher.Print();
	adminstrator.Print();
	
	// Error : ambiguous conversions from 'AdministratorTeacher *' to 'Faculty *'

	
	system("PAUSE");
	return 0;
}