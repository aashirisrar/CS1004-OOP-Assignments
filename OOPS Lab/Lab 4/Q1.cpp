#include <iostream>
#include <string>
using namespace std;

class Student
{
	int rollNum;
	string name;
	long long int cnic;
	string degree;
	string address;

public:
	// Setter
	void studentRollNumSetter(int rollOfStudent)
	{
		rollNum = rollOfStudent;
	}
	void studenNameSetter(string nameOfStudent)
	{
		name = nameOfStudent;
	}
	void studentCnicSetter(long long int cnicOfStudent)
	{
		cnic = cnicOfStudent;
	}
	void studentDegreeSetter(string degreeOfStudent)
	{
		degree = degreeOfStudent;
	}
	void studentAddressSetter(string addressofStudent)
	{
		address = addressofStudent;
	}

	// Getter
	int studentRollNumGetter()
	{
		return rollNum;
	}
	string studenNameGetter()
	{
		return name;
	}
	long long int studentCnicGetter()
	{
		return cnic;
	}
	string studentDegreeGetter()
	{
		return degree;
	}
	string studentAddressGetter()
	{
		return address;
	}

	// Print
	void print()
	{
		cout << "The Roll Number of Student is: " << rollNum<<endl;
		cout << "The Name of Student is: " << name << endl;
		cout << "The CNIC of Student is: " << cnic << endl;
		cout << "The Degree of Student is: " << degree << endl;
		cout << "The Address of Student is: " << address << endl;
	}
};

int main()
{
	Student student;

	int rollNum;
	string name;
	long long int cnic;
	string degree;
	string address;

	cout << "Enter the roll number of student:";
	cin >> rollNum;

	cout << "Enter the name of student:";
	cin.ignore();
	getline(cin, name);

	cout << "Enter the CNIC of student:";
	cin >> cnic;

	cout << "Enter the degree of student:";
	cin.ignore();

	getline(cin, degree);

	cout << "Enter the address of student:";
	cin.ignore();

	getline(cin, address);

	// Calling Setter
	student.studentRollNumSetter(rollNum);
	student.studenNameSetter(name);
	student.studentCnicSetter(cnic);
	student.studentDegreeSetter(degree);
	student.studentAddressSetter(address);

	// Calling Getter
	student.studenNameGetter();
	student.studenNameGetter();
	student.studenNameGetter();
	student.studentDegreeGetter();
	student.studentAddressGetter();

	// Print
	student.print();

	system("PAUSE");
	return 0;
}