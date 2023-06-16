#include <iostream>
using namespace std;

class Student
{
    int size;
    int *marks;

public:
    Student()
    {
        marks = nullptr;
        size = 0;
    }

    Student(int *arr, int sizeOfArr)
    {
        size = sizeOfArr;
        marks = new int[size];

        // deep copy
        for (int i = 0; i < size; i++)
        {
            marks[i] = arr[i];
        }
    }

    ~Student()
    {
        delete[] marks;
        marks = nullptr;
    }

    void ScaleUp()
    {
        for (int i = 0; i < size; i++)
        {
            if (marks[i] + 5 < 100 && marks[i] > 45)
            {
                marks[i] += 5;
            }
        }
    }

    void PrintInfo()
    {
        for (int i = 0; i < size; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int arr[] = {46, 2, 94, 99, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    Student Aashir(arr, size);

    cout << "Marks before scaling up:" << endl;
    Aashir.PrintInfo();

    Aashir.ScaleUp();

    cout << "\nMarks after scaling up:" << endl;
    Aashir.PrintInfo();

    return 0;
}
