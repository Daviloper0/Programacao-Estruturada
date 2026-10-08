#include <stdio.h>

#include "../fractal.h"
#include "../desenho.h"

int testes(unsigned char img[][MAX_DIM]) {
    linha_horizontal(img, 10, 3, 5, 1);
    linha_vertical(img, 20, 10, 5, 1);
    pinta_retangulo(img, 30, 10, 7, 5, 1);

    salva_pbm("linha_horizontal.pbm", img, 1024, 1024);
    
    return 0;
}