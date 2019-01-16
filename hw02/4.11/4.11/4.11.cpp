// This program finds the sum of the digits of a user-inputted integer

#include <stdio.h>

int main(void)
{
	int input;
	scanf("%i", &input);

	int sum = 0;
	while (input != 0)
	{
		sum += input % 10;
		input /= 10;
	}

	printf("%i\n", sum);

	return 0;
}