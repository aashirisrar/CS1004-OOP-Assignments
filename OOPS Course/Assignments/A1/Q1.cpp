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

    /* Matrix Input */
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
    OutputMatrix(matrixTwo, rowColSizeArr[1][0], rowColSizeArr[1][1]);

    // Matrix Three Input
    int **matrixThree = InputMatrix(inputFile, rows, cols);
    rowColSizeArr[2][0] = rows;
    rowColSizeArr[2][1] = cols;

    cout << "Matrix Three:" << endl;
    OutputMatrix(matrixThree, rowColSizeArr[2][0], rowColSizeArr[2][1]);

    /* Adding Matrices */
    // A+B
    if (rowColSizeArr[0][0] == rowColSizeArr[1][0] && rowColSizeArr[0][1] == rowColSizeArr[1][1])
    {
        int **addedMatrixAB = AddMatrix(matrixOne, matrixTwo, rowColSizeArr[0][0], rowColSizeArr[0][1]);
        cout << "Added Matrix (A+B):" << endl;
        OutputMatrix(addedMatrixAB, rowColSizeArr[0][0], rowColSizeArr[0][1]);

        // Deallocating Added Matrix A+B
        for (int i = 0; i < rowColSizeArr[0][0]; i++)
        {
            delete[] addedMatrixAB[i];
            addedMatrixAB[i] = 0;
        }
        delete[] addedMatrixAB;
        addedMatrixAB = 0;
    }
    else
    {
        cout << "Addition is not possible!";
    }

    // A+C
    if (rowColSizeArr[0][0] == rowColSizeArr[2][0] && rowColSizeArr[1][1] == rowColSizeArr[2][1])
    {
        int **addedMatrixAC = AddMatrix(matrixOne, matrixTwo, rowColSizeArr[0][0], rowColSizeArr[0][1]);
        cout << "Added Matrix (A+C):" << endl;
        OutputMatrix(addedMatrixAC, rowColSizeArr[2][0], rowColSizeArr[2][1]);
    }
    else
    {
        cout << "A+C= " << endl;
        cout << "Addition is not possible" << endl;
    }

    /* Transpose of Matrix */
    // A
    int **transposeOfA = TransposeMatrix(matrixOne, rowColSizeArr[0][0], rowColSizeArr[0][1]);
    cout << "Transpose of A:" << endl;
    OutputMatrix(transposeOfA, rowColSizeArr[0][0], rowColSizeArr[0][1]);

    // B
    int **transposeOfB = TransposeMatrix(matrixTwo, rowColSizeArr[1][0], rowColSizeArr[1][1]);
    cout << "Transpose of B:" << endl;
    OutputMatrix(transposeOfB, rowColSizeArr[1][0], rowColSizeArr[1][1]);

    // C
    int **transposeOfC = TransposeMatrix(matrixThree, rowColSizeArr[2][0], rowColSizeArr[2][1]);
    cout << "Transpose of C:" << endl;
    OutputMatrix(transposeOfC, rowColSizeArr[2][1], rowColSizeArr[2][0]);

    /* SYMMETRIC */
    // A
    bool isSymmetricA = IsSymmetric(transposeOfA, rowColSizeArr[0][0], rowColSizeArr[0][1]);
    if (isSymmetricA)
    {
        cout << "Matrix A is symmetric" << endl;
    }
    else
    {
        cout << "Matrix A is NOT symmetric" << endl;
    }

    // B
    bool isSymmetricB = IsSymmetric(transposeOfB, rowColSizeArr[1][0], rowColSizeArr[1][1]);
    if (isSymmetricB)
    {
        cout << "Matrix B is symmetric" << endl;
    }
    else
    {
        cout << "Matrix B is NOT symmetric" << endl;
    }

    // C
    cout << "Matrix C is NOT symmetric as its row and column sizes are not same!" << endl;

    /* Interchanging Rows */
    InterchangeRows(matrixOne, rowColSizeArr[0][0], rowColSizeArr[0][1]);
    cout << "After interchanging matrix A: " << endl;
    OutputMatrix(matrixOne, rowColSizeArr[0][0], rowColSizeArr[0][1]);

    /* CLOSING FILE */
    inputFile.close();

    /* DEALLOCATION */
    // Matrix One
    for (int i = 0; i < rowColSizeArr[0][0]; i++)
    {
        delete[] matrixOne[i];
        matrixOne[i] = 0;
    }
    delete[] matrixOne;
    matrixOne = 0;

    // Matrix Two
    for (int i = 0; i < rowColSizeArr[1][0]; i++)
    {
        delete[] matrixTwo[i];
        matrixTwo[i] = 0;
    }
    delete[] matrixTwo;
    matrixTwo = 0;
    // Matrix Three

    for (int i = 0; i < rowColSizeArr[2][0]; i++)
    {
        delete[] matrixThree[i];
        matrixThree[i] = 0;
    }
    delete[] matrixThree;
    matrixThree = 0;

    // Transpose Matrix A
    for (int i = 0; i < rowColSizeArr[0][0]; i++)
    {
        delete[] transposeOfA[i];
        transposeOfA[i] = 0;
    }
    delete[] transposeOfA;
    transposeOfA = 0;

    // Transpose Matrix B
    for (int i = 0; i < rowColSizeArr[1][0]; i++)
    {
        delete[] transposeOfB[i];
        transposeOfB[i] = 0;
    }
    delete[] transposeOfB;
    transposeOfB = 0;

    // Transpose Matrix C
    for (int i = 0; i < rowColSizeArr[2][1]; i++)
    {
        delete[] transposeOfC[i];
        transposeOfC[i] = 0;
    }
    delete[] transposeOfC;
    transposeOfC = 0;

    // Row Column Size Array
    for (int i = 0; i < matrixRows; i++)
    {
        delete[] rowColSizeArr[i];
        rowColSizeArr[i] = 0;
    }
    delete[] rowColSizeArr;
    rowColSizeArr = 0;

    return 0;
}

