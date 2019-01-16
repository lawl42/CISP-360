// This program prints a number in word form

#include <stdio.h>

int main(void)
{
	int input, manipulated = 0, checker, trailingZeroes = 0;
	scanf("%i", &input);
	checker = input;
	while (checker % 10 == 0)
	{
		trailingZeroes++;
		checker /= 10;
	}

	do
	{
		manipulated = manipulated * 10 + (input % 10);
		input /= 10;
	} while (input != 0);

	const char *digits[10] = { "zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine " };
	do
	{
		printf(digits[manipulated % 10]);
		manipulated /= 10;
	} while (manipulated != 0);

	if (trailingZeroes > 0)
	{
		for (int i = 1; i <= trailingZeroes; i++)
			printf("zero ");
		printf("\n");
	}
	else
		printf("\n");

	return 0;
}