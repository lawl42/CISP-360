#include <stdio.h>
#include <conio.h>

// header struct
struct s_header {
	unsigned char verCode;
	unsigned char serviceType;
	unsigned short totLength;
	unsigned char reserved;
	unsigned char flags;
	unsigned short hopCount;
	unsigned char srcAddr[4];
	unsigned long destAddr[4];
};

// string tables
char * codes[] = {
	"OK",
	"Possible data corruption",
	"Reserved"
};

char * services[] = {
	"Normal",
	"Low Priority",
	"High Priority",
	"Medium Priority",
	"So	- so Priority",
	"Needed Yesterday",
	"Nevermind",
	"Reserved"
};

char * flags[] = {
	" Grumpy: ",
	" Sneezy: ",
	" Bashful: ",
	" Doc: ",
	" Dopey: ",
	" Tipsy: ",
	" Surly: ",
	" SnowWhite: "
};

void display_header(struct s_header header) {
	// version + code
	printf("Version: \t\t%d\n", header.verCode >> 4);
	printf("Code: \t\t\t%d - %s\n", header.verCode & 0x0F, (int)(header.verCode & 0x0F) < 2 ? codes[(int)header.verCode & 0x0F] : codes[2]);

	// service type
	printf("Service Type: \t\t%d - %s\n", header.serviceType, (int)(header.serviceType) < 7 ? services[(int)header.serviceType] : services[7]);

	// total length
	printf("Total Length: \t\t%d\n", header.totLength);

	// flags
	for (int i = 0; i < 8; i++) {
		printf("%s   \t\t%d\n", flags[i], (header.flags >> (i)) & 1);
	}

	// hop count
	printf("Hop Count: \t\t%d\n", header.hopCount);

	// source address
	printf("Source Address: \t%d.%d.%d.%d\n", header.srcAddr[0], header.srcAddr[1], header.srcAddr[2], header.srcAddr[3]);

	// destination address
	printf("Destination Adress: \t%lu.%lu.%lu.%lu\n", header.destAddr[0], header.destAddr[1], header.destAddr[2], header.destAddr[3]);
}

// print everything
void print_data(struct s_header *header, FILE *inf) {
	char readbuffer[16];
	// read header
	fread(readbuffer, 1, 16, inf);

	// version + code
	header->verCode = readbuffer[0];

	// service type
	header->serviceType = readbuffer[1];

	// total length
	int totalLength[4];
	totalLength[1] = (readbuffer[2] >> 4) & 0x0F;
	totalLength[0] = readbuffer[2] & 0x0F;
	totalLength[3] = (readbuffer[3] >> 4) & 0x0F;
	totalLength[2] = readbuffer[3] & 0x0F;
	header->totLength = 0;
	for (int i = 0; i < 4; i++) {
		header->totLength << 4;
		for (int j = 0; j < i; j++)
			totalLength[i] *= 16;
		header->totLength += totalLength[i];
	}

	// reserved
	header->reserved = readbuffer[4];

	// flags
	header->flags = readbuffer[5];

	// hop count
	int totalHops[4];
	totalHops[1] = readbuffer[6] >> 4;
	totalHops[0] = readbuffer[6] & 0x0F;
	totalHops[3] = readbuffer[7] >> 4;
	totalHops[2] = readbuffer[7] & 0x0F;
	header->hopCount = 0;
	for (int i = 0; i < 4; i++) {
		header->hopCount << 4;
		for (int j = 0; j < i; j++)
			totalHops[i] *= 16;
		header->hopCount += totalHops[i];
	}

	// source address
	header->srcAddr[0] = readbuffer[8];
	header->srcAddr[1] = readbuffer[9];
	header->srcAddr[2] = readbuffer[10];
	header->srcAddr[3] = readbuffer[11];

	// destination address
	header->destAddr[0] = readbuffer[12] & 0xFF;
	header->destAddr[1] = readbuffer[13] & 0xFF;
	header->destAddr[2] = readbuffer[14] & 0xFF;
	header->destAddr[3] = readbuffer[15] & 0xFF;

	// header
	display_header(*header);

	// read and display data portion of packet
	int idataSize = header->totLength - 16; // calculate data size
	char *dbuf = new char[idataSize + 1]; // get a buffer
	fread(dbuf, 1, idataSize, inf); // read data into buffer
	dbuf[idataSize] = 0; // add a null terminator
	printf("Data: \n%s\n", dbuf);
}

int main(int argc, char ** argv) {
	if (argc != 2) {
		printf("wrong cmd line format\n");
	}

	FILE *inf = fopen(argv[1], "rb");
	struct s_header header;

	do {
		printf("\n");
		print_data(&header, inf);
		printf("Another? (Y/N) ");
	} while (getch() != 'N');

	fclose(inf);
	return 0;
}