int **InputMatrix(ifstream &fin, int &rows, int &cols)
{
    int **inputArr = nullptr;
    char arr[100] = {};
    while (!fin.eof())
    {
        fin.getline(arr, 100);

        if (arr[0] != '/' && arr[0] != '\0')
        {
            rows = arr[0] - 48;
            cols = arr[2] - 48;

            inputArr = new int *[rows];

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

                    if (arr[k + 1] == ' ' || arr[k + 1] == '\000')
                    {
                        k += 2;
                    }
                    else
                    {
                        int count = 0;
                        int num = 0;

                        for (int l = k; arr[l] != ' ' && arr[l] != '\000'; l++)
                        {
                            int temp = arr[l] - 48;
                            num = (num * 10) + temp;
                            count++;
                        }
                        inputArr[i][j] = num;
                        k += count;
                    }
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
        int *ptr = *(matrix + i);
        for (int j = 0; j < COLS; j++)
        {
            cout << *ptr << " ";
            ptr++;
        }
        cout << endl;
    }
    cout << endl;
}

int **AddMatrix(int **matrixA, int **matrixB, const int &ROWS, const int &COLS)
{
    int **addedMatrix = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        addedMatrix[i] = new int[COLS];
    }

    for (int i = 0; i < ROWS; i++)
    {
        int *ptr1 = *(matrixA + i);
        int *ptr2 = *(matrixB + i);
        int *ptr3 = *(addedMatrix + i);

        for (int j = 0; j < COLS; j++)
        {
            *ptr3 = *ptr1 + *ptr2;
            ptr1++;
            ptr2++;
            ptr3++;
        }
    }
    return addedMatrix;
}

int **TransposeMatrix(int **matrix, const int &ROWS, const int &COLS)
{
    if (ROWS == COLS)
    {
        int **transposeMatrix = new int *[ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            transposeMatrix[i] = new int[COLS];
        }

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                transposeMatrix[i][j] = matrix[j][i];
            }
        }
        return transposeMatrix;
    }
    else
    {
        int **transposeMatrix = new int *[COLS];
        for (int i = 0; i < COLS; i++)
        {
            transposeMatrix[i] = new int[ROWS];
        }

        for (int i = 0; i < COLS; i++)
        {
            for (int j = 0; j < ROWS; j++)
            {
                transposeMatrix[i][j] = matrix[j][i];
            }
        }
        return transposeMatrix;
    }
    return 0;
}

bool IsSymmetric(int **matrix, const int &ROWS, const int &COLS)
{
    int **transposeOfTransposeMatrix = new int *[ROWS];
    for (int i = 0; i < ROWS; i++)
    {
        transposeOfTransposeMatrix[i] = new int[COLS];
    }

    transposeOfTransposeMatrix = TransposeMatrix(matrix, ROWS, COLS);

    int count = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (transposeOfTransposeMatrix[i][j] == matrix[i][j])
            {
                count++;
            }
        }
    }

    if (count == ROWS * COLS)
    {
        return 1;
    }

    return 0;
}

void InterchangeRows(int **matrix, const int &ROWS, const int &COLS)
{
    int row1;
    int row2;

    cout << "row1: ";
    cin >> row1;
    row1--;

    cout << "row2: ";
    cin >> row2;
    row2--;

    if (row1 >= 0 && row2 < ROWS)
    {
        InterchangeRows(matrix[row1], matrix[row2]);
    }
    else
    {
        cout << "Error! The row number must be between 0 and " << ROWS + 1 << endl;
        exit(0);
    }
}

void InterchangeRows(int *&row1, int *&row2)
{
    int *temp = row1;
    row1 = row2;
    row2 = temp;
}
