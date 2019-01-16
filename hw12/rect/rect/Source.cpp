#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
	if (argc != 3) {
		printf("Wrong cmd line format!\n");
		return 0;
	}
	
	for (int r = 0; r < atoi(argv[1]); r++) {
		for (int c = 0; c < atoi(argv[2]); c++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}