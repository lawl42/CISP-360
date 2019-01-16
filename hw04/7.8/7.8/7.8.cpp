#include <stdio.h>

// calculate absolute value
float  absoluteValue(float x)
{
	if (x < 0)
		x = -x;
	return (x);
}

// calculate square root
float  squareRoot(float x)
{
	const float  epsilon = .00001;
	float        guess = 1.0;

	while (absoluteValue(guess * guess - x) >= epsilon)
		guess = (x / guess + guess) / 2.0;

	return guess;
}

// use quadratic formula
void quadraticFormula(float a, float b, float c)
{
	float discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0) {
		printf("The roots are imaginary.\n");
	} 
	else if (discriminant == 0) {
		float x = (-b + squareRoot(discriminant)) / (2 * a);
		printf("The root is %.2f.\n", x);
	}
	else {
		float x1 = (-b + squareRoot(discriminant)) / (2 * a);
		float x2 = (-b - squareRoot(discriminant)) / (2 * a);
		printf("The roots are %.2f and %.2f.\n", x1, x2);
	}
}
int main(void)
{
	float a, b, c;
	printf("a: ");
	scanf("%f", &a);
	printf("b: ");
	scanf("%f", &b);
	printf("c: ");
	scanf("%f", &c);

	quadraticFormula(a, b, c);

	return 0;
}