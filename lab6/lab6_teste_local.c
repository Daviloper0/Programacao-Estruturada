#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

/* Cria uma lista simplesmente ligada, sem cabeca, com os valores do vetor. */
No *criar_lista(int valores[], int n) {
    No *inicio = NULL;
    No *ultimo = NULL;
    for (int i = 0; i < n; i++) {
        No *novo = malloc(sizeof *novo);
        if (novo == NULL) {
            fprintf(stderr, "Erro ao alocar memoria.\n");
            exit(EXIT_FAILURE);
        }
        novo->valor = valores[i];
        novo->prox = NULL;
        if (ultimo == NULL)
            inicio = novo;
        else
            ultimo->prox = novo;
        ultimo = novo;
    }
    return inicio;
}

/* Cria uma lista simplesmente ligada com no cabeca. */
No *criar_lista_com_cabeca(int valores[], int n) {
    No *cabeca = malloc(sizeof *cabeca);
    if (cabeca == NULL) {
        fprintf(stderr, "Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    cabeca->valor = -1; /* O valor do no cabeca eh irrelevante. */
    cabeca->prox = criar_lista(valores, n);
    return cabeca;
}

/* Cria uma lista circular sem no cabeca. */
No *criar_lista_circular(int valores[], int n) {
    No *lista = criar_lista(valores, n);
    if (lista != NULL) {
        No *ultimo = lista;
        while (ultimo->prox != NULL)
            ultimo = ultimo->prox;
        ultimo->prox = lista;
    }
    return lista;
}

void imprimir_lista(No *lista) {
    for (No *p = lista; p != NULL; p = p->prox)
        printf("%d -> ", p->valor);
    puts("NULL");
}

void imprimir_lista_com_cabeca(No *cabeca) {
    printf("[C] -> ");
    imprimir_lista(cabeca->prox);
}

/* Percorre uma lista circular ate retornar ao no inicial. */
void imprimir_lista_circular(No *lista) {
    if (lista == NULL) {
        puts("NULL");
        return;
    }
    No *p = lista;
    do {
        printf("%d -> ", p->valor);
        p = p->prox;
    } while (p != lista);
    printf("(volta para %d)\n", lista->valor);
}

void liberar_lista(No *lista) {
    while (lista != NULL) {
        No *proximo = lista->prox;
        free(lista);
        lista = proximo;
    }
}

/* Libera inclusive o no cabeca, que foi alocado dinamicamente. */
void liberar_lista_com_cabeca(No *cabeca) {
    liberar_lista(cabeca);
}

/* Libera todos os nos de uma lista circular. */
void liberar_lista_circular(No *lista) {
    if (lista == NULL)
        return;
    No *p = lista->prox;
    while (p != lista) {
        No *proximo = p->prox;
        free(p);
        p = proximo;
    }
    free(lista);
}

/*
 * ===== COLE SUAS IMPLEMENTACOES AQUI =====
 *
 * As duas funcoes declaradas abaixo ainda nao foram implementadas.
 * Substitua estas declaracoes pelas implementacoes completas.
 */

No *josephus(No *lista, int k) {
    //printf("Comeco da brincadeira -> Numero de passagens: %d\n", k);
    //TODO: NÃO ESQUECER DE DAR FREE
    //Quando estiver no último elemento, vai ser quando o próximo for igual ao atual, certo? Não sabo.
    No *atual = lista;
    short int passagens_restantes = k;
    if (k == 1) {
        No *primeiro_elemento = lista;
        while (atual->prox != primeiro_elemento) {
            No *no_antigo = atual;
            atual = atual->prox;
            free(no_antigo);
        }
        atual->prox = atual;
        return atual;
    }
    while (atual -> prox != atual) { //teoricamente não precisa verificar se é nulo, nem o próximo
        if (passagens_restantes > 2) {
            //printf("%d -> ", atual->valor); 
            passagens_restantes--;
            atual = atual -> prox; //vai andando até as passagens restantes ser 1, e aí o próximo é o que deve ser retirado.

        } else {
            //printf("REMOVEU %d\n", atual->prox->valor);
            No *no_antigo = atual -> prox;
            atual->prox = atual->prox->prox;
            free(no_antigo);
            passagens_restantes = k;
            atual = atual->prox;
        }
    }
    return atual;
}
void particionar(No *cabeca, int x) {
    No *cabeca_comeco = cabeca;
    No *inicio_fim = NULL;
    No *cabeca_fim = NULL; // KKKKKK
    No *inicio_ultimo_x = NULL;
    No *cabeca_ultimo_x = NULL;
    No *atual = cabeca->prox;

    while (atual != NULL) {
        if (atual -> valor < x) {
            cabeca_comeco -> prox = atual; //muda da cabeça atual
            cabeca_comeco = atual;
        } else if (atual -> valor > x) {
            if (cabeca_fim == NULL) {
                inicio_fim = atual;
                cabeca_fim = atual;
            } else {
                cabeca_fim -> prox = atual;
                cabeca_fim = atual;
            }
        } else {
            if (cabeca_ultimo_x == NULL) {
                inicio_ultimo_x = atual;
                cabeca_ultimo_x = atual;
            } else {
                cabeca_ultimo_x -> prox = atual;
                cabeca_ultimo_x = atual;
            }
        }
        atual = atual -> prox;
    }
    if (inicio_ultimo_x != NULL) {
        cabeca_comeco -> prox = inicio_ultimo_x;
        cabeca_ultimo_x -> prox = inicio_fim; 
    } else {
        cabeca_comeco->prox = inicio_fim;
    }
    
    if (cabeca_fim != NULL) {
        cabeca_fim->prox = NULL;
    } else if (cabeca_ultimo_x != NULL) {
        cabeca_ultimo_x->prox = NULL;
    } else {
        cabeca_comeco->prox = NULL;
    }
}

/* ===== ESCREVA SEUS TESTES AQUI ===== */

int main() {
    int vetor1[7] = {1,2,3,4,5,6,7};
    No *lista1 = criar_lista_circular(vetor1, 7);
    No *resultadoLista = josephus(lista1, 3);
    printf("Resultado brincadeira\n    * Endereco: %p,    * Valor: %d\n", (void *)resultadoLista, resultadoLista->valor);

    int vetor2[4] = {10,20,30,40};
    No *lista2 = criar_lista_circular(vetor2, 4);
    No *resultadoLista2 = josephus(lista2, 1);
    printf("Resultado brincadeira\n    * Endereco: %p,    * Valor: %d\n", (void *)resultadoLista2, resultadoLista2->valor);

    int vetor3[8] = {7,2,5,3,8,1,5,6};
    No *lista3 = criar_lista_com_cabeca(vetor3, 8);
    particionar(lista3, 5);
    imprimir_lista_com_cabeca(lista3);
    
    int vetor4[7] = {7,2,5,3,8,1,5};
    No *lista4 = criar_lista_com_cabeca(vetor4, 7);
    particionar(lista4, 5);
    imprimir_lista_com_cabeca(lista4);

    int vetor5[6] = {7, 2, 5, 3, 8, 1};
    No *lista5 = criar_lista_com_cabeca(vetor5, 6);
    particionar(lista5, 5);
    imprimir_lista_com_cabeca(lista5);

    int vetor6[5] = {7, 2, 5, 3, 8};
    No *lista6 = criar_lista_com_cabeca(vetor6, 5);
    particionar(lista6, 5);
    imprimir_lista_com_cabeca(lista6);

    int vetor7[4] = {7, 2, 5, 3};
    No *lista7 = criar_lista_com_cabeca(vetor7, 4);
    particionar(lista7, 5);
    imprimir_lista_com_cabeca(lista7);

    int vetor8[3] = {7, 2, 5};
    No *lista8 = criar_lista_com_cabeca(vetor8, 3);
    particionar(lista8, 5);
    imprimir_lista_com_cabeca(lista8);

    int vetor9[2] = {7, 2};
    No *lista9 = criar_lista_com_cabeca(vetor9, 2);
    particionar(lista9, 5);
    imprimir_lista_com_cabeca(lista9);

    int vetor10[1] = {7};
    No *lista10 = criar_lista_com_cabeca(vetor10, 1);
    particionar(lista10, 5);
    imprimir_lista_com_cabeca(lista10);
}