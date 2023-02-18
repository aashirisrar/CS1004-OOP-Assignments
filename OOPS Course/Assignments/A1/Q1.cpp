#include <iostream>
#include <fstream>
using namespace std;

int **InputMatrix(ifstream &fin, int &rows, int &cols);
void OutputMatrix(int **matrix, const int &ROWS, const int &COLS);
int **AddMatrix(int **matrixA, int **matrixB, const int &ROWS, const int &COLS);
int **TransposeMatrix(int **matrix, const int &ROWS, const int &COLS);
bool IsSymmetric(int **matrix, const int &ROWS, const int &COLS);
void InterchangeRows(int **matrix, const int &ROWS, const int &COLS);
void InterchangeRows(int *&row1, int *&row2);

int main()
{
    ifstream inputFile;
    int rows = 0;
    int cols = 0;
    int matrixRows = 1;
    int matrixCols = 2;
    int **rowColSizeArr = new int *[matrixRows];

    for (int i = 0; i < matrixRows; i++)
    {
        rowColSizeArr[i] = new int[matrixCols];
    }

    inputFile.open("InputFile.txt");

    int **matrixOne = InputMatrix(inputFile, rows, cols);
    matrixRows++;
    rowColSizeArr[0][0] = rows;
    rowColSizeArr[0][1] = cols;

    for (int i = 0; i < rowColSizeArr[0][0]; i++)
    {
        for (int j = 0; j < rowColSizeArr[0][1]; j++)
        {
            cout << matrixOne[i][j] << " ";
        }
        cout << endl;
    }

    int **matrixTwo = InputMatrix(inputFile, rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrixTwo[i][j] << " ";
        }
        cout << endl;
    }

    int **matrixThree = InputMatrix(inputFile, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrixThree[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int **InputMatrix(ifstream &fin, int &rows, int &cols)
{
    int **inputArr = new int *[rows];
    char arr[100] = {};
    while (!fin.eof())
    {
        fin.getline(arr, 100);

        if (arr[0] != '/' && arr[0] != '\000')
        {
            rows = arr[0] - 48;
            cols = arr[2] - 48;

            for (int i = 0; i < rows; i++)
            {
                inputArr[i] = new int[cols];
            }

            int k = 0;
            for (int i = 0; i < rows; i++)
            {
                fin.getline(arr, 100);
                k = 0;
                for (int j = 0; j < cols; j++)
                {
                    inputArr[i][j] = arr[k] - 48;
                    k += 2;
                }
            }
            return inputArr;
        }
    }
    return 0;
}