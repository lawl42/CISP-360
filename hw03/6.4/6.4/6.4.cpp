#include <stdio.h>

int main(void)
{
	float input[10];
	float sum = 0;

	for (int i = 0; i < 10; ++i)
	{
		scanf("%f", &input[i]);
		sum += input[i];
	}

	printf("The average is %f.\n", sum / 10);

	return 0;
}