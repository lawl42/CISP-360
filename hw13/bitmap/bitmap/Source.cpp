#include <stdio.h>

// the bits
struct pix {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

int main() {
	FILE *inf = fopen("in.bmp", "rb");
	FILE *outf = fopen("out.bmp", "wb");
	struct pix pixel;
	char readbuffer[120000];

	// read header from the input file
	fread(readbuffer, 54, 1, inf);

	// write header to the output file
	fwrite(readbuffer, 54, 1, outf);

	// read the pixels from the input file
	fread(readbuffer, 120000, 1, inf);

	// process each pixel
	for (int i = 0; i < 120000; i += 3) {
		pixel.blue = readbuffer[i];
		pixel.green = readbuffer[i + 1];
		pixel.red = readbuffer[i + 2];

		// blue to green
		if ((pixel.blue == 255) && (pixel.red == 0) && (pixel.green == 0)) {
			pixel.red = 255;
			pixel.green = 255;
			pixel.blue = 0;
		}
		// white to black
		else if ((pixel.blue == 255) && (pixel.red == 255) && (pixel.green = 255)) {
			pixel.red = 0;
			pixel.blue = 0;
			pixel.green = 0;
		}

		readbuffer[i] = pixel.blue;
		readbuffer[i + 1] = pixel.green;
		readbuffer[i + 2] = pixel.red;
	}

	// write all the pixels to the output file
	fwrite(readbuffer, 120000, 1, outf);

	fclose(inf);
	fclose(outf);
	return 0;
}