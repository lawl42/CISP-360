#include <stdio.h>

// Function to read a line of text from the terminal
void readLine(char buffer[])
{
	char character;
	int i = 0;

	do {
		character = getchar();
		buffer[i] = character;
		++i;
	} while (character != '\n');

	buffer[i - 1] = '\0';
}

int main()
{
	int i;
	char line[81];
	
	for (i = 0; i < 3; i++) {
		readLine(line);
		printf("%s\n\n", line);
	}

	return 0;
}