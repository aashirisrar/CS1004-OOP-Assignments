#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Matrix
{
	int rows, cols;

public:
	// Setters
	void rowSetter(int row)
	{
		rows = row;
	}
	void colSetter(int col)
	{
		cols = col;
	}

	// Getters
	int rowGetter()
	{
		return rows;
	}
	int colGetter()
	{
		return cols;
	}

	// Allocate Memory
	int **allocateMemory(int row, int col)
	{
		int **matrix = new int *[row];

		for (int i = 0; i < row; i++)
		{
			matrix[i] = new int[col];
		}

		return matrix;
	}

	// Input
	int **input(ifstream &fin, int **empty_Matrix)
	{
		char num;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				fin >> num;

				empty_Matrix[i][j] = num - 48;
			}
		}
		
		return empty_Matrix;
	}

	// Rotate Array
	int **rotateOuterLayerBy1(int **arr, int rows, int cols)
	{
		for (int i = 0; i < rows / 2; i++)
		{
			for (int j = i; j < rows - i - 1; j++)
			{
				int temp = arr[i][j];
				arr[i][j] = arr[rows - 1 - j][i];
				arr[rows - 1 - j][i] = arr[rows - 1 - i][rows - 1 - j];
				arr[rows - 1 - i][rows - 1 - j] = arr[j][rows - 1 - i];
				arr[j][rows - 1 - i] = temp;
			}
		}

		return arr;
	}

	// Display
	void display(int **matrix_filled)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << matrix_filled[i][j] << " ";
			}
			cout << endl;
		}
	}

};

int main()
{
	int rows, cols;
	Matrix matrix;
	ifstream myFile;

	cout << "Enter the number of rows:";
	cin >> rows;

	cout << "Enter the number of columns:";
	cin >> cols;

	matrix.rowSetter(rows);
	matrix.colSetter(cols);

	matrix.rowGetter();
	matrix.colGetter();

	myFile.open("file.txt");

	int **emptyMatrix = matrix.allocateMemory(rows, cols);

	// Matrix Input
	int **filledMatrix = matrix.input(myFile, emptyMatrix);

	// Call rotateOuterLayerBy1 function
	int **rotatedMatrix = matrix.rotateOuterLayerBy1(filledMatrix, rows, cols);

	// Display 
	cout << "The rotated matrix is:" << endl;
	matrix.display(rotatedMatrix);

	// Closing File
	myFile.close();

	// Deallocation
	// Empty Matrix
	for (int i = 0; i < rows; i++)
	{
		delete[] emptyMatrix[i];
		emptyMatrix[i] = 0;
	}
	delete[] emptyMatrix;
	emptyMatrix = 0;

	system("PAUSE");
	return 0;
}

