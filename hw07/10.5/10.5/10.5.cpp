#include <stdio.h>
#include <conio.h>

#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_UP 72

struct entry
{
	int value;
	struct entry *previous;
	struct entry *next;
};

int print_entries(struct entry *listPtr)
{
	int location = 0;
	printf("\n%i\n", listPtr->value);

	while (true)
	{
		switch (location = getch()) {
			case KEY_LEFT:
				if (listPtr->previous == (struct entry *) 0)
					printf("Out of Bounds\n");
				else {
					listPtr = listPtr->previous;
					printf("%i\n", listPtr->value);
				}
				break;
			case KEY_RIGHT:
				if (listPtr->next == (struct entry *) 0)
					printf("Out of Bounds\n");
				else {
					listPtr = listPtr->next;
					printf("%i\n", listPtr->value);
				}
				break;
			case KEY_UP:
				printf("We done.\n");
				return 0;
		}
	}
}

int main()
{
	struct entry n1, n2, n3, n4, n5;
	struct entry *listStart = &n1;

	n1.value = 100;
	n2.value = 200;
	n3.value = 300;
	n4.value = 400;
	n5.value = 500;

	n1.previous = 0;
	n2.previous = &n1;
	n3.previous = &n2;
	n4.previous = &n3;
	n5.previous = &n4;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = 0;

	printf("Press the LEFT and RIGHT arrow to navigate.\n");
	printf("Press the UP arrow when finished.\n");
	print_entries(listStart);

	return 0;
}