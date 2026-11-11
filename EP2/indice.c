#include "indice.h"
#include "ocorrencias.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa_indice(Indice *indice) {
    /* TODO (obrigatorio): inicializar os campos de um indice vazio. */
    (void)indice;
}

int busca_palavra(Indice *indice, char *palavra) {
    /* TODO (obrigatorio): buscar com strcmp e devolver posicao ou -1. */
    (void)indice;
    (void)palavra;
    return -1; /* Stub: nenhuma palavra e encontrada por enquanto. */
}

void insere_palavra(Indice *indice, char *palavra, int linha) {
    /* TODO (obrigatorio): inserir/atualizar a palavra e sua frequencia.
     * Redimensionar o vetor de entradas quando necessario.
     * Depois, integrar com inicializa_ocorrencias/registra_ocorrencia.
     * A palavra deve ser copiada para memoria pertencente ao indice. */
    (void)indice;
    (void)palavra;
    (void)linha;
}

/* FORNECIDA: nao modificar. */
void imprime_indice(Indice *indice) {
    for (int i = 0; i < indice->n; i++) {
        Entrada *ent = &indice->entradas[i];
        printf("[%s]: %d ocorrencias \n", ent->palavra, ent->frequencia);
        printf("\t");
        imprime_ocorrencias(&ent->ocorrencias);
    }
}

void libera_indice(Indice *indice) {
    /* TODO (obrigatorio): liberar cada palavra, cada lista e o vetor. */
    (void)indice;
}

void remove_linha(Indice *indice, int linha) {
    /* TODO (BONUS): remover a linha de todas as listas; atualizar as
     * frequencias e eliminar entradas com frequencia zero.
     * Cuidado ao percorrer o vetor enquanto remove elementos dele. */
    (void)indice;
    (void)linha;
}
