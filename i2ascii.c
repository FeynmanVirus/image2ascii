#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include <string.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

void ascii(int height, int width, RGBTRIPLE image[height][width], char array[height][width]);

int main(int argc, char *argv[]) 
{
	//Checking for valid usage
	if (argc > 2 || argc < 2) {
		printf("Usage: i2ascii [INPUT FILE]");
		return 1;
	}
	char ascii[] = "`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ";
	//char ascii[] = "QWNM0gB$#DR8mHXKAUbGOpV4d9h6PkqwSE2]ayjxY5Zoen[ult13If}C{iF|(7J)vTLs?z/*cr!+<>;=^,_:'-.`";
	int len = strlen(ascii);
	
	int width, height, components;
	unsigned char *data = stbi_load(argv[1], &width, &height, &components, 0);

	if (!data) {
		printf("Error: couldn't load image %s", argv[1]);
	} 
	unsigned char *pixels = data; 
	for (int i = 0; i < height; i++) {
	 	for (int j = 0; j < width; j++) {
	 		unsigned char r = *pixels++;
	 		unsigned char g = *pixels++;
	 		unsigned char b = *pixels++;
			if (components >= 4) {
				unsigned char a = *pixels++;
			}

			//float avgColors = (0.3*r + 0.6*g + 0.1*b) / 3.0f;
			int avgColors = (r + g + b) / 3.0f;
			int index = (int)(len * (avgColors/255.0f));

			printf("%c", ascii[index]);
	 	}
		printf("\n");
	 }

	return 0;
}
	// Reading into input file
	// FILE *input;
	// input = fopen(argv[1], "rb");
	// FILE *output;
	// output = fopen(argv[2], "wb");
	
	// if (output == NULL) {
	// 	printf("Could not open output file.");
	// 	fclose(input);
	// 	fclose(output);
	// 	return 1;
	// }


	// // check input file's validity
	// if (input == NULL) {
	// 	printf("Couldn't read into input file");
	// 	fclose(input);
	// 	fclose(output);
	// 	return 1;
	// }
	// declaring ascii characters

	//loading image through stb_image library
	
	// checking valid file type
// 	BITMAPFILEHEADER fileheader;
// 	fread(&fileheader, sizeof(BITMAPFILEHEADER), 1, input);
// 	BITMAPINFOHEADER imageheader;
// 	fread(&imageheader, sizeof(BITMAPINFOHEADER), 1, input);

// 	if (fileheader.bfType != 0x4D42 || fileheader.bfOffBits != 54 || imageheader.biSize != 40 ||
//         imageheader.biBitCount != 24 || imageheader.biCompression != 0) {
// 		printf("The file is not of a valid format: BMP");
// 		fclose(input);
// 		fclose(output);
// 		return 1;
// 	} else {
// 		printf("BMP\n");
// 	}

// 	// reading header to deterine width and height 
		
// 	// height and width for the matrix
// 	int height = abs(imageheader.biHeight);
// 	int width = imageheader.biWidth;
// 	// read for RGBTRIPLE values
// 	RGBTRIPLE (*image)[width] = calloc(height, width * sizeof(RGBTRIPLE)); 
	
// 	int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

// 	for (int i = 0; i < height; i++) {	
// 		fread(image[i], sizeof(RGBTRIPLE), width, input);
		
// 		fseek(input, padding, SEEK_CUR);
// 	}


	

// 	//writing into output file
// 	//fwrite(&fileheader, sizeof(BITMAPFILEHEADER), 1, output);
// 	//fwrite(&imageheader, sizeof(BITMAPINFOHEADER), 1, output);
	
// 	// turn image pixels into ascii characters
// 	char asciiText[height][width];
// 	ascii(height, width, image, asciiText);

// 	for (int i = 0; i < height; i++) {
//  		for (int j = 0; j < width; j++) {
// 			fwrite(&asciiText[i][j], sizeof(char), 1, output);
// 		}
// 		fwrite("\n", 1, 1, output);
// 	}

// 	// free memory allocated to image
// 	free(image);
// 	//close input and output file
// 	fclose(input);
// 	fclose(output);

// 	return 0;
// }

// void ascii(int height, int width, RGBTRIPLE image[height][width], char array[height][width]) {
// 	char ascii[] = {'$', '@', 'b', '%', '8', '&', 'w', 'm', '#', '*', 'o', 'a', 'k', 'q', 'D', 'u', 'x', 'c','o', 'v', 'r', '-', '_', '+', '~', ';', ',', '"', '^', '`', '.'};
// 	float len = strlen(ascii);

// 	//char ascii[] = {' ', '.', '\'', '=', ':', '*', '|', 'o', '$', 'm'};

// 	for (int i = 0; i < height; i++) {
// 		for (int j = 0; j < width; j++) {
// 		int avgColors = (0.1 * image[i][j].rgbtBlue) + (0.6 * image[i][j].rgbtGreen) + (0.3 * image[i][j].rgbtRed) / 3.0;
// 		int index = len - (avgColors/8);
// 			printf("%c", ascii[index]);
// 			array[i][j] = ascii[index];
// 		}
// 		printf("\n");
// 	}
// 	return;

// }
