// Divides two integers with three decimal accuracy

#include <stdio.h>

int main(void)
{
	int i1, i2;
	scanf("%i %i", &i1, &i2);

	if (i2 == 0)
		printf("Can't divide by zero.\n");
	else
		printf("%.3f\n", (float)i1 / i2);
}