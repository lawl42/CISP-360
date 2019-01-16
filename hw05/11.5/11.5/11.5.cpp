#include <stdio.h>

// number of bits in number
int bit_length(unsigned int val)
{
	// right shift until zero
	int length = 0;
	while (val != 0) {
		val >>= 4;
		length += 4;
	}
	return length;
}

// check if the bit is on or off
int bit_test(unsigned int val, int n)
{
	int length = bit_length(val);	
	val >>= (length - n - 1);
	
	if (val % 2 == 0)
		return 0;
	else
		return 1;
}

unsigned int bit_set(unsigned int val, int n)
{
	if (bit_test(val, n)) // already turned on
		return val;
	else {				  // turned off
		int add = 01;
		for (int i = 1; i <= bit_length(val) - n - 1; i++)
			add *= 2;
		return val + add;
	}
}

int main()
{
	unsigned int num = 0x12345678u; // only hex numbers
	int bit = 8; // change for checking different bits

	/* bit 0 is the first bit of the first non-zero digit
		ie bit 0 of 0a is 1 not 0 */
	printf("%i\n", bit_test(num, bit));
	printf("%x\n", bit_set(num, bit));

	// second run: changed num, bit
	num = 0xabcdefu; // only hex numbers
	bit = 23; // change for checking different bits

	printf("%i\n", bit_test(num, bit));
	printf("%x\n", bit_set(num, bit));

	return 0;
}