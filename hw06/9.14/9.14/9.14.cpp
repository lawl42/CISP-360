#include <stdio.h>

void intToStr(int integer, char str[12])
{
	int i = 0, j = 0;

	if (integer < 0) {
		integer *= -1;
		str[0] = '-';
		++i, ++j;
	}

	for (i; integer != 0; ++i) {
		str[i] = (integer % 10) + '0';
		integer /= 10;
	}
	str[i] = '\0';

	for (int k = i-1; j <= i/2; ++j, --k) {
		char temp = str[j];
		str[j] = str[k];
		str[k] = temp;
	}
}

int main()
{
	char str[12];
	intToStr(-12345, str);
	printf("%s\n", str);

	intToStr(278342, str);
	printf("%s\n", str);

	intToStr(-9383, str);
	printf("%s\n", str);

	return 0;
}
