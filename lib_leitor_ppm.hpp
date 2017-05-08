#ifndef READ_PPM_FORMAT_H
#define READ_PPM_FORMAT_H

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Pixel {
	int r, g, b;
};

class Imagem {
	private:

		struct Pixel **pixels;
		int width, heigth;

		void setPixels(FILE *arquivo);

	public:

		Imagem(FILE *arq);
		struct Pixel getPixel(int x, int y);
		struct Pixel **getAllPixels();
		int getWidth();
		int getHeigth();
		
};

void save_ppm(struct Pixel **, int, int, char *);

#endif