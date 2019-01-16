// Program to find a pattern of bits in a int

#include <stdio.h>

// number of bits in number
int bit_length(unsigned int val)
{
	// right shift until zero
	int length = 0;
	while (val != 0) {
		val >>= 1;
		length++;
	}

	// add length for leading zeroes
	if (length % 4 == 3)
		return length + 1;
	else if (length % 4 == 2)
		return length + 2;
	else if (length % 4 == 1)
		return length + 3;
	else
		return length;
}

// check if the bit is on or off
int bit_test(unsigned int val, int n)
{
	unsigned int copy = val;
	int length = bit_length(val);

	val >>= (length - n - 1);
	(copy >>= (length - n - 1))++;

	if ((val ^= copy) > 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int bitpat_search(unsigned int source, unsigned int pattern, int n)
{
	// loop through the source
	for (int i = 0; i < bit_length(source) - 2; ++i) {
		
		// loop through the pattern, while comparing it to source
		for (int j = bit_length(pattern)-1, k = i+2; j >= bit_length(pattern) - n; --j, --k) {
			
			// if source matches pattern, don't break
			if ((bit_test(source, k) && bit_test(pattern, j)) || (!(bit_test(source, k)) && !(bit_test(pattern, j)))) {
				if (j == bit_length(pattern)-n)
					return i;
			}
			else
				break;
		}
	}

	return -1;
}

int main(void)
{
	unsigned int source = 0x1e5bu;
	unsigned int pattern = 0xa1;
	int n = 5;
	int index = bitpat_search(source, pattern, n);
	
	if (index == -1)
		printf("Pattern not found.\n");
	else
		printf("The pattern begins at bit %i.\n", index);

	return 0;
}