#include "ocorrencias.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

void inicializa_ocorrencias(ListaOcorrencias *lista) {
    /* TODO (obrigatorio): inicializar lista vazia na representacao escolhida. */
    (void)lista;
}

void registra_ocorrencia(ListaOcorrencias *lista, int linha) {
    /* TODO (obrigatorio): criar no, ou incrementar a quantidade se
     * a ultima ocorrencia registrada ja for desta linha. */
    (void)lista;
    (void)linha;
}

int remove_ocorrencia(ListaOcorrencias *lista, int linha) {
    /* TODO (BONUS): remover no da linha, liberar memoria e retornar
     * a quantidade removida (ou zero, se a linha nao existir). */
    (void)lista;
    (void)linha;
    return 0;
}

NoOcorrencia *primeira_ocorrencia(ListaOcorrencias *lista) {
    /* TODO (obrigatorio): retornar o primeiro no real, ou NULL.
     * O retorno NULL permite que imprime_ocorrencias funcione
     * mesmo enquanto a lista ainda nao foi implementada. */
    (void)lista;
    return NULL;
}

void libera_ocorrencias(ListaOcorrencias *lista) {
    /* TODO (obrigatorio): liberar todos os nos alocados. */
    (void)lista;
}

/* FORNECIDA: nao modificar. */
void imprime_ocorrencias(ListaOcorrencias *lista) {
    NoOcorrencia *p = primeira_ocorrencia(lista);

    if (p != NULL) {
        printf("L:%d (x%d)", p->linha, p->quantidade);
        p = p->prox;
    }

    while (p != NULL) {
        printf(" -> L:%d (x%d)", p->linha, p->quantidade);
        p = p->prox;
    }

    printf("\n");
}
