#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *numbers[] = {
	NULL, "one", "two", "three", "four",
	"five", "six", "seven", "eight", "nine"
};

int main(int argc, char * argv[]) {
	// check for correct format
	if (argc != 4) {
		printf("Wrong cmd line format!\n");
		printf("Format: pay (fname) (lname) $xxxx.xx\n");
		return 0;
	}

	// get the name and print it
	char* fname = argv[1];
	char* lname = argv[2];
	printf("Pay to the order of: %s %s\n", fname, lname);

	int len = strlen(argv[3]);

	// amounts too large
	if (len > 8 || len < 3) {
		printf("The amount you requested is out of bounds.\n");
		printf("Bounds: $.01 to $9999.99\n");
		return 0;
	}

	// thousands
	if (len >= 8) {
		if (numbers[argv[3][len - 7] - '0']) {
			printf("%s thousand ", numbers[argv[3][len - 7] - '0']);
		}
	}
	
	// hundreds
	if (len >= 7) {
		if (numbers[argv[3][len - 6] - '0']) {
			printf("%s hundred ", numbers[argv[3][len - 6] - '0']);
		}
	}

	// tens
	if (len >= 6) {
		if (numbers[argv[3][len - 5] - '0']) {
			printf("%sty ", numbers[argv[3][len - 5] - '0']);
		}
	}

	// ones
	if (len >= 5) {
		if (numbers[argv[3][len - 4] - '0']) {
			printf("%s ", numbers[argv[3][len - 4] - '0']);
		}
		printf("and ");
	}

	// cents
	if (len >= 4) {
		printf("%s/100\n", &argv[3][len - 2]);
	}

	printf("Signed: me\n\n");
	return 0;
}