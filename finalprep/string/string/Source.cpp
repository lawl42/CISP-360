#include <stdio.h>
#include <string.h>

int main() {
	char str[80];
	scanf("%s", str);

	char temp;
	temp = str[0];
	str[0] = str[strlen(str) - 1];
	str[strlen(str) - 1] = temp;

	printf("%s\n", str);

	return 0;
}