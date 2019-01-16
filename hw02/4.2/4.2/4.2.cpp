// This generates a table of n and n^2

#include <stdio.h>

int main(void)
{
	printf(" n      n^2\n");
	printf("---    -----\n");

	for (int i = 1; i <= 10; i++)
		printf("%2i     %i\n", i, i*i);

	return 0;
}