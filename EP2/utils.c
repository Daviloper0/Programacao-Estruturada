#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

void *malloc_safe(size_t tamanho) {
    void *ptr = malloc(tamanho);

    if (ptr == NULL && tamanho > 0) {
        fprintf(stderr, "Erro: falha na alocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

void *realloc_safe(void *ptr, size_t tamanho) {
    if (tamanho == 0) {
        fprintf(stderr, "Erro: tamanho de realocacao igual a zero.\n");
        exit(EXIT_FAILURE);
    }

    void *novo = realloc(ptr, tamanho);

    if (novo == NULL) {
        fprintf(stderr, "Erro: falha na realocacao de memoria.\n");
        exit(EXIT_FAILURE);
    }

    return novo;
}