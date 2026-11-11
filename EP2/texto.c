#include "texto.h"
#include "utils.h"

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

#define TAM_INICIAL_LINHA 5

/* Substitui cada caractere que não é letra ou número por espaços. */
static int limpa_linha(char *texto) {
    mbstate_t estado = {0};
    char *p = texto;
    size_t restantes = strlen(texto);

    while (restantes > 0) {
        wchar_t c;
        size_t tam = mbrtowc(&c, p, restantes, &estado);

        if (tam == (size_t)-1 || tam == (size_t)-2 || tam == 0)
            return -1;

        if (!iswalnum(c))
            memset(p, ' ', tam);

        p += tam;
        restantes -= tam;
    }

    return 1;
}

int tokeniza_linha(const char *texto, LinhaTokenizada *resultado) {

    resultado->palavras = NULL;
    resultado->n = 0;

    // Trabalhamos em uma cópia para preservar a linha original.
    char *copia = malloc_safe(strlen(texto) + 1);
    strcpy(copia, texto);

    if (limpa_linha(copia) != 1) {
        free(copia);
        return -1;
    }

    int capacidade = TAM_INICIAL_LINHA;
    resultado->palavras = malloc_safe(capacidade * sizeof(char *));

    char *palavra = strtok(copia, " ");
    while (palavra != NULL) {
        if (resultado->n == capacidade) {
            capacidade *= 2;
            resultado->palavras = realloc_safe(
                resultado->palavras, capacidade * sizeof(char *));
        }

        char *nova_palavra = malloc_safe(strlen(palavra) + 1);
        strcpy(nova_palavra, palavra);
        resultado->palavras[resultado->n++] = nova_palavra;

        palavra = strtok(NULL, " ");
    }

    free(copia);
    return 1;
}

void libera_linha_tokenizada(LinhaTokenizada *linha) {
    for (int i = 0; i < linha->n; i++)
        free(linha->palavras[i]);

    free(linha->palavras);
    linha->palavras = NULL;
    linha->n = 0;
}
