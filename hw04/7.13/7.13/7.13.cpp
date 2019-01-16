// Remake of 7.1.12
// Sorts an array in descending or ascending order.

#include <stdio.h>
#define ARRAY_SIZE 16

void sort(int a[], int n, char order)
{
	int  i, j, temp;

	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			if (((order == '+') && (a[i] > a[j])) || ((order == '-') && (a[i] < a[j]))) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main(void)
{
	int i;
	int array[ARRAY_SIZE] = { 34, -5, 6, 0, 12, 100, 56, 22,
		44, -3, -9, 12, 17, 22, 6, 11 };

	char order;
	printf("Type '+' for ascending or '-' for descending. ");
	scanf("%c", &order);
	if (order != '+' && order != '-') {
		printf("Type '+' or '-'!\n");
		return 1;
	}

	printf("\nThe array before the sort:\n");
	for (i = 0; i < ARRAY_SIZE; ++i)
		printf("%i ", array[i]);

	sort(array, ARRAY_SIZE, order);

	printf("\n\nThe array after the sort:\n");
	for (i = 0; i < ARRAY_SIZE; ++i)
		printf("%i ", array[i]);

	printf("\n");
	return 0;
}


