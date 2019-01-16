#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Switch the spots of two cards
void swap(int deck[], int num1, int num2) {
	int temp = deck[num1];
	deck[num1] = deck[num2];
	deck[num2] = temp;
}

void print_card(int card) {
	// Print the value
	switch (card % 13) {
		case 0:
			printf("A");
			break;
		case 1:
			printf("2");
			break;
		case 2:
			printf("3");
			break;
		case 3:
			printf("4");
			break;
		case 4:
			printf("5");
			break;
		case 5:
			printf("6");
			break;
		case 6:
			printf("7");
			break;
		case 7:
			printf("8");
			break;
		case 8:
			printf("9");
			break;
		case 9:
			printf("10");
			break;
		case 10:
			printf("J");
			break;
		case 11:
			printf("Q");
			break;
		case 12:
			printf("K");
			break;
	}

	// Print the suit
	switch (card / 13) {
		case 0:
			printf("S ");
			break;
		case 1:
			printf("H ");
			break;
		case 2:
			printf("C ");
			break;
		case 3:
			printf("D ");
			break;
	}
}

int main() {
	int deck[52];
	for (int i = 0; i < 52; i++) {
		deck[i] = i;
	}

	// Shuffle the deck by swapping two random cards many times
	srand((unsigned)time(0));
	for (int i = 0; i < 1000; i++) {
		swap(deck, rand() % 52, rand() % 52);
	}

	// Print the deck
	printf("Deck:\n");
	for (int i = 0; i < 52; i++) {
		print_card(deck[i]);
	}

	// Print each player's cards
	printf("\n");
	int j = 0;
	for (int i = 0; i < 10; i++) {
		printf("Player %d: ", i + 1);
		for (j; j < (i + 1) * 5; j++) {
			print_card(deck[j]);
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}