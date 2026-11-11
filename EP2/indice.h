#ifndef INDICE_H
#define INDICE_H

#include "ocorrencias.h"

typedef struct {
    char *palavra;
    int frequencia;
    ListaOcorrencias ocorrencias;
} Entrada;

typedef struct {
    Entrada *entradas;
    int n;
    int capacidade;
} Indice;

/* Inicializa um indice vazio. */
void inicializa_indice(Indice *indice);

/* Busca linear: retorna a posicao da palavra ou -1 se nao existir. */
int busca_palavra(Indice *indice, char *palavra);

/* Registra uma ocorrencia de palavra na linha indicada.
 * A funcao deve manter a frequencia total e a lista de ocorrencias. */
void insere_palavra(Indice *indice, char *palavra, int linha);

/* FORNECIDA: imprime as palavras, frequencias e listas de ocorrencias. */
void imprime_indice(Indice *indice);

/* BONUS: remove do indice todas as ocorrencias na linha indicada.
 * Palavras que ficarem sem ocorrencias devem sair do vetor de entradas. */
void remove_linha(Indice *indice, int linha);

/* Libera todas as alocacoes que pertencem ao indice. */
void libera_indice(Indice *indice);

#endif
