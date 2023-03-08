#include<iostream>
using namespace std;

int **AllocateMemory(int &rows, int &cols);
void InputMatrix(int **matrix, const int rows, const int cols);
void DisplayMatrix(int **matrix, const int &rows, const int &cols);
int *maxCol(int **matrix, const int &rows, const int &cols);
void DeallocateMemory(int** matrix, const int &rows); 
int **concat_table(int **table1, int **table2, int row1, int col1, int row2, int col2,	bool axis);

int main()
{
	//int rows, cols;

	////take input from user for rows and cols
	//int ** matrix = AllocateMemory(rows, cols);

	//InputMatrix(matrix, rows, cols);

	//DisplayMatrix(matrix, rows, cols);

	//int * maxColValues = maxCol(matrix, rows, cols);

	//cout << "The maximum values in each column are: ";

	//for (int i = 0; i < cols; i++)
	//{
	//	cout << *(maxColValues + i) << ", ";
	//}
	//cout<<endl;

	//DeallocateMemory(matrix, rows);

	int row1, col1;

	//take input from user for rows and cols
	int **table1 = AllocateMemory(row1, col1);

	InputMatrix(table1, row1, col1);

	int row2, col2;


		//take input from user for rows and cols
		int **table2 = AllocateMemory(row2, col2);

		InputMatrix(table2, row2, col2);

	if (row1 == row2 && col1 == col2)
	{
		bool axis;

		cout << "Enter the axis(0 for x and 1 for y):";
		cin >> axis;

		// before calling concat_table check some conditions of rows and cols
		int **result = concat_table(table1, table2, row1, col1, row2, col2, axis);	
		cout << endl;

		DeallocateMemory(result, row1);
	}
	else
	{
		cout << "Enter the same row and column size for both the arrays!" << endl;
	}
	

	system("PAUSE");
	return 0;
}

int** AllocateMemory(int &rows, int &cols)
{
	cout << "Enter the row size:";
	cin >> rows;
	
	cout << "Enter the column size:";
	cin >> cols;

	int **newMatrix = new int *[rows];

	for (int i = 0; i < rows; i++)
	{
		newMatrix[i] = new int[cols];
	}

	return newMatrix;
}


void InputMatrix(int **matrix, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter the element in the " << i << " row and " << " column " << j<<":";
			cin >> matrix[i][j];
		}
	}
}


void DisplayMatrix(int **matrix, const int &rows, const int &cols)
{
	cout << "The matrix is:" << endl;

	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
}

int *maxCol(int **matrix, const int &rows, const int &cols)
{
	int *arr = new int[rows];
	int k = 0;

	for (int i = 0; i < rows; i++)
	{
		int max = 0;
		for (int j = 0; j < cols; j++)
		{
			if (matrix[j][i] > max)
			{
				max = matrix[j][i];
			}
		}
		arr[k++] = max;
	}

	return arr;
}

void DeallocateMemory(int** matrix, const int &rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete [] matrix[i];
		matrix[i] = 0;
	}

	delete[] matrix;
	matrix = 0;
}

int **concat_table(int **table1, int **table2, int row1, int col1, int row2, int col2, bool axis)
{
	int m = 0, n = 0;
	int **concatArr = new int *[row1+row2];
	for (int i = 0; i < row1+row2; i++)
	{
		concatArr[i] = new int[col1 + col2];
	};

	if (axis)
	{
		for (int i = 0; i < row1; i++)
		{
			n = 0;
			for (int j = 0; j < col1; j++)
			{
				concatArr[i][j] = table1[m][n++];
			}
			m++;
		}

		m = 0, n = 0;

		for (int i = row1; i < row1 + row2; i++)
		{
			n = 0;
			for (int j = 0; j < col1; j++)
			{
				concatArr[i][j] = table2[m][n++];
			}
			m++;
		}

		DisplayMatrix(concatArr, col1, row1+row2);

	}
	else
	{
		// x axis
		for (int i = 0; i < row1; i++)
		{
			n = 0;
			for (int j = 0; j < col1; j++)
			{
				concatArr[i][j] = table1[m][n++];
			}
			m++;
		}

		m = 0, n = 0;

		for (int i = 0; i < row1; i++)
		{
			n = 0;
			for (int j = col1; j < col1 + col2; j++)
			{
				concatArr[i][j] = table2[m][n++];
			}
			m++;
		}

		DisplayMatrix(concatArr, row1 + row2, col1);
	}

	return concatArr;
}