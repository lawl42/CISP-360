// Prints the primes up to n

#include <stdio.h>

int main()
{
	// create array
	const int n = 150;
	int integers[n];
	for (int i = 2; i <= n; i++)
		integers[i - 1] = i;
	
	// loop through array
	for (int i = 2; i <= n; i++)
	{
		// print primes
		if (integers[i - 1] != 1)
		{
			printf("%i ", integers[i - 1]);

			// "cross off" multiples of the primes
			for (int j = 2; (i * j) - 1 < n; j++)
				integers[(i * j) - 1] = 1;
		}
	}
	
	return 0;
}