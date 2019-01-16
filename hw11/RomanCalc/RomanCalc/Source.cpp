// Roman Calculator

#include <stdio.h>
#include <conio.h>

// roman to arabic
int toArabic(char *roman) {
	int num = 0;

	for (int i = 0; roman[i] != '\0'; i++) {
		switch (roman[i]) {
			case 'I':
				num += 1;
				break;
			case 'V':
				num += 5;
				break;
			case 'X':
				num += 10;
				break;
			case 'L':
				num += 50;
				break;
			case 'C':
				num += 100;
				break;
			case 'D':
				num += 500;
				break;
			case 'M':
				num += 1000;
				break;
		}
	}

	return num;
}

// do the math with a valid operation
int doTheMath(int num1, int num2) {
	printf("Enter operation (* / + -): ");
	bool opOK;
	do {
		char op = getche();
		opOK = true;
		switch (op) {
		case '*':
			return num1 * num2;
		case '/':
			return num1 / num2;
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		default:
			printf("\nInvalid operation. Select another one. ");
			opOK = false;
			break;
		}
	} while (!opOK);
}

void printRoman(int num) {
	char roman[80];
	int i;
	for (i = 0; num > 0; i++) {
		if (num >= 1000) {
			roman[i] = 'M';
			num -= 1000;
		}
		else if (num >= 500) {
			roman[i] = 'D';
			num -= 500;
		}
		else if (num >= 100) {
			roman[i] = 'C';
			num -= 100;
		}
		else if (num >= 50) {
			roman[i] = 'L';
			num -= 50;
		}
		else if (num >= 10) {
			roman[i] = 'X';
			num -= 10;
		}
		else if (num >= 5) {
			roman[i] = 'V';
			num -= 5;
		}
		else if (num >= 1) {
			roman[i] = 'I';
			num -= 1;
		}
	}
	roman[i] = '\0';

	printf("%s\n", roman);
}


int main() {
	// vars
	char roman1[80], roman2[80], quit;
	int num1, num2, ans;

	// intro
	printf("Welcome to Roman Calculator!\n\n");
	
	// MAIN LOOP
	do {
		// get roman and print arabic
		printf("Enter first number: ");
		scanf("%s", roman1);
		num1 = toArabic(roman1);
		printf("The first number is: %d\n", num1);
		printf("Enter second number: ");
		scanf("%s", roman2);
		num2 = toArabic(roman2);
		printf("The second number is: %d\n", num2);
		
		// do the math with valid operation
		ans = doTheMath(num1, num2);

		// print the answers
		printf("\nAnswer: %d\n", ans);
		if (ans < 0) {
			ans *= -1;
			printf("In Roman: -");
		}
		else {
			printf("In Roman: ");
		}
		printRoman(ans);
		
		// quit or continue
		printf("Press Q to quit, any other to continue.\n\n");
		quit = getch();

	} while (quit != 'Q');

	printf("Thanks for playing.\n");
	return 0;
}