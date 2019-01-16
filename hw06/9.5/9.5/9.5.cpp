#include <stdio.h>
#include <string.h>

int findString(const char source[], const char target[]) {
	for (int i = 0; i < strlen(source); ++i)
		for (int j = 0; j < strlen(target); ++j) {
			if (source[i+j] != target[j]) break;
			else if (j == strlen(target) - 1) return i;
		}
	return -1;
}

int main()
{
	const char source1[] = { "a chatterbox" };
	const char target1[] = { "hat" };
	int index1 = findString(source1, target1);
	
	if (index1 == -1) printf("%s is not in %s\n", target1, source1);
	else printf("\"%s\" begins at index %i of \"%s\"\n", target1, index1, source1);

	const char source2[] = { "a joker" };
	const char target2[] = { "hat" };
	int index2 = findString(source2, target2);

	if (index2 == -1) printf("\"%s\" is not in \"%s\"\n", target2, source2);
	else printf("\"%s\" begins at index %i of \"%s\"\n", target2, index2, source2);

	return 0;
}