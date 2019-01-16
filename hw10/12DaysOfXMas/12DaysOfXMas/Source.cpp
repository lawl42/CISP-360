#include <stdio.h>

int main() {
	printf("How many days do you want? ");
	int days;
	scanf("%d", &days);

	for (int verse = 1; verse <= days; verse++) {
		printf("On the %d of Christmas\n", verse);
		printf("My true love game to me\n");
		for (int line = verse; line >= 1; line--) {
			switch (line) {
			case 1:
				printf("A partridge in a pear tree\n\n");
				break;
			case 2:
				printf("Two turtle doves, and\n");
				break;
			case 3:
				printf("Three French hens,\n");
				break;
			case 4:
				printf("Four calling birds,\n");
				break;
			case 5:
				printf("Five golden rings,\n");
				break;
			case 6:
				printf("Six geese-a-laying,\n");
				break;
			case 7:
				printf("Seven swans-a-swimming,\n");
				break;
			case 8:
				printf("Eight maids-a-milking,\n");
				break;
			case 9:
				printf("Nine ladies dancing,\n");
				break;
			case 10:
				printf("Ten Lords-a-leaping,\n");
				break;
			case 11:
				printf("Eleven Pipers Piping,\n");
				break;
			case 12:
				printf("Twelve drummers drumming,\n");
				break;
			}
		}
	}

	return 0;
}