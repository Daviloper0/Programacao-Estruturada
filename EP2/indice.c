#include "indice.h"
#include "ocorrencias.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa_indice(Indice *indice) {
    indice -> entradas = NULL;
    indice -> n = 0;
    indice -> capacidade = 0;
}

int busca_palavra(Indice *indice, char *palavra) {
    /* TODO (obrigatorio): buscar com strcmp e devolver posicao ou -1. */
    
    for (int i = 0; i < (indice -> n) && strcmp(indice -> entradas[i].palavra, palavra) != 0; i++) {
        if (strcmp(indice -> entradas[i].palavra, palavra) == 0) return i;
    }
    return -1;
}

void insere_palavra(Indice *indice, char *palavra, int linha) {
    /* TODO (obrigatorio): inserir/atualizar a palavra e sua frequencia.
     * Redimensionar o vetor de entradas quando necessario.
     * Depois, integrar com inicializa_ocorrencias/registra_ocorrencia.
     * A palavra deve ser copiada para memoria pertencente ao indice. */
    int indice_entrada = busca_palavra(indice, palavra);
    if (indice_entrada == -1) {
        //verifica se é necessário redimensionar vetor, não faço isso antes, pois só precisa redimensionar caso insira um índice novo
        //insere ao final
        if ((indice -> capacidade) == (indice -> n)) {
            if (indice -> capacidade == 0) {
                indice -> capacidade = 5;
                indice -> entradas = malloc_safe(5 * sizeof(Entrada));
            } else {
                indice -> capacidade *= 2;
                Entrada *temp = realloc_safe(indice -> entradas, indice -> capacidade * sizeof(Entrada));
                indice -> entradas = temp;
            }
        }
        Entrada entrada_palavra = indice -> entradas[indice -> n];
        entrada_palavra.palavra = palavra;
        entrada_palavra.frequencia = 1;
        
        indice -> n += 1;
    }
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
