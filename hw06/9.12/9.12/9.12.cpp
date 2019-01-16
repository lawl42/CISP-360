#include <stdio.h>

float strToFloat(const char string[])
{
	int i = 0;
	float floatVal, result = 0;
	bool negativity = false;

	if (string[i] == '-') {
		negativity = true;
		++i;
	}

	while (string[i] >= '0' && string[i] <= '9') {
		floatVal = string[i] - '0';
		result = result * 10 + floatVal;
		++i;
	}

	if (string[i] == '.') {
		++i;
		int divides = 1;
		for (i; string[i] >= '0' && string[i] <= '9'; ++i) {
			floatVal = string[i] - '0';
			for (int j = 0; j < divides; ++j) {
				floatVal /= 10;
			}
			result += floatVal;
			++divides;
		}
	}

	if (negativity) return -result;
	else return result;
}

int main()
{
	printf("%.4f\n", strToFloat("-867.6921"));
	printf("%.5f\n", strToFloat("1.23456"));
	printf("%.0f\n", strToFloat("-837"));

	return 0;
}