#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int integerVar = 100;
	float floatingVar = 331.79;
	double doubleVar = 8.44e+11;
	char charVar = 'W';

	bool boolVar = false;

	printf("integarVar = %i\n", integerVar);
	printf("floatingVar = %f\n", floatingVar);
	printf("doubleVar = %e\n", doubleVar);
	printf("charVar = %c\n", charVar);

	printf("boolVar = %u\n", boolVar);

	return 0;
}