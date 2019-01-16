// Counts the number of times a letter occurs

#include <stdio.h>
#include <ctype.h>

void my_strupper(char *str) {
	for (int i = 0; str[i] != '\0'; i++) {
		str[i] = toupper(str[i]);
	}
}

int main()
{
	printf("Please enter a string: ");
	char input[80];
	gets(input);
	my_strupper(input);
	
	int freqs[26] = { 0 };
	for (int i = 0; input[i] != '\0'; i++) {
		freqs[input[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (freqs[i] != 0) {
			printf("%c  %d\n", i + 'A', freqs[i]);
		}
	}

	return 0;
}