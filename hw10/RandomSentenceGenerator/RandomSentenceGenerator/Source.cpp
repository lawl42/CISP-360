#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	char* article[] = {
		"the",
		"a",
		"one",
		"some",
		"any"
	};
	char* noun[] = {
		"boy",
		"girl",
		"dog",
		"town",
		"car"
	};
	char* verb[] = {
		"drove",
		"jumped",
		"ran",
		"walked",
		"skipped"
	};
	char* preposition[] = {
		"to",
		"from",
		"over",
		"under",
		"on"
	};

	char sent[80] = "";
	for (int i = 0; i < 20; i++) {
		strcat(sent, article[rand() % 5]);
		strcat(sent, " ");
		strcat(sent, noun[rand() % 5]);
		strcat(sent, " ");
		strcat(sent, verb[rand() % 5]);
		strcat(sent, " ");
		strcat(sent, preposition[rand() % 5]);
		strcat(sent, " ");
		strcat(sent, article[rand() % 5]);
		strcat(sent, " ");
		strcat(sent, noun[rand() % 5]);
		strcat(sent, ".");
		sent[0] = toupper(sent[0]);
		printf("%s\n", sent);
		strcpy(sent, "");
	}

	return 0;
}