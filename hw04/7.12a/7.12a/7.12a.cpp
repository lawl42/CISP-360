#include <stdio.h>

void transposeMatrix(int matrix[4][5], int transposed[5][4])
{
	int  row, column;
	for (row = 0; row < 4; ++row)
		for (column = 0; column < 5; ++column)
			transposed[column][row] = matrix[row][column];
}

void  displayMatrix(int  matrix[5][4])
{
	int   row, column;

	for (row = 0; row < 5; ++row) {
		for (column = 0; column < 4; ++column)
			printf("%5i", matrix[row][column]);

		printf("\n");
	}
}

int main(void)
{
	int   matrix[4][5] =
	{
		{ 7, 16, 55, 13, 12 },
		{ 12, 10, 52, 0, 7 },
		{ -2, 1, 2, 4, 9 },
		{5, -10, 3, 12, 34}
	};
	int transposed[5][4];

	transposeMatrix(matrix, transposed);
	displayMatrix(transposed);

	return 0;
}