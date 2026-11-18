#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct NoDuplo {
    int valor;
    struct NoDuplo *ant;
    struct NoDuplo *prox;
} NoDuplo;

/* Cria uma lista simplesmente ligada com os valores do vetor. */
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

/* Cria uma lista duplamente ligada com os valores do vetor. */
NoDuplo *criar_lista_dupla(int valores[], int n) {
    NoDuplo *inicio = NULL;
    NoDuplo *ultimo = NULL;
    for (int i = 0; i < n; i++) {
        NoDuplo *novo = malloc(sizeof *novo);
        if (novo == NULL) {
            fprintf(stderr, "Erro ao alocar memoria.\n");
            exit(EXIT_FAILURE);
        }
        novo->valor = valores[i];
        novo->ant = ultimo;
        novo->prox = NULL;
        if (ultimo == NULL)
            inicio = novo;
        else
            ultimo->prox = novo;
        ultimo = novo;
    }
    return inicio;
}

void imprimir_lista(const No *lista) {
    for (const No *p = lista; p != NULL; p = p->prox)
        printf("%d -> ", p->valor);
    puts("NULL");
}

/* Imprime nos dois sentidos e sinaliza problemas de encadeamento. */
void imprimir_lista_dupla(const NoDuplo *lista) {
    const NoDuplo *ultimo = NULL;
    int consistente = (lista == NULL || lista->ant == NULL);

    printf("Ida:   ");
    for (const NoDuplo *p = lista; p != NULL; p = p->prox) {
        if (p->ant != ultimo)
            consistente = 0;
        printf("%d <-> ", p->valor);
        ultimo = p;
    }
    puts("NULL");

    printf("Volta: ");
    const NoDuplo *proximo = NULL;
    for (const NoDuplo *p = ultimo; p != NULL; p = p->ant) {
        if (p->prox != proximo)
            consistente = 0;
        printf("%d <-> ", p->valor);
        proximo = p;
    }
    puts("NULL");
    printf("Ponteiros consistentes: %s\n", consistente ? "SIM" : "NAO");
}

void liberar_lista(No *lista) {
    while (lista != NULL) {
        No *proximo = lista->prox;
        free(lista);
        lista = proximo;
    }
}

void liberar_lista_dupla(NoDuplo *lista) {
    while (lista != NULL) {
        NoDuplo *proximo = lista->prox;
        free(lista);
        lista = proximo;
    }
}

/*
 * ===== COLE SUAS IMPLEMENTACOES AQUI =====
 *
 * As tres funcoes declaradas abaixo ainda nao foram implementadas.
 * Substitua estas declaracoes pelas implementacoes completas.
 */

No *rotacionar(No *lista, int k) {
    if (lista == NULL) return NULL;
    short int k_real = k; 
    No *atual = lista;
    No *novo_inicio = lista;
    short int numero_elementos = 0;

    while (atual != NULL && atual -> prox != NULL) {
        numero_elementos++;

        atual = atual -> prox;
    } //além dessa função contar, para pegarmos o k real, ela também deixa no último elemento, facilitando a rotação
    
    k_real = k % numero_elementos;
    printf("k_real %d, nelementos: %d\n", k_real, numero_elementos);
    atual = lista;

    for (int i = k_real; i > 0; i--) {
        
        while (atual != NULL) {
            if (atual -> prox -> prox != NULL) {
                atual = atual -> prox;
            } else {
                atual -> prox -> prox = novo_inicio; //o que vem depois do novo primeiro é o antigo primeiro
                novo_inicio = atual -> prox;
                atual -> prox = NULL; //o último elemento tem que apontar para nulo
                //tenho que trocar o atual para o primeiro
                atual = novo_inicio;
                break;
            }
        }
    }
    return novo_inicio;
}

No *intercalar(No *a, No *b) {
    return NULL;
}
NoDuplo *reorganizar(NoDuplo *lista) {
    return NULL;
}

/* ===== TESTES (voce pode acrescentar outros) ===== */

void testar_rotacao() {
    int valores[] = {0, 1, 2, 3, 4};
    No *lista = criar_lista(valores, 5);

    puts("Exercicio 1 - Rotacao por 2:");
    lista = rotacionar(lista, 2);
    imprimir_lista(lista); /* Esperado: 3 -> 4 -> 0 -> 1 -> 2 -> NULL */
    liberar_lista(lista);

    puts("Rotacao de lista vazia:");
    lista = rotacionar(NULL, 3);
    imprimir_lista(lista); /* Esperado: NULL */
    liberar_lista(lista);
}

void testar_intercalacao() {
    int va[] = {1, 3, 5, 7};
    int vb[] = {2, 4, 6};
    No *a = criar_lista(va, 4);
    No *b = criar_lista(vb, 3);

    puts("Exercicio 2 - Intercalar:");
    No *resultado = intercalar(a, b);
    imprimir_lista(resultado); /* Esperado: 1 -> 2 -> ... -> 7 -> NULL */
    liberar_lista(resultado);

    puts("Intercalar com uma lista vazia:");
    a = NULL;
    b = criar_lista(vb, 3);
    resultado = intercalar(a, b);
    imprimir_lista(resultado); /* Esperado: 2 -> 4 -> 6 -> NULL */
    liberar_lista(resultado);
}

void testar_reorganizacao() {
    int pares[] = {1, 2, 3, 4, 5, 6};
    int impares[] = {1, 2, 3, 4, 5};

    puts("Exercicio 3 - Lista com seis nos:");
    NoDuplo *lista = criar_lista_dupla(pares, 6);
    lista = reorganizar(lista);
    imprimir_lista_dupla(lista); /* Esperado na ida: 1, 6, 2, 5, 3, 4 */
    liberar_lista_dupla(lista);

    puts("Lista com cinco nos:");
    lista = criar_lista_dupla(impares, 5);
    lista = reorganizar(lista);
    imprimir_lista_dupla(lista); /* Esperado na ida: 1, 5, 2, 4, 3 */
    liberar_lista_dupla(lista);
}

int main() {
    int vetor1[5] = {1,2,3,4,5};
    No *lista1 = criar_lista(vetor1, 5);
    No *novo_inicio;
    imprimir_lista(lista1);
    //NÃO É A MESMA LISTA, POR ISSO
    novo_inicio = rotacionar(lista1, 1);
    imprimir_lista(novo_inicio);
    
    novo_inicio = rotacionar(novo_inicio, 2);
    imprimir_lista(novo_inicio);

    novo_inicio = rotacionar(novo_inicio, 3);
    imprimir_lista(novo_inicio);

    novo_inicio = rotacionar(novo_inicio, 4);
    imprimir_lista(novo_inicio);
    return 0;
}