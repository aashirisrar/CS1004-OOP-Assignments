#include <iostream>
#include <cstring>
using namespace std;

class Student;
class Person;
class Graduate;

class Person
{
protected:
	int ID;
	char name[50];
	int age;

public:
	Person(int id = 0, char nameSt[50]= "", int ageSt = 0)
	{
		cout << "In constructor of class Person" << endl;

		ID = id;
		strcpy_s(name, nameSt);
		age = ageSt;
	}

	void Print()
	{
		cout << name << endl;
	}

	~Person()
	{
		cout << "In destructor of class Person" << endl;
	}
};

class Student : public Person
{
protected:
	char rollNo[50];
	float cgpa;

public:
	Student()
	{
		cout << "In constructor of class student" << endl;
	}

	void Input(char rollNum[50], float cgpaSt)
	{
		strcpy_s(rollNo, rollNum);
		cgpa = cgpaSt;
	}

	void Print()
	{
		cout << name << " is " << age << " years old, his cgpa is " << cgpa << endl;
	}

	~Student()
	{
		cout << "In destructor of class student" << endl;
	}
};


class Undergraduate : public Student
{
	char fyp_name[50];

public:
	Undergraduate(int id, char namePer[50], int ageSt, char rollNoSt[50], float cgpaSt, char fyp_name[50])
	{
		ID = id;
		strcpy_s(name , namePer);
		age = ageSt;
		strcpy_s(rollNo, rollNoSt);
		cgpa = cgpaSt;
		strcpy_s(this->fyp_name, fyp_name);

		cout << "In constructor of class undergraduate" << endl;
	}

	void Input(char nameFYP[50])
	{
		strcpy_s(fyp_name, nameFYP);
	}

	void print()
	{
		cout << name << " is an undergraduate student, his cgpa is " << cgpa << " and his final year project is titled: " << fyp_name << endl;
	}

	~Undergraduate()
	{
		cout << "In destructor of class undergraduate" << endl;

	}
};

class Graduate : public Student
{
	char thesisTopic[50];
	char supName[50];

public:
	Graduate(int id, char namePer[50], int ageSt, char rollNoSt[50], float cgpaSt, char thesisTopic[50], char supName[50])
	{
		ID = id;
		strcpy_s(name, namePer);
		age = ageSt;
		strcpy_s(rollNo, rollNoSt);
		cgpa = cgpaSt;
		strcpy_s(this->thesisTopic, thesisTopic);
		strcpy_s(this->supName, supName);

		cout << "In constructor of class Graduate" << endl;
	}

	void Input(char thesis[50], char sup[50])
	{
		strcpy_s(thesisTopic, thesis);
		strcpy_s(supName, sup);
	}

	void print()
	{
		cout << name << " is a graduate student, his cgpa is " << cgpa <<" and his thesis topic is "<< thesisTopic<<" under supervision of "<< supName << endl;
	}

	~Graduate()
	{
		cout << "In destructor of class Graduate" << endl;

	}
};



int main()
{
	Student * s = new Undergraduate(1, "Ted", 22, "14L-4171", 3.91, "The Event Locator");
	Student * s2 = new Graduate(2, "Arnold", 25, "17L-6171", 3.01,"Distributed Algorithms" ,"Dr Kashif Zafar");

	s -> Print();
	s -> Input("22-6597", 1.9);
	s2-> Print();
	s2 -> Print();
	s -> Print();
	s2 -> Print();

	system("PAUSE");
	return 0;
}