#include <stdio.h>

int main() {
	printf("Term\tSum\n");

	float sum = 0, term;
	for (int i = 1; i <= 20; i++) {
		term = (float)i / (i + 1);
		sum = sum + term;
		printf("%d\t%f\n", i, sum);
	}

	return 0;
}