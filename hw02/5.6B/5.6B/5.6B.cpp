// This program prints a number in word form

#include <stdio.h>

int main(void)
{
	int input;
	scanf("%i", &input);

	// self-taught array syntax
	const char *wordForm[10] = { "zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine " };
	int inputArray[10];

	// store each digit of the input in an array
	int numDigits = 0;
	do
	{
		inputArray[numDigits] = input % 10;
		input /= 10;
		numDigits++;
	} while (input != 0);

	// print each digit of the array in word form
	for (int i = numDigits - 1; i >= 0; i--) {
		printf(wordForm[inputArray[i]]);
	}

	printf("\n");
	return 0;
}