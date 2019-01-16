// Remake of 6.1.3
// Generates a the most possible Fibonacci numbers for type int

#include <stdio.h>

int main()
{
	int i1 = 0, i2 = 1, i3 = 1;

	printf("%i %i ", i1, i2);

	// for (int i = 2; i <= 46; ++i) is also possible
	while (i3 > 0)
	{
		i3 = i1 + i2;
		i1 = i2;
		i2 = i3;

		// when i3 is too large, it will turn negative
		if (i3 > 0)
			printf("%i ", i3);
	}

	printf("\n");

	return 0;
}