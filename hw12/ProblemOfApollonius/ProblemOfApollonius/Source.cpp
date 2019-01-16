#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 10) {
		printf("Wrong command line argument format!\n");
		return 0;
	}

	int data[3][3] = {0};
	int i = 1;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			data[r][c] = atoi(argv[i]);
			i++;
			printf("%d\n", data[r][c]);
		}
	}

	// (Xs - X1) ^ 2 + (Ys - Y1) ^ 2 = (Rs - S1R1) ^ 2
	// (Xs - X2) ^ 2 + (Ys - Y2) ^ 2 = (Rs - S2R2) ^ 2
	// (Xs - X3) ^ 2 + (Ys - Y3) ^ 2 = (Rs - S3R3) ^ 2
	

	return 0;
}