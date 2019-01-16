#include <stdio.h>

void substring(const char source[], int start, int count, char result[]) {
	int resultCount = 0;
	for (int i = start; i < start + count; ++i) {
		result[resultCount] = { source[i] };
		if (source[i] == '\0') {
				break;
		}
		++resultCount;
	}
	result[resultCount] = '\0';
}

int main()
{
	char source1[] = { "character" };
	char result[1000];
	substring(source1, 4, 3, result);
	printf("%s\n", result);

	char source2[] = { "two words" };
	substring(source2, 4, 20, result);
	printf("%s\n", result);

	return 0;
}