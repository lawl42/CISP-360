// This program writes out a number in word form

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int input, manipulated = 0, checker, numberofzeroes = 0;
	bool zero = false;
	scanf("%i", &input);
	if (input % 10 == 0)
	{
		checker = input;
		zero = true;
		while (checker % 10 == 0)
		{
			numberofzeroes++;
			checker /= 10;
		}
	}

	do
	{
		manipulated = manipulated * 10 + (input % 10);
		input /= 10;
	} while (input != 0);

	do
	{
		switch (manipulated % 10)
		{
			case 0:
				printf("zero ");
				break;
			case 1:
				printf("one ");
				break;
			case 2:
				printf("two ");
				break;
			case 3:
				printf("three ");
				break;
			case 4:
				printf("four ");
				break;
			case 5:
				printf("five ");
				break;
			case 6:
				printf("six ");
				break;
			case 7:
				printf("seven ");
				break;
			case 8:
				printf("eight ");
				break;
			case 9:
				printf("nine ");
				break;
			default:
				break;
		}
		manipulated /= 10;
	} while (manipulated != 0);

	if (zero == true)
	{
		for (int i = 1; i <= numberofzeroes; i++)
			printf("zero ");
		printf("\n");
	}
	else
		printf("\n");

	return 0;
}