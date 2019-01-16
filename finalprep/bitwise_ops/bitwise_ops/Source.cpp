#include <stdio.h>

int main() {
	int num, count = 0;
	scanf("%d", &num);

	char c = num;
	
	for (int i = 1; i < 8; i++) {
		if (c & 1 == 1) count++;
		c = c >> 1;
	}

	printf("%d\n", count);
	return 0;
}