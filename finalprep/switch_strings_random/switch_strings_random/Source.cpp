#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	time_t t;
	srand((unsigned)time(&t));

	int x, y, sum;
	while (true) {
		x = (rand() % 6) + 1;
		y = (rand() % 6) + 1;
		sum = x + y;
		
		printf("%d %d\nsum: %d\n", x, y, sum);
		
		if (sum == 2) {
			printf("Snake eyes!\n");
		}
		else if (sum == 12) {
			printf("Craps!\n");
		}
		
		if (x == y) {
			printf("Pairs, roll again.\n");
			continue;
		}

		break;
	}

	return 0;
}