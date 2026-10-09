#include <stdio.h>

#include "../fractal.h"
#include "../desenho.h"

unsigned char imagem2[MAX_DIM][MAX_DIM] = {0};

int testes(unsigned char img[][MAX_DIM]) {
    linha_vertical(img, 20, 10, 5, 1);
    pinta_retangulo(img, 30, 10, 7, 5, 1);
    linha_vertical(img, 0, 0, 8, 1);
    linha_horizontal(img, 1, 0, 4, 1);
    linha_vertical(img, 5, 0, 8, 1);
    linha_horizontal(img, 1, 7, 4, 1);

    pinta_retangulo(img, 10, 0, 1, 8, 1);
    salva_pbm("linha_horizontal.pbm", img, 1024, 1024);
    cantor(imagem2, 5, "cantor.pbm");
    
    return 0;
}