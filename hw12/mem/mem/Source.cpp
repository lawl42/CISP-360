#include <stdio.h>
#include <new>

int main() {
	char *thing, buf[80];
	int count = 0;

	printf("Adress		Count\n");
	int address1, address2;
	while (true) {
		thing = new (std::nothrow) char[0x100000];
		if (thing == 0) break;
		printf("%.8x	%d\n", thing, count++);
	}
	printf("Total bytes allocated: %d\n", count * 1048576);
	
	return 0;
}