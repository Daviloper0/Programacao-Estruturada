#include "../indice.h"
#include "../ocorrencias.h"
#include "../utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Indice indice = {0};
    printf("Indice no main: %p\n", &indice);
    inicializa_indice(&indice);
    printf("Indice depois no main: %p\n", &indice);
    //printf("Índice inicializado:\n * Capacidade: %d\n * Número de índices: %d", indice -> capacidade, indice -> n);
    
    return 0;
}