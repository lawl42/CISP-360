// Classic Rock Paper Scissors

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
	time_t t;
	srand((unsigned)time(&t));

	// intro
	printf("Welcome to Rock Paper Scissors!\n");
	printf("Enter R, P, or S. Press ESC to quit.\n");
	printf("\nHuman    Computer Winner\n");
	printf("-------------------------\n");

	// MAIN LOOP
	while (true) {
		char user, comp, chOK = false;

		// get user's move
		do {
			user = getch();
			switch (user) {
				case 'R':
				case 'r':
				case 'P':
				case 'p':
				case 'S':
				case 's':
				case 27: // ESC
					chOK = true;
					break;
				default:
					chOK = false;
			}
		} while (!chOK);
		
		// quit the game
		if (user == 27) break;

		// make user input uppercase
		// 'any lowercase letter' - 'same uppercase letter' = ' ' (32)
		if (user > 'Z') user -= ' '; 
		
		// get computer's move
		comp = rand() % 3;
		switch (comp) {
			case 0:
				comp = 'R';
				break;
			case 1:
				comp = 'P';
				break;
			case 2:
				comp = 'S';
				break;
		}

		// check winner
		if (user == 'R' && comp == 'R')
			printf("Rock     Rock     Draw\n");
		else if (user == 'R' && comp == 'P')
			printf("Rock     Paper    Computer\n");
		else if (user == 'R' && comp == 'S')
			printf("Rock     Scissor  User\n");
		else if (user == 'P' && comp == 'R')
			printf("Paper    Rock     User\n");
		else if (user == 'P' && comp == 'P')
			printf("Paper    Paper    Draw\n");
		else if (user == 'P' && comp == 'S')
			printf("Paper    Scissor  Computer\n");
		else if (user == 'S' && comp == 'R')
			printf("Scissor  Rock     Computer\n");
		else if (user == 'S' && comp == 'P')
			printf("Scissor  Paper    User\n");
		else if (user == 'S' && comp == 'S')
			printf("Scissor  Scissor  Draw\n");
	}

	return 0;
}