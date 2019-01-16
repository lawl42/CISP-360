// This program finds the triangular number of 5, 10, 15, ..., 50 with a formula

#include <stdio.h>

int main(void)
{
	for (int i = 5; i <= 50; i += 5)
		printf("%i\n", i * (i + 1) / 2);

	return 0;
}