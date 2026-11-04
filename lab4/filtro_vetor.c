#include <stdio.h>
#include <stdlib.h>

int *menores_que(const int v[], int n, int limite, int *novo_n) {
    int *vetor_filtrado_grande = malloc(n * sizeof(int));
    if (vetor_filtrado_grande == NULL) return NULL;
    *novo_n = 0;
    
    for (int i = 0; i < n; i++) {
        if (v[i] < limite) vetor_filtrado_grande[(*novo_n)++] = v[i]; //o ponto e vírgula é necessário, pois ++ tem precedência sobre o *
    }

    if (*novo_n == 0) return NULL;

    int *vetor_filtrado = realloc(vetor_filtrado_grande, (*novo_n) * sizeof(int));
    if (vetor_filtrado != NULL) return vetor_filtrado;
    return NULL;
}

int main () {
    int v[] = {8, 2, 5, 1, 7, 3, 9};
    int novo_n;

    int *r = menores_que(v, 7, 5, &novo_n);

    printf("%d:", novo_n);
    for (int i = 0; i < novo_n; i++)
        printf(" %d", r[i]);
    printf("\n");

    free(r);
}