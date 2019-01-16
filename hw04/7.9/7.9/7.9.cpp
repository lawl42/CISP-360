#include <stdio.h>

int  gcd(int u, int v)
{
	int  temp;

	while (v != 0) {
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

int lcm(int u, int v)
{
	if (u >= 0 && v >= 0)
		return u * v / gcd(u, v);
	else
		return -1;
}

int main(void)
{
	int  result;
	int i1, i2;
	scanf("%i %i", &i1, &i2);

	if (lcm(i1,i2) == -1)
		printf("Don't enter negative integers!\n");
	else
		printf("The lcm is %i.\n", lcm(i1, i2));
	
	return 0;
}
