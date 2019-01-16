// Bingo

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "time.h"
#pragma warning (disable:4996)

// global vars and Table
#define TROWS 3
#define TCOLS 3
#define BROWS 6
#define BCOLS 5
unsigned char Table[TROWS][TCOLS][BROWS][BCOLS];

// Initializes one bingo board
void initBoard(char B[6][5])
{
	int row, col;

	// first row of board "BINGO"
	B[0][0] = 'B';
	B[0][1] = 'I';
	B[0][2] = 'N';
	B[0][3] = 'G';
	B[0][4] = 'O';

	// fill with random numbers
	for (row = 1; row < BROWS; row++) {
		for (col = 0; col < BCOLS; col++) {
			B[row][col] = (rand() % 50) + 1;  // 1 to 50
		}
	}
}

// Prints one board on the console
void printBoard(char B[6][5])
{
	int Brow;
	int Bcol;

	// print letters
	for (Bcol = 0; Bcol < 5; Bcol++)
		printf("  %c", B[Bcol]);
	printf("\n");

	// print number or '.'
	for (Brow = 0; Brow < 5; Brow++) {
		for (Bcol = 0; Bcol < 5; Bcol++) {
			// print visible numbers only
			if (B[Brow][Bcol] != 250)
				printf("%3d", B[Brow][Bcol]);
			else
				printf("  %c", 250);
		}
		printf("\n");
	}
}

//Prints an NxN Table of Bingo boards to the console
void printTable()
{
	int Brow;
	int Bcol;
	int Trow;
	int Tcol;

	// for each table row
	for (Trow = 0; Trow < TROWS; Trow++) {
		// print letters for each board on this Trow
		for (Tcol = 0; Tcol < TCOLS; Tcol++) {
			// print letters for one board
			for (Bcol = 0; Bcol < BCOLS; Bcol++)
				printf("  %c", Table[Trow][Tcol][0][Bcol]);
			printf("   ");
		}
		printf("\n");

		// print numbers for each board on this Trow
		for (Brow = 1; Brow < BROWS; Brow++)
		{
			for (Tcol = 0; Tcol < TCOLS; Tcol++)
			{
				for (Bcol = 0; Bcol < BCOLS; Bcol++)
				{
					// print only the visible numbers
					if (Table[Trow][Tcol][Brow][Bcol] != 250)
						printf("%3d", Table[Trow][Tcol][Brow][Bcol]);
					else
						printf("  %c", 250);
				}
				printf("   ");
			}
			printf("\n");
		}
		printf("\n");
	}
}

/*
Receives a bingo move and checks for these values on all the boards.
Then checks for bingo

Returns the number of times this value appears on the boards,
plus a bitflag to indicate bingo
*/
int play(char ch, int num)
{
	int Brow, Bcol, Trow, Tcol;
	int found = 0, bingo = 0;

	// search every single number
	for (Trow = 0; Trow < TROWS; Trow++) {
		for (Tcol = 0; Tcol < TCOLS; Tcol++) {
			for (Brow = 1; Brow < BROWS; Brow++) {
				for (Bcol = 0; Bcol < BCOLS; Bcol++) {
					// look for a number match in this ch column
					if (Table[Trow][Tcol][Brow][Bcol] == num && Table[Trow][Tcol][0][Bcol] == ch) {
						Table[Trow][Tcol][Brow][Bcol] = 250;
						found++;

						// check for BINGO
						if (!bingo)   // neglect prior bingos
						{
							bingo = 64;  // assume bingo!

							// for each Brow
							for (int row = 1; row < BROWS; row++) {
								if (Table[Trow][Tcol][row][Bcol] != 250) {
									bingo = 0;
								}
							}

							// for each Bcol
							for (int col = 0; col < BCOLS; col++) {
								if (Table[Trow][Tcol][Brow][col] != 250) {
									break;
								}
								else if (col == BCOLS - 1) {
									bingo = 64;
								}
							}
						}
					}
				}
			}
		}
	}

	return found + bingo;

}

int main()
{
	time_t t;
	int Trow, Tcol;
	char ch;
	int num, found;

	// seed generator
	srand((unsigned)time(&t));

	// initialize the global table of boards
	for (Trow = 0; Trow < TROWS; Trow++) {
		for (Tcol = 0; Tcol < TCOLS; Tcol++) {
			initBoard((char(*)[5]) Table[Trow][Tcol]);
		}
	}
	printTable();
	
	// MAIN LOOP
	do {
		// prompt user for next move
		printf("DRAW! Example N5 (Q to quit): ");

		// get move from user
		ch = getche();
		if (ch == 'Q') break;  // terminate main loop
		scanf("%d", &num);

		// play this user move
		found = play(ch, num);

		printTable();

		// check for Bingo
		if (found >= 64)
		{
			printf("BINGO!!!!  ");
			found -= 64;  // take out the bitflag
		}

		// print results
		if (found)
			printf("%d occurance of %c%d found. ", found, ch, num);
		else
			printf("%c%d not found. ", ch, num);

	} while (1);

	printf("\n");
	
	return 0;
}