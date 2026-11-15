#include "ocorrencias.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

void inicializa_ocorrencias(ListaOcorrencias *lista) {
    /* TODO (obrigatorio): inicializar lista vazia na representacao escolhida. */
    lista -> primeira_ocorrencia = NULL;
    lista -> ultima_ocorrencia = NULL;
}
void registra_primeira_ocorrencia(NoOcorrencia *no, int linha) {
    no -> linha = linha;
    no -> quantidade = 1;
    no -> prox = NULL;
}

void registra_ocorrencia(ListaOcorrencias *lista, int linha) {
    /* TODO (obrigatorio): criar no, ou incrementar a quantidade se
     * a ultima ocorrencia registrada ja for desta linha. */
    //ideia: vê a última, se ela é na mesma linha, incrementa, se não, troca linha.
    if(lista -> ultima_ocorrencia != NULL && lista -> ultima_ocorrencia -> linha == linha) {
        lista -> ultima_ocorrencia -> quantidade += 1;
        return;
    } 
    
    NoOcorrencia *no_ocorrencia_temp = malloc_safe(sizeof(NoOcorrencia));
    registra_primeira_ocorrencia(no_ocorrencia_temp, linha);

    if (lista -> primeira_ocorrencia == NULL) {
        lista -> primeira_ocorrencia = no_ocorrencia_temp;
        lista -> ultima_ocorrencia = no_ocorrencia_temp;
    } else {
        lista -> ultima_ocorrencia -> prox = no_ocorrencia_temp;
        lista -> ultima_ocorrencia = no_ocorrencia_temp;
    }
    
}

int remove_ocorrencia(ListaOcorrencias *lista, int linha) {
    /* TODO (BONUS): remover no da linha, liberar memoria e retornar
     * a quantidade removida (ou zero, se a linha nao existir). */
    (void)lista;
    (void)linha;
    return 0;
}

NoOcorrencia *primeira_ocorrencia(ListaOcorrencias *lista) {
    return lista -> primeira_ocorrencia; //como já foi iniciado, então pode retornar null, sem comparações
}

void libera_ocorrencias(ListaOcorrencias *lista) {
    NoOcorrencia *no_atual = lista -> primeira_ocorrencia;
    while (no_atual != NULL) {
        NoOcorrencia *no_antigo = no_atual;
        no_atual = no_atual -> prox;
        free(no_antigo);
    }
    lista -> primeira_ocorrencia = NULL;
    lista -> ultima_ocorrencia = NULL;
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
