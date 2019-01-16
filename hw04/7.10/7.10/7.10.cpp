#include <stdio.h>

bool prime(int num) {
	if (num == 1)
		return false;
	for (int i = 2; i < num; ++i)
		if (num % i == 0)
			return false;
	return true;
}

int main(void)
{
	int num;
	scanf("%i", &num);

	if (prime(num))
		printf("%i is prime.\n", num);
	else
		printf("%i is not prime.\n", num);

	return 0;
}