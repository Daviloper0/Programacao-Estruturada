#include "documento.h"
#include "utils.h"

#include <stddef.h>
#include <stdlib.h>

void inicializa_documento(Documento *doc) {
    doc->linhas = NULL;
    doc->n = 0;
    doc->capacidade = 0;
}

void adiciona_linha(Documento *doc, char *linha) {
    if (doc->n == doc->capacidade) {
        doc->capacidade = (doc->capacidade == 0) ? 5 : 2 * doc->capacidade;
        doc->linhas = realloc_safe(
            doc->linhas, doc->capacidade * sizeof(char *));
    }

    doc->linhas[doc->n++] = linha;
}

char *obtem_linha(Documento *doc, int numero) {
    if (numero < 1 || numero > doc->n)
        return NULL;

    return doc->linhas[numero - 1];
}

void libera_documento(Documento *doc) {
    for (int i = 0; i < doc->n; i++)
        free(doc->linhas[i]);

    free(doc->linhas);
    inicializa_documento(doc);
}
