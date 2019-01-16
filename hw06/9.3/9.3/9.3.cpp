#include <stdio.h>

// Function to determine if a character is alphabetic
bool checker(const char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '\'' || (c == '+' || c == '-') || (c >= '1' && c <= '9') || (c == ',' || c == '.'))
		return true;
	else
		return false;
}

// Function to count the number of words in a string
int countWords(const char string[])
{
	int i, wordCount = 0;
	bool lookingForWord = true;

	for (int i = 0; string[i] != '\0'; ++i) {
		if (checker(string[i])) {
			if (lookingForWord) {
				++wordCount;
				lookingForWord = false;
			}
		}
		else
			lookingForWord = true;
	}

	return wordCount;
}

int main()
{
	const char text1[] = "-123,456.789";
	const char text2[] = "Billy's mom's sister's son's aunt's son is Billy";

	printf("%s - words = %i\n", text1, countWords(text1));
	printf("%s - words = %i\n", text2, countWords(text2));

	return 0;
}