#include "lib_leitor_ppm.hpp"

void Imagem :: setPixels(FILE *arquivo) {
	
	char tipo[2];
	struct Pixel **pixel = NULL;
	
	fscanf(arquivo, "%s %d %d\n\n", &tipo, &this->width, &this->heigth);
	
	pixel = (struct Pixel **) malloc(sizeof(struct Pixel *)*(this->heigth));
	for (int i = 0; i < this->heigth; i++) {
		pixel[i] = (struct Pixel *) malloc(sizeof(struct Pixel)*(this->width));
	}
	
	for (int y = 0; y < this->heigth; y++) {
		for (int x = 0; x < this->width; x++) {
			fscanf(arquivo, "%d %d %d ", &pixel[y][x].r, &pixel[y][x].g, &pixel[y][x].b);
		}
	}
	
	this->pixels = pixel;
}

Imagem :: Imagem(FILE *arq) {
	this->setPixels(arq);
}

struct Pixel Imagem :: getPixel(int x, int y) {
	return this->pixels[y][x];
}

struct Pixel ** Imagem :: getAllPixels() {
	return this->pixels;
}

int Imagem :: getWidth() {
	return this->width;
}

int Imagem :: getHeigth() {
	return this->heigth;
}

void save_ppm(struct Pixel **pixel, int heigth, int width, char *nomeArq) {
	
	FILE *arq = fopen(nomeArq, "w");
	
	fprintf(arq, "P3\n%i %i\n255\n", width, heigth);
	
	for (int y = 0; y < heigth; y++) {
		for (int x = 0; x < width; x++) {
			fprintf(arq, "%i %i %i ", pixel[y][x].r - 10, pixel[y][x].g - 10, pixel[y][x].b - 10); //quando somamos o rgb do pixel e dividimos por 3 temos o seu valor negativo 
		}
		fprintf(arq, "\n");
	}
	
	fclose(arq);
}