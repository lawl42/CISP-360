// Program to find a pattern of bits in an int

#include <stdio.h>

int size(unsigned int hex)
{
	int length = 0;
	do {
		hex >>= 4;
		length += 4;
	} while (hex != 0);
	return length;
}

// check if the bit is on or off
int bit_test(unsigned int val, int n)
{
	int length = size(val);
	val >>= (length - n - 1);

	if (val % 2 == 0)
		return 0;
	else
		return 1;
}

// search for the pattern
int bitpat_search(unsigned int source, unsigned int pattern, int n)
{
	int size_pattern = size(pattern);

	// loop through the source
	for (int i = 0; i < size(source) - n + 1; ++i) {

		// loop through the pattern, while comparing it to source
		for (int j = size_pattern - 1, k = i + n - 1; j >= size_pattern - n; --j, --k) {

			// if source doesn't match pattern, break
			if (bit_test(source, k) != bit_test(pattern, j))
				break;

			// if at end of pattern, it is a match
			if (j == (size_pattern - n))
				return i;
		}
	}

	return -1;
}

int main(void)
{
	// variables are all hard coded
	unsigned int source = 0xc3u; // hex
	unsigned int pattern = 0x2u; // hex
	int n = 2;					 // decimal

	int index = bitpat_search(source, pattern, n);

	if (index == -1)
		printf("Pattern not found.\n");
	else
		printf("The pattern begins at bit %i.\n", index);

	// different source, pattern, n
	source = 0xe1f4u; // hex
	pattern = 0x5u;   // hex
	n = 3;			  // decimal

	index = bitpat_search(source, pattern, n);

	if (index == -1)
		printf("Pattern not found.\n");
	else
		printf("The pattern begins at bit %i.\n", index);

	return 0;
}