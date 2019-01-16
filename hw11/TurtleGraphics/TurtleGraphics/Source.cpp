// Turtle Graphics

#include <stdio.h>
#include <ctype.h>
#include <conio.h>

const int rows = 30, cols = 30;
char board[rows][cols];
int position_r = 15, position_c = 15; // start

// print the board
void print_board() {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			printf("%c", board[r][c]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
}

// put a turtle at a certain location
void star(int row, int col) {
	if (row == rows) position_r = 0;
	if (row == -1) position_r = rows - 1;
	if (col == cols) position_c = 0;
	if (col == -1) position_c = cols - 1;
	board[position_r][position_c] = '*';
}

int main() {
	// make the board all spaces
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			board[r][c] = ' ';
		}
	}
	print_board();

	char ch;
	do {
		ch = getch();
		switch (ch) {
			case '8':
				star(--position_r, position_c);
				break;
			case '4':
				star(position_r, --position_c);
				break; 
			case '2':
				star(++position_r, position_c);
				break; 
			case '6':
				star(position_r, ++position_c);
				break;
			default:
				continue;
		} 
		print_board();
	} while (ch != 27);

	return 0;
}