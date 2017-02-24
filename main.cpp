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

		void setPixels(FILE *arquivo) {
	
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

	public:

		Imagem(FILE *arq) {
			this->setPixels(arq);
		}

		struct Pixel getPixel(int x, int y) {
			return this->pixels[y][x];
		}

		struct Pixel **getAllPixels() {
			return this->pixels;
		}

		int getWidth() {
			return this->width;
		}

		int getHeigth() {
			return this->heigth;
		}
		
};

void save_ppm(struct Pixel **, int, int, char *);

int main(int argc, char **argv) {
	char nomeArq[] = "saida.ppm";
	int x, y;
	
	if (argc < 2) {
		cout << "entre com o nome do arquivo ppm!" << endl;
		return 1;
	}
	
	FILE *arq = fopen(argv[1], "r");
	
	if (arq == NULL) {
		cout << "arquivo nao valido!" << endl;
		return 2;
	}
	
	Imagem *img = new Imagem(arq);

	save_ppm(img->getAllPixels(), img->getHeigth(), img->getWidth(), nomeArq);
	fclose(arq);
	return 0;
}



void save_ppm(struct Pixel **pixel, int heigth, int width, char *nomeArq) {
	
	FILE *arq = fopen(nomeArq, "w");
	
	fprintf(arq, "P2\n%i %i\n255\n", width, heigth);
	
	for (int y = 0; y < heigth; y++) {
		for (int x = 0; x < width; x++) {
			fprintf(arq, "%i ", (unsigned int)((pixel[heigth-y-1][x].r + pixel[heigth-y-1][x].g + pixel[heigth-y-1][x].b) / 3)); //quando somamos o rgb do pixel e dividimos por 3 temos o seu valor negativo 
		}
		fprintf(arq, "\n");
	}
	
	fclose(arq);
}
