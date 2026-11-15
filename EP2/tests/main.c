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
    insere_palavra(&indice, "Cachorro", 0);
    if (indice.n != 2) {
        printf("[ERR] N nao e 2, e sim: %d", indice.n);
        return -1;
    }
    insere_palavra(&indice, "Passarinho", 0);
    if (indice.n != 3) {
        printf("[ERR] N nao e 3, e sim: %d", indice.n);
        return -1;
    }
    insere_palavra(&indice, "Pato", 1);
    if (indice.n != 4) {
        printf("[ERR] N nao e 4, e sim: %d", indice.n);
        return -1;
    }
    insere_palavra(&indice, "Jamanta", 1);
    if (indice.n != 5) {
        printf("[ERR] N nao e 5, e sim: %d", indice.n);
        return -1;
    }
    insere_palavra(&indice, "Patito", 1);
    if (indice.n != 6) {
        printf("[ERR] N nao e 6, e sim: %d", indice.n);
        return -1;
    }
    insere_palavra(&indice, "Bomba relogio", 1);
    if (indice.n != 7) {
        printf("[ERR] N nao e 7, e sim: %d", indice.n);
        return -1;
    }
    if (indice.capacidade != 10) {
        printf("[ERR] Capacidade nao e 10, e sim: %d", indice.capacidade);
        return -1;
    }

    if (indice.capacidade != 10) {
        printf("[ERR] Capacidade nao e 10, e sim: %d", indice.n);
        return -1;
    }
    insere_palavra(&indice, "Gato", 1);
    insere_palavra(&indice, "Gato", 1);
    imprime_indice(&indice);
    return 0;
}