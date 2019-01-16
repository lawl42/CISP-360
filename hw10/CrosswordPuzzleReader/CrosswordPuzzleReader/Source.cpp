#include <stdio.h>

int main() {
	char crossword[20][20] = {
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 
		' ', ' ', ' ', ' ', ' ', 'G', ' ', 'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', 'P', 'R', 'O', 'V', 'O', 'L', 'O', 'N', 'E', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', 'U', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ',
		' ', 'S', ' ', ' ', ' ', 'D', ' ', 'A', ' ', ' ', ' ', ' ', 'B', ' ', ' ', 'F', ' ', 'M', ' ', ' ',
		' ', 'W', ' ', ' ', ' ', 'A', ' ', 'N', ' ', ' ', ' ', 'G', 'R', 'U', 'Y', 'E', 'R', 'E', ' ', ' ',
		' ', 'I', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', ' ', ' ', 'I', ' ', ' ', 'T', ' ', 'M', ' ', ' ',
		' ', 'S', ' ', 'M', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', 'A', ' ', 'B', ' ', ' ',
		' ', 'S', ' ', 'U', ' ', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ',
		' ', ' ', ' ', 'E', ' ', ' ', 'M', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', 'R', ' ', 'R', ' ', ' ',
		' ', ' ', ' ', 'N', ' ', ' ', 'O', ' ', ' ', ' ', 'M', ' ', 'R', 'I', 'C', 'O', 'T', 'T', 'A', ' ',
		' ', ' ', ' ', 'S', ' ', ' ', 'Z', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', 'T', ' ', ' ', 'Z', ' ', ' ', ' ', 'M', ' ', ' ', ' ', ' ', 'U', ' ', ' ', ' ', ' ',
		' ', 'C', 'H', 'E', 'D', 'D', 'A', 'R', ' ', ' ', 'B', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', 'R', ' ', ' ', 'R', ' ', ' ', ' ', 'E', ' ', 'G', ' ', ' ', 'F', ' ', 'J', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', 'E', ' ', 'G', 'O', 'R', 'G', 'O', 'N', 'Z', 'O', 'L', 'A', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', 'L', ' ', ' ', ' ', 'T', ' ', 'U', ' ', ' ', 'R', ' ', 'C', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', 'L', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', 'T', ' ', 'K', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', 'P', 'A', 'R', 'M', 'I', 'G', 'I', 'A', 'N', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	};

	// Print the crossword
	for (int r = 0; r < 20; r++) {
		for (int c = 0; c < 20; c++) {
			printf("%c", crossword[r][c]);
		}
		printf("\n");
	}

	char words[18][11];
	int words_index = 0;

	// Algorithm to find words
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 20; column++) {
			
			// Check if letter present
			if (crossword[row][column] != ' ') {
				
				// Determine if start of vertical word
				if (crossword[row - 1][column] == ' ' && crossword[row][column - 1] == ' ' && crossword[row][column + 1] == ' ') {
					int r;
					for (r = 0; crossword[row + r][column] != ' '; r++) {
						words[words_index][r] = crossword[row + r][column];
					}
					words[words_index][r] = '\0';
					words_index++;
				}

				// Determine if start of horizontal word
				if (crossword[row - 1][column] == ' ' && crossword[row][column - 1] == ' ' && crossword[row + 1][column] == ' ') {
					int c;
					for (c = 0; crossword[row][column + c] != ' '; c++) {
						words[words_index][c] = crossword[row][column + c];
					}
					words[words_index][c] = '\0';
					words_index++;
				}
			}
		}
	}

	// Print the words
	for (int i = 0; i < 18; i++) {
		for (int j = 0; words[i][j] != '\0'; j++) {
			printf("%c", words[i][j]);
		}
		printf("\n");
	}
	return 0;
}