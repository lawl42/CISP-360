#include <stdio.h>

int main() {
	FILE *inf = fopen("input", "rb");

	unsigned char buffer[2];
	for (int i = 1; fread(buffer, 1, 1, inf) == 1; i++) {
		if (!(i % 10)) {
			printf("%c\n", i, buffer[0]);
		}
	}

	return 0;
}