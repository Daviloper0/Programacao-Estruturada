#include "indice.h"
#include "ocorrencias.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa_indice(Indice *indice) {
    printf("Indice antes de malloc: %p\n", indice);
    indice = malloc_safe(sizeof(Indice));
    printf("Indice depois malloc: %p\n", indice);
    indice -> entradas = NULL;
    indice -> n = 0;
    indice -> capacidade = 0;
}

int busca_palavra(Indice *indice, char *palavra) {
    /* TODO (obrigatorio): buscar com strcmp e devolver posicao ou -1. */

    for (int i = 0; strcmp(indice -> entradas[i].palavra, palavra) != 0 && i < (indice -> n); i++) {
        if (strcmp(indice -> entradas[i].palavra, palavra) == 0) return i;
    }
    return -1;
}

void insere_palavra(Indice *indice, char *palavra, int linha) {
    /* TODO (obrigatorio): inserir/atualizar a palavra e sua frequencia.
     * Redimensionar o vetor de entradas quando necessario.
     * Depois, integrar com inicializa_ocorrencias/registra_ocorrencia.
     * A palavra deve ser copiada para memoria pertencente ao indice. */
    (void)indice;
    (void)palavra;
    (void)linha;
    int indice_palavra = busca_palavra(indice, palavra);
    if (indice_palavra != 0) {
        indice -> entradas[indice_palavra].frequencia += 1; //faz sentido mas tem cara que vai dar problema
        //adicionar na lista de ocorrencias
        return;
    }
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
