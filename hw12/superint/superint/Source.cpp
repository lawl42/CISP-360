#include <stdio.h>
#include <conio.h>
#include <string.h>

// a 256 bit (32 byte) integer
struct superint {
	char byte[32];
};
const int SI_SIZE_BYTES = sizeof(superint);
const int SI_SIZE_BITS = sizeof(superint) * 8;

/*
Sets the bit at position 'index' to the value 'v'.
Calculates the bit and byte position,
generates bitmasks, and sets the bit using the mask.
*/
void setbit(struct superint * si, int index, int v) {
	int bytenum = index / 8; 
	int bitnum = index % 8; 
	unsigned char mask = 128; 

	for (int i = 0; i < bitnum; i++)
		mask = mask >> 1;

	if (v) {
		si->byte[bytenum] = si->byte[bytenum] | mask;
	}
	else {
		mask = ~mask;
		si->byte[bytenum] = si->byte[bytenum] & mask;
	}
}

/*
Gets the bit value at position 'index'.
Calculates the bit and byte position,
generates a bitmask, gets the bit using the mask,
returns the character '1' or '0'
*/
char getbit(struct superint si, int index) {
	int bytenum = index / 8;
	int bitnum = index % 8;
	unsigned char mask = 128;
	int i, b;

	for (i = 0; i < bitnum; i++)
		mask = mask >> 1;

	b = si.byte[bytenum] & mask;

	if (b)
		return 1;
	else
		return 0;
}


/*
Sets a superint to zero
*/
void setzero(struct superint *si) {
	for (int B = 0; B < SI_SIZE_BYTES; B++)
		si->byte[B] = 0;
}

/*
Returns -1 (true) if the superint is 0
otherwise returns 0 (false)
*/
int iszero(struct superint si) {
	int b;

	// assume superint is zero
	// try to prove otherwise
	for (b = SI_SIZE_BITS - 1; b >= 0; b--) {
		if (getbit(si, b))
			return 0;
	}

	// if we got here, superint must be zero
	return -1;
}


/*
Returns -1 (true) if the string is 0
otherwise returns 0 (false)

0 means filled with all '0'
*/
bool iszeroStr(char s[]) {
	// assume string is zero
	// try to prove otherwise
	for (int i = 0; s[i]; i++) {
		if (s[i] != '0') {
			return false;
		}
	}

	// if we got here, superint must be zero
	return true;
}


/*
returns 1 (true) if odd
returns 0 (false) if even
*/
int isOdd(char s[]) {
	return (s[(strlen(s) - 1)] - '0') % 2;
}


/*
Receives a superint pointer and a string representation of a
decimal number.
Converts the string to binary and fills a superint with the bits.

Returns 1 if the binary bits overflow,
otherwise returns 0
*/
int dec_to_si(struct superint * si, char s[]) {
	char buf[80];
	int b = 0, nxtadd, add;

	// make a copy
	strcpy(buf, s);

	while (!iszeroStr(buf)) {
		// check for binary overflow
		if (b == SI_SIZE_BITS) {
			return -1;
		}

		if (isOdd(buf))
			setbit(si, b, 1);
		else
			setbit(si, b, 0);

		// Begin divide by 2 algorithm
		nxtadd = 0;
		for (int c = 0; buf[c]; c++) {
			add = nxtadd;
			if ((buf[c] - '0') % 2)
				nxtadd = 5;
			else
				nxtadd = 0;
			buf[c] = ((buf[c] - '0') / 2) + add + '0';
		}
		// end divide by two algorithm

		b++;
	}

	return 0;
}


/*
Receives a string buffer and a superint.
Converts the superint to a decimal string and fills the
buffer with the digits.
*/
void si_to_dec(struct superint X, char s[]) {
	int b, R = 0;
	struct superint Y = { 0, 0, 0, 0 };
	int c1 = 0, c2 = 0;
	char buf[80];

	while (!iszero(X)) {
		// begin division by ten algorithm
		R = 0;
		setzero(&Y);
		for (b = SI_SIZE_BITS - 1; b >= 0; b--) { // msb to lsb
			R = 2 * R + getbit(X, b);  // build remainder
			if (R >= 10) {
				setbit(&Y, b, 1);   // Y += "1"
				R -= 10;
			}
			else
				setbit(&Y, b, 0);   // Y += "0"
		}
		// end division by ten algorithm

		// output remainder to next buffer position
		buf[c1] = R + '0';
		c1++;

		// copy Y to X for next division
		X = Y;
	}

	// reverse the decimal string
	c1--;
	while (c1 >= 0)
		s[c2++] = buf[c1--];
	s[c2] = 0;  // null terminator

	// check for null string and insert one '0'
	if (!s[0]) {
		s[0] = '0'; s[1] = 0;
	}
}


/*
Receives a superint and prints it to the console.
Uses the value of format to determine output format.
"%b" binary format
"%d" decimal format
*/
void si_printf(char format[], struct superint si) {
	char buf[80];
	int i;

	if (!strcmp(format, "%b"))
		for (i = SI_SIZE_BITS - 1; i >= 0; i--) {
			putch(getbit(si, i) + '0');
		}

	if (!strcmp(format, "%d")) {
		si_to_dec(si, buf);
		printf(buf);
	}

}


/*
Takes 2 superints and adds them

returns -1 if overflow occurs,
returns 0 otherwise

uses the hugeint addition algorithm
and setbit helper function
*/
int add_si(struct superint si1, struct superint si2) {
	struct superint sum;
	setzero(&sum);
	char buf[SI_SIZE_BITS + 1];

	for (int i = 0; i < SI_SIZE_BITS; i++) {
		if (getbit(si1, i) == 1 && getbit(si2, i) == 1) {
			setbit(&sum, i, 0);
			buf[i + 1] = '1';
		}
		else if (getbit(si1, i) == 0 && getbit(si2, i) == 0){
			setbit(&sum, i, 0);
			buf[i + 1] = '0';
		}
		else{
			setbit(&sum, i, 1);
			buf[i + 1] = '0';
		}

		if (buf[i] == '1') {
			if (getbit(sum, i) == 0) {
				setbit(&sum, i, 1);
			}
			else if (getbit(sum, i) == 1) {
				setbit(&sum, i, 0);
				buf[i + 1] = '1';
			}
		}

		if (i + 1 == SI_SIZE_BITS && buf[i + 1] == '1') return -1;
	}

	si_to_dec(sum, buf);
	printf("%s\n", buf);

	return 0;
}

int main() {
	// number with 256 bits can only be up to 78 digits in decimal
	char buf[80], input[79]; 
	struct superint si;

	// get a number
	printf("Number (Input): ");
	scanf("%s", input);

	strcpy(buf, input);
	setzero(&si);
	if (dec_to_si(&si, buf) == -1) {
		printf("Number too large!\n");
		return 1;
	}
	si_printf("%b", si);
	printf("\n");
	si_printf("%d", si);
	printf("\n\n");

	struct superint si1, si2;
	setzero(&si1);
	setzero(&si2);
	dec_to_si(&si1, "57896044618658097711785492504343953926634992332820282019728792003956564819967");
	dec_to_si(&si2, "57896044618658097711785492504343953926634992332820282019728792003956564819967");
	si_printf("%d", si1);
	printf("\n+\n");
	si_printf("%d", si2);
	printf("\n=\n");

	int sum;
	sum = add_si(si1, si2);
	if (sum == -1) {
		printf("Overflow\n");
	}

	return 0;
}