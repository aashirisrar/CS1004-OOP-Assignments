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
    int matrixRows = 3;
    int matrixCols = 2;
    int **rowColSizeArr = new int *[matrixRows];

    for (int i = 0; i < matrixRows; i++)
    {
        rowColSizeArr[i] = new int[matrixCols];
    }

    inputFile.open("InputFile.txt");

    // Matrix One Input
    int **matrixOne = InputMatrix(inputFile, rows, cols);
    rowColSizeArr[0][0] = rows;
    rowColSizeArr[0][1] = cols;

    cout << "Matrix One:" << endl;
    OutputMatrix(matrixOne, rowColSizeArr[0][0], rowColSizeArr[0][1]);

    // Matrix Two Input
    int **matrixTwo = InputMatrix(inputFile, rows, cols);
    rowColSizeArr[1][0] = rows;
    rowColSizeArr[1][1] = cols;

    cout << "Matrix Two:" << endl;
    OutputMatrix(matrixTwo, rowColSizeArr[0][0], rowColSizeArr[0][1]);

    // Matrix Three Input
    int **matrixThree = InputMatrix(inputFile, rows, cols);
    rowColSizeArr[2][0] = rows;
    rowColSizeArr[2][1] = cols;

    cout << "Matrix Three:" << endl;
    OutputMatrix(matrixThree, rowColSizeArr[0][0], rowColSizeArr[0][1]);

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

void OutputMatrix(int **matrix, const int &ROWS, const int &COLS)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}