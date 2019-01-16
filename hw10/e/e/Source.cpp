// Calculate e

#include <stdio.h>

int factorial(int n) {
	if (n > 0) {
		return (n * factorial(n - 1));
	}
	else{
		return 1;
	}
}

float calculate_e(int terms) {
	printf("i fact   term     e\n");

	float e = 1.0;
	float term = 1.0;
	for (int i = 1; i <= terms; i++) {
		printf("%-2d", i);
		printf("%-7d", factorial(i));
		
		term = 1 / (float)factorial(i);
		printf("%.30f", term);

		printf(" ");
		e += term;
		printf("%.30f\n", e);
	}

	return 0;
}

int main() {
	printf("Enter number of terms: ");
	int terms;
	scanf("%d", &terms);
	
	calculate_e(terms);
	return 0;
}