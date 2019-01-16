// This program prints the first ten factorials.

#include <stdio.h>

int main(void)
{
	for (int i = 1; i <= 10; i++)
	{
		int factorial = 1;
		
		for (int j = 1; j <= i; j++)
			factorial *= j;

		printf("%i\n", factorial);
	}

	return 0;
}