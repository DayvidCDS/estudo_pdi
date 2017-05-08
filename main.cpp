#include "lib_leitor_ppm.hpp"

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
