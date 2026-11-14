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
    if (indice.capacidade != 0 || indice.n != 0) {
        printf("[ERR] Indice nao inicializado corretamente\n");
        return -1;
    }
    printf("Indice inicializado corretamente: @%p = [Capacidade: %d, Numero de indices: %d]\n", &indice, indice.capacidade, indice.n);
    int indice_gato;
    indice_gato = busca_palavra(&indice, "gato");

    if (indice_gato != -1) {
        printf("[ERR] Por algum milagre encontrou o digito: %d, ao invés de -1", indice_gato);
        return -1;
    }
    insere_palavra(&indice, "Gato", 0);
    if (indice.capacidade != 5) {
        printf("[ERR] Capacidade nao e 5, na primeira insercao, e sim: %d", indice.capacidade);
        return -1;
    }
    if (indice.n != 1) {
        printf("[ERR] N nao e 1, e sim: %d", indice.n);
        return -1;
    }
    indice_gato = busca_palavra(&indice, "Gato");
    if (indice_gato != 0) {
        printf("[ERR] Indice do gato nao e 0, e sim %d", indice_gato);
        return -1;
    }
    
    return 0;
}