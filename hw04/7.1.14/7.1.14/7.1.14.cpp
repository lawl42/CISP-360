#include <stdio.h>

void  scalarMultiply(int nRows, int nCols, int * matrix, int  scalar)
{
	int  row, column;

	for (row = 0; row < nRows; ++row)
		for (column = 0; column < nCols; ++column)
			*(matrix + nCols * row + column) *= scalar;
}

void  displayMatrix(int nRows, int nCols, int * matrix)
{
	int   row, column;

	for (row = 0; row < nRows; ++row) {
		for (column = 0; column < nCols; ++column)
			printf("%5i", *(matrix + nCols * row + column));

		printf("\n");
	}
}

int main(void)
{
	int sampleMatrix[3][5] =
	{
		{ 7, 16, 55, 13, 12},
		{ 12, 10, 52, 0, 7},
		{ -2, 1, 2, 4, 9}
	};

	printf("Original matrix:\n");
	displayMatrix(3, 5, (int *)sampleMatrix);

	scalarMultiply(3, 5, (int *)sampleMatrix, 2);
	printf("\nMultiplied by 2:\n");
	displayMatrix(3, 5, (int *)sampleMatrix);

	scalarMultiply(3, 5, (int *)sampleMatrix, -1);
	printf("\nThen multiplied by -1:\n");
	displayMatrix(3, 5, (int *)sampleMatrix);

	return 0;
}