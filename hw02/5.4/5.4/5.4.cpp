// Printing calculator

#include <stdio.h>

int main(void)
{
	char op;
	float num, end = 0;
	printf("Begin Calculations\n");

	do
	{
		scanf("%f %c", &num, &op);
		switch (op)
		{
			case '+':
				end += num;
				printf("= %f\n", end);
				break;
			case '-':
				end -= num;
				printf("= %f\n", end);
				break;
			case '*':
				end *= num;
				printf("= %f\n", end);
				break;
			case '/':
				if (num == 0)
					printf("Can't divide by zero.\n");
				else {
					end /= num;
					printf("= %f\n", end);
				}
				break;
			case 'S':
				end = (float)num;
				printf("= %f\n", end);
				break;
			case 'E':
				printf("End of Calculations.\n");
				break;
			default:
				printf("Invalid Operation.\n");
				break;
		}
	} while (op != 'E');

	return 0;
}