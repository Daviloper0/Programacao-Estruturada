#ifndef OCORRENCIAS_H
#define OCORRENCIAS_H

typedef struct no_ocorrencia {
    int linha;
    int quantidade;
    struct no_ocorrencia *prox;
} NoOcorrencia;

/* TODO (alunos): escolher os campos desta estrutura.
 * O campo abaixo e apenas um marcador, para o esqueleto compilar.
 * Substituam-no pelos ponteiros/campos necessarios a sua representacao.
 * As ocorrencias de linhas distintas devem ficar em ordem crescente. */

typedef struct {
    NoOcorrencia *primeira_ocorrencia;
    NoOcorrencia *ultima_ocorrencia;
} ListaOcorrencias;

/* Inicializa uma lista vazia. */
void inicializa_ocorrencias(ListaOcorrencias *lista);

/* Registra uma ocorrencia na linha indicada.
 * Durante a construcao do indice, as linhas chegam em ordem nao decrescente.
 * Repeticoes da mesma linha devem ser agrupadas no mesmo no. */
void registra_ocorrencia(ListaOcorrencias *lista, int linha);

/* BONUS: remove o no da linha e devolve sua quantidade; 0 se ausente. */
int remove_ocorrencia(ListaOcorrencias *lista, int linha);

/* Retorna o primeiro no REAL, ou NULL se a lista estiver vazia.
 * Se houver sentinela, nao deve retornar a sentinela. */
NoOcorrencia *primeira_ocorrencia(ListaOcorrencias *lista);

/* FORNECIDA: imprime as ocorrencias percorrendo primeira_ocorrencia(). */
void imprime_ocorrencias(ListaOcorrencias *lista);

/* Libera todos os nos alocados para a lista (inclusive sentinela, se houver). */
void libera_ocorrencias(ListaOcorrencias *lista);

#endif